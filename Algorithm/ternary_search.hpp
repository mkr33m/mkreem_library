#ifndef ternary_search_HPP
#define ternary_search_HPP

#include <tuple>
#include <functional>

/**
 * @brief 凸関数の [L, R] における最小（最大値）を返す
 * @param Arg 評価関数 f の引数の型
 * @param Val 評価関数 f の返り値の型
 * @param get_min true で最小値、false で最大値を求める
 * @return 最小（最大）値となる引数の値・最小（最大）値を pair で返す
 */
template <typename Arg, typename Val, bool get_min = true>
std::pair<Arg, Val> ternary_search(Arg L, Arg R, const std::function<Val(Arg)>& f) {
    int iter = 80;
    while (iter--) {
        Arg l = (L * 2 + R) / 3;
        Arg r = (L + R * 2) / 3;
        if ((f(l) < f(r)) ^ get_min) {
            L = l;
        } else {
            R = r;
        }
    }
    return std::make_pair(L, f(L));
}

#endif // ternary_search_HPP