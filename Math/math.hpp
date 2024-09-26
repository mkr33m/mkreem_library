#ifndef math_HPP
#define math_HPP

#include "../Others/macros.hpp"

namespace math {

    /**
     * @brief 繰り返し二乗法を利用した、x^nの求値
     */
    ll pow(ll x, ll n){
        ll res = 1;

        while(n){
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }

        return res;
    }

    /**
     * @brief x/mのfloor（x/m以下の最大の整数）を求める
     */
    ll floor(const ll& x, const ll& m){
        ll r = (x % m + m) % m; // xをmで割った余り
        return (x - r) / m;
    }

    /**
     * @brief x/mのceil（x/m以上の最小の整数）を求める
     */
    ll ceil(const ll& x, const ll& m){
        return floor(x + m - 1, m); // x/m + (m-1)/m
    }

    /**
     * @brief log(2)N の整数部分を求める
     */
    int log2_floor(long long N){
        int res = -1;
        while(N != 0){
            res++;
            N /= 2;
        }
        return res;
    }

} // namespace math

#endif // math_HPP