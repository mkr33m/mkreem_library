#ifndef quotient_range_HPP
#define quotient_range_HPP

#include <vector>
#include <tuple>

/**
 * @brief floor(N/i) (1<=i<=N) について、p=floor(N/i) となる i の範囲 [l,r] を全ての p で求める
 * @remark floor(N/i) (1<=i<=N) の要素の個数は高々 O(sqrt(N)) で抑えられる
 * @remark [p,l,r] の順で記録した vector<tuple<>> を返す
 */

template <typename T>
std::vector<std::tuple<T, T, T>> quotient_range(T N) {
    std::vector<std::tuple<T, T, T>> res;
    T L = 1;
    while (L <= N) {
        T p = N / L, R = N / p;
        res.emplace_back(p, L, R);
        L = R + 1;
    }
    return res;
}

#endif // quotient_range_HPP