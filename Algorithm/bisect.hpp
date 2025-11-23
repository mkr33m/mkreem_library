#ifndef bin_search_HPP
#define bin_search_HPP

#include <cmath>

template <typename T, typename F>
T bisect(T& ok, T& ng, const F& f) {
    while (std::abs(ok - ng) > 1) {
        T mid = (ok - ng) / 2 + ng;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

template <typename T, typename F>
T bisect_real(T& ok, T& ng, const F& f, int itr = 80) {
    while (itr--) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

#endif // bisect_HPP