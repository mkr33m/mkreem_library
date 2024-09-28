#ifndef osa_k_HPP
#define osa_k_HPP

#include <vector>
#include <map>
#include <tuple>

struct osa_k {
private:
    using ll = long long;
    ll N;
    std::vector<int> min_factor;

public:
    /**
     * @rem O(Nlog(N))
     */
    osa_k(ll N) : N(N){
        min_factor.resize(N + 1);
        for(int i = 0; i <= N; i++){
            min_factor[i] = i;
        }
        min_factor[0] = min_factor[1] = -1;

        for(ll i = 2; i * i <= N; i++){
            if(min_factor[i] < i) continue; // iが合成数
            for(ll j = 2; i * j <= N; j++){
                min_factor[i * j] = i;
            }
        }
    }

    /**
     * @rem O(log(N))
     */
    std::map<ll, ll> prime_factorize(ll N){
        std::map<ll, ll> ret;
        while(N != 1){
            ret[min_factor[N]]++;
            N /= min_factor[N];
        }
        return ret;
    }

    /**
     * @brief Nの素因数の結果から、Nの約数を列挙する
     * @param idx 何番目の素因数を見ているか
     * @remark O(log(N))
     */
    void dfs(std::vector<std::pair<ll, ll>>& pf_N, std::vector<ll>& divs_N, ll div = 1, int idx = 0){
        if(idx == (int)pf_N.size()){
            divs_N.emplace_back(div);
            return;
        }

        ll mult = 1;
        for(int i = 0; i < pf_N[idx].second; i++){// idx番目の素因数を何個含む約数か
            dfs(pf_N, divs_N, div * mult, idx + 1);
            mult *= pf_N[idx].first;
        }
    }

    std::vector<ll> enum_divisors(ll N){
        std::map<ll, ll> pf_N_map = prime_factorize(N);
        std::vector<std::pair<ll, ll>> pf_N;
        std::vector<ll> divs_N;
        for(const auto& x : pf_N_map){
            pf_N.emplace_back(x.first, x.second);
        }
        dfs(pf_N, divs_N);
        return divs_N; // 未ソート
    }
};

#endif // osa_k_HPP