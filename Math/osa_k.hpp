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
    std::vector<int> primes;

public:
    /**
     * @rem O(Nlog(N))
     */
    osa_k(ll N) : N(N) {
        min_factor.assign(N + 1, 0);
        for (int i = 2; i <= N; i++) {
            if (min_factor[i] == 0) {
                min_factor[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > min_factor[i] || (ll)i * p > N) {
                    break;
                }
                min_factor[i * p] = p;
            }
        }
        if (N >= 0) {
            min_factor[0] = -1;
        }
        if (N >= 1) {
            min_factor[1] = -1;
        }
    }

    /**
     * @rem O(log(N))
     */
    std::vector<std::pair<ll, ll>> prime_factorize(ll N) {
        std::vector<std::pair<ll, ll>> ret;
        while (N != 1) {
            int factor = min_factor[N];
            if (ret.empty() || ret.back().first != factor) {
                ret.push_back({factor, 1});
            } else {
                ret.back().second++;
            }
            N /= factor;
        }
        return ret;
    }

    /**
     * @brief Nの素因数の結果から、Nの約数を列挙する
     * @param idx 何番目の素因数を見ているか
     * @remark O(log(N))
     */
    void dfs(std::vector<std::pair<ll, ll>>& pf_N, std::vector<ll>& divs_N, ll div = 1, int idx = 0) {
        if (idx == (int)pf_N.size()) {
            divs_N.emplace_back(div);
            return;
        }

        ll mult = 1;
        for (int i = 0; i <= pf_N[idx].second; i++) {// idx番目の素因数を何個含む約数か
            dfs(pf_N, divs_N, div * mult, idx + 1);
            mult *= pf_N[idx].first;
        }
    }

    std::vector<ll> enum_divisors(ll N) {
        std::vector<std::pair<ll, ll>> pf_N = prime_factorize(N);
        ll total = 1;
        for (const auto& p : pf_N) {
            total *= (p.second + 1);
        }
        std::vector<ll> divs_N;
        divs_N.reserve(total);
        dfs(pf_N, divs_N);
        return divs_N; // 未ソート
    }
};

#endif // osa_k_HPP