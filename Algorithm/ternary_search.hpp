#ifndef ternary_search_HPP
#define ternary_search_HPP

#include <tuple>
#include <functional>

/**
 * @brief 凸関数の [L, R] における最小（最大値）を返す
 * @param get_min true で最小値、false で最大値を求める
 * @return 最小（最大）値となる引数の値・最小（最大）値を pair で返す
 */
template <bool get_min = true, class F>
auto ternary_search(auto L, auto R, const F& f) {
    int iter = 100;
    while (iter--) {
        auto l = L + (R - L) / 3;
        auto r = R - (R - L) / 3;
        if ((f(l) < f(r)) ^ get_min) {
            L = l;
        } else {
            R = r;
        }
    }
    return std::make_pair(L, f(L));
}

#endif // ternary_search_HPP