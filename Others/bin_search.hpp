#ifndef bin_search_HPP
#define bin_search_HPP

#include <cmath>

template <typename T, typename F>
/**
 * @param ok 解が存在する値
 * @param ng 解が存在しない値
 * @remark ok > ng の場合は最小値、ok < ng の場合は最大値を返却
 */
T bin_search(T& ok, T& ng, const F& f){
    while(std::abs(ok - ng) > 1){
        T mid = (ok - ng) / 2 + ng;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <typename T, typename F>
T bin_search_real(T& ok, T& ng, const F& f, int itr = 100){
    while(itr--){
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

#endif // bin_search_HPP