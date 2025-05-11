#ifndef RollingHash_HPP
#define RollingHash_HPP

#include <vector>
#include <string>
#include <random>

struct RollingHash {
private:
    using ull = unsigned long long;
    static const ull mod = 0x1fffffffffffffff; // 2^61-1
    /**
     * @param base ハッシュ計算の基底
     * @param hased 部分文字列のハッシュ値
     */
    static ull base;
    std::vector<ull> hash, power;

    /**
     * @brief a*b mod 2^61 - 1 を、オーバーフローなしで計算
     */
    inline ull mul(ull a, ull b) const {
        ull au = a >> 31; // 上位31ビット
        ull ad = a & ((1UL << 31) - 1); // 下位31ビット
        ull bu = b >> 31;
        ull bd = b & ((1UL << 31) - 1);

        // a*b = (au*2^31+ad) * (bu*2^31+bd)
        // = au*bu*2^62 + "(au*bd + ad*bu)*2^31" + ad*bd
        ull mid = au*bd + ad*bu;
        ull midu = mid >> 30; // 上位30ビット
        ull midd = mid & ((1UL << 30) - 1); // 下位30ビット

        ull ans = au*bu*2 + midu + (midd << 31) + ad*bd;

        ans = (ans >> 61) + (ans & mod);
        if(ans >= mod) ans -= mod;
        return ans;
    }

public:
    RollingHash(const std::string& s){
        int N = s.size();
        hash.assign(N + 1, 0);
        power.assign(N + 1, 0);
        power[0] = 1;
        for(int i = 0; i < N; i++){
            power[i + 1] = mul(power[i], base); // 基数の累乗を計算
            hash[i + 1] = mul(hash[i], base) + s[i];
            if(hash[i + 1] >= mod){
                hash[i + 1] -= mod;
            }
        }
    }

    /**
     * @brief 部分文字列S[l, r)のハッシュ値を計算
     */
    ull get(int l, int r) const {
        ull ret = hash[r] + mod - mul(hash[l], power[r - l]);
        if(ret >= mod){
            ret -= mod;
        }
        return ret;
    }

    /**
     * @brief frontのハッシュ値h1と、backのハッシュ値h2を連結（文字列front+backのハッシュ値）
     */
    ull connect(ull front_hash, ull back_hash, int back_len) const {
        ull ret = mul(front_hash, power[back_len]) + back_hash;
        if(ret >= mod){
            ret -= mod;
        }
        return ret;
    }

    /**
     * @brief 既存の文字列に新しい文字列を結合し、ハッシュテーブルを再構成
     */
    void rebuild(const std::string& append_str){
        int N = hash.size() - 1, M = append_str.size();
        hash.resize(N + M + 1);
        power.resize(N + M + 1);
        for(int i = N; i < N + M; i++){
            power[i + 1] = mul(power[i], base);
            hash[i + 1] = mul(hash[i], base) + append_str[i - N];
            if(hash[i + 1] >= mod){
                hash[i + 1] -= mod;
            }
        }
    }

    /**
     * @brief 二つの文字列の最長共通接頭辞LCPを計算する
     */
    int LCP(const RollingHash& another_str, int l1, int r1, int l2, int r2){
        int len = std::min(r1 - l1, r2 - l2); // 共通部分の長さ
        int low = -1, high = len + 1;
        while(high - low > 1){
            int mid = (low - high) / 2 + high;
            if(get(l1, l1 + mid) == another_str.get(l2, l2 + mid)){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};

/* // 基数をランダムに初期化
std::mt19937_64 mt{(unsigned int)time(NULL)};
RollingHash::ull RollingHash::base = mt() % RollingHash::mod; // （静的メンバ変数はの初期化は、クラスの外部で行う） */

#endif // RollingHash_HPP