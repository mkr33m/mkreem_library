#ifndef math_HPP
#define math_HPP

#include "../Others/macros.hpp"
#include <cassert>

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

    template <typename T>
    T floor (const T& x, const T& m) {
        T r = (x % m + m) % m;
        return (x - r) / m;
    }

    template <typename T>
    T ceil (const T& x, const T& m) {
        return floor(x + m - 1, m);
    }

    /**
     * @brief floor(sqrt(N)) を求める
     */
    template <typename T>
    T sqrt_floor(T N) {
        assert(N >= 0);
        ll R = sqrt(N);
        // R*R>N なら大きすぎるので減らす
        while (R * R > N) {
            R--;
        }
        // 二乗して N を超えないギリギリまで増やす
        while ((R + 1) * (R + 1) <= N) {
            R++;
        }
        return R;
    }

    /**
     * @brief ceil(sqrt(N)) を求める
     */
    template <typename T>
    T sqrt_ceil(T N) {
        ll R = sqrt_floor(N);
        if (R * R == N) {
            return R;
        }
        return R + 1;
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