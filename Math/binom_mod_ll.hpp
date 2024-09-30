#ifndef binom_mod_ll_HPP
#define binom_mod_ll_HPP

#include <vector>
#include <cassert>

#include "../Others/macros.hpp"
#include "extended_gcd.hpp"

struct binom_mod_ll {
private:
    int MAX_N;
    ll MOD;
    std::vector<ll> factorial, factorial_inv;

    /**
     * @brief a の mod m における逆元 x を求める
     * a*x == 1 を満たす x を求めたいということは、a*x + b*y == 1 を満たす x を求めたいということ
     */
    ll mod_inverse(ll a, ll m){
        ll x, y;
        ll g = extended_gcd(a, m, x, y);
        assert(g == 1);
        return (x % m + m) % m;
    }

public:
    binom_mod_ll(int MAX_N = 10000000, ll MOD = 998244353) : MAX_N(MAX_N), MOD(MOD) {
        factorial[0] = 1;
        for(int i = 1; i <= MAX_N; i++){
            factorial[i] = factorial[i - 1] * i % MOD;
        }
        factorial_inv[MAX_N] = mod_inverse(factorial[MAX_N], MOD);
        for(int i = MAX_N - 1; i >= 0; i--){
            /*
            ((i+1)!)^(-1) ≡ (i+1)^(-1) * (i!)^(-1)
            より、
            (i!)^(-1) == ((i+1)!)^(-1) * (i+1)
            */
            factorial_inv[i] = factorial_inv[i + 1] * (i + 1) % MOD;
        }
    }

    ll val(int N, int K){
        if(N < K || N < 0 || K < 0){
            return 0;
        }
        return factorial[N] * (factorial_inv[K] * factorial_inv[N - K] % MOD) % MOD;
    }
};

#endif //binom_mod_ll_HPP