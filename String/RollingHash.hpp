#ifndef RollingHash_HPP
#define RollingHash_HPP

#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cassert>

class RollingHash {
    using ull = unsigned long long;
    // static：インスタンス間でのみ共有される
    static constexpr ull MOD = 0x1fffffffffffffff; // ハッシュ値がでかくなりすぎるから、そのための mod（2^61 - 1）
    /**
     * @param base ハッシュ計算の基底
     * @param hase 部分文字列のハッシュ値  hash[i] で S[0, i) をハッシュ化したもの
     * @param S ハッシュ化する文字列
     * @param N ハッシュ化した文字列の長さ
     * @param initialized // 基底 base を各インスタンスで共有するためのフラグ
     **/
    inline static ull base = 0; // 初期化
    std::vector<ull> hash, rhash, power;
    std::string S;
    int N;
    inline static bool initialized = false; // 初期化

public:
    /**
     * @brief (a * b) MOD 2^61 - 1 を、オーバーフローなしで計算
     */
    // inline : べた張り展開（関数呼び出しのたびにその関数のメモリの位置に移動しなくてよい）
    // static（メンバ関数）: RollingHash::mul(...) のように、オブジェクトを生成しなくても利用可能。ただし、非 static メンバに触れることはできない。結局、インスタンスに紐づかない簡単な計算ルーチンである（けど、クラスの仲間として置いている）ことを明示しておくことができる。
    static inline ull mul(ull a, ull b) {
        ull aq = a >> 31; // 上位 31 ビット（a を 2^31 で割った商）
        ull ar = a & ((1UL << 31) - 1); // 下位 31 ビット（b を 2^31 で割った余り）
        ull bq = b >> 31;
        ull br = b & ((1UL << 31) - 1);
        // -> a * b = aq * bq * 2^62
                    // + (aq * br + ar * bq) * 2^31
                    // + ar * br
        
        ull mid = aq * br + ar * bq; // -> 2^30 で割った商と余りを考えてみる（2^31 * 2^30 == 2^61 だから）
        ull midq = mid >> 30; // 上位 30 ビット（mid を 2^30 で割った商）
        ull midr = mid & ((1UL << 30) - 1); // 下位 30 ビット（mid を 2^30 で割った余り）

        ull ans = aq * bq * 2 + midq + (midr << 31) + ar * br;

        // ans の MOD 2^61 - 1 を求めたい
        // ans = ansq * 2^61 + ansr とすると、ans ≡ ansq + ansr
        // ans < 2^64 より、ansq < 2^3 だから、
        // ansq + ansr < 2^3 + 2^61
        // ansq + ansr - 2^61 < 2^3
        // 割るのではなくて、2^61 を引くだけでよい（元々割る必要がないせいで引きすぎたなら、2^61 を足せばよい）。
        ans = (ans >> 61) + (ans & MOD);
        if (ans >= MOD) {
            ans -= MOD;
        }
        return ans;
    }

    RollingHash(const std::string& S) : S(S), N((int)S.size()) {
        if (!initialized) {
            std::mt19937_64 mt{ std::random_device{}() };
            std::uniform_int_distribution<long long> ran(0, std::numeric_limits<long long>::max());
            base = ran(mt) % MOD; // 基底を（ランダムに）設定。もちろん MOD 未満で取ってくる。
            initialized = true;
        }

        std::string revS = S;
        std::reverse(revS.begin(), revS.end());
        hash.assign(N + 1, 0);
        rhash.assign(N + 1, 0);
        power.assign(N + 1, 0);
        power[0] = 1;
        for (int i = 0; i < N; i++) {
            power[i + 1] = mul(power[i], base); // 基数の累乗を計算
            // hash(S[0, N+1)) = hash(S[0, N)) * base + S[N]
            // hash(S[l, r)) = hash(S[0, r)) - hash(S[0, l)) * base^{r-l}
            hash[i + 1] = mul(hash[i], base) + S[i];
            if (hash[i + 1] >= MOD) {
                hash[i + 1] -= MOD;
            }
            rhash[i + 1] = mul(rhash[i], base) + revS[i];
            if (rhash[i + 1] >= MOD) {
                rhash[i + 1] -= MOD;
            }
        }
    }

    /**
     * @brief 部分文字列 S[l, r) のハッシュ値を計算
     */
    // const : メンバを変更することを許さないようにする（もし変えようとしていたら、エラーを吐いてくれる）。つまり、読み取り専用デアルことを明示的に宣言する。参照系、更新系のどちらかが一目でわかって嬉しい。
    ull get(int l, int r) const {
        assert(l <= r);
        ull res = hash[r] + MOD - mul(hash[l], power[r - l]);
        if (res >= MOD) {
            res -= MOD;
        }
        return res;
    }

    ull get_rev(int l, int r) const {
        assert(l <= r);
        ull res = rhash[r] + MOD - mul(rhash[l], power[r - l]);
        if (res >= MOD) {
            res -= MOD;
        }
        return res;
    };

    /**
     * @brief front のハッシュ値 h1 と、back のハッシュ値 h2 を連結（文字列 front + back のハッシュ値）
     * @remark front_hash, back_hash の base が一致していないと破綻する気がする。
     */
    ull connect(ull front_hash, ull back_hash, int back_len) const {
        ull res = mul(front_hash, power[back_len]) + back_hash;
        if (res >= MOD) {
            res -= MOD;
        }
        return res;
    }

    /**
     * @brief 既存の文字列に新しい文字列を結合し、ハッシュテーブルを再構成（M 延長して、idx の N 以降を構築する）。
     */ 
    void rebuild(const std::string& T) {

        int prevN = N;
        int M = (int)T.size();
        S += T; // S の更新
        N += M; // N の更新
        hash.resize(N + 1);
        rhash.assign(N + 1, 0);
        power.resize(N + 1);

        for (int i = prevN; i < N; i++) {
            power[i + 1] = mul(power[i], base);
            hash[i + 1] = mul(hash[i], base) + T[i - prevN];
            if (hash[i + 1] >= MOD) {
                hash[i + 1] -= MOD;
            }
        }
        std::string revS = S;
        std::reverse(revS.begin(), revS.end());
        for (int i = 0; i < N; i++) {
            rhash[i + 1] = mul(rhash[i], base) + revS[i];
            if (rhash[i + 1] >= MOD) {
                rhash[i + 1] -= MOD;
            }
        }
    }

    /**
     * @brief 二つの文字列の最長共通接頭辞LCPを計算する
     */
    int LCP(const RollingHash& T, int l1, int r1, int l2, int r2) const {
        int len = std::min(r1 - l1, r2 - l2); // 共通部分の長さ
        int ok = -1, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) >> 1;
            if (get(l1, l1 + mid) == T.get(l2, l2 + mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }

    /**
     * @brief S[l, r) が回文であるかどうかを判定する
     */
    bool is_palindrome(int l, int r) const {
        return get(l, r) == get_rev(N - r, N - l);
    }
};

#endif // RollingHash_HPP