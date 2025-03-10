#ifndef math_HPP
#define math_HPP

#include "../Others/macros.hpp"

namespace math {

    ll pow(ll N, ll e) {
        ll res = 1;
        while (e) {
            if (e & 1) {
                res *= N;
            }
            N *= N;
            e >>= 1;
        }
        return res;
    }

    ll floor (const ll& x, const ll& m) {
        ll r = (x % m + m) % m;
        return (x - r) / m;
    }

    ll ceil (const ll& x, const ll& m) {
        return floor(x + m - 1, m);
    }

    int log2_floor(ll N) {
        int res = -1;
        while (N != 0) {
            res++;
            N /= 2;
        }
        return res;
    }

} // namespace math

#endif // math_HPP