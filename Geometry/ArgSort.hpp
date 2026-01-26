#ifndef ArgSort_HPP
#define ArgSort_HPP

#include <array>
#include <cassert>
#include <cmath>
#include <tuple>

template <int dx = 1, int dy = 0, bool cw = false, typename T = long long>
bool argcmp(const std::pair<T, T> a, const std::pair<T, T> b) {
    static_assert((dx == 0 or dy == 0) and (std::abs(dx) + std::abs(dy) == 1),
            "basis must be one of (1,0),(0,1),(-1,0),(0,-1)");
    
    std::array<int, 4> mp{};
    if (dx == 1 and dy == 0) {
        if (cw) {
            mp = {3, 2, 1, 0};
        } else {
            mp = {0, 1, 2, 3};
        }
    } else if (dx == 0 and dy == 1) {
        if (cw) {
            mp = {0, 3, 2, 1};
        } else {
            mp = {3, 0, 1, 2};
        }
    } else if (dx == -1 and dy == 0) {
        if (cw) {
            mp = {1, 0, 3, 2};
        } else {
            mp = {2, 3, 0, 1};
        }
    } else if (dx == 0 and dy == -1) {
        if (cw) {
            mp = {2, 1, 0, 3};
        } else {
            mp = {1, 2, 3, 0};
        }
    }

    auto shogen = [&](const T& x, const T& y) {
        bool xp = (x >= 0), yp = (y >= 0);
        if ( xp and  yp) return mp[0];
        if (!xp and  yp) return mp[1];
        if (!xp and !yp) return mp[2];
        return mp[3]; // (xp and !yp)
    };

    const T x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second;
    const int s1 = shogen(x1, y1), s2 = shogen(x2, y2);
    if (s1 != s2) {
        return s1 < s2;
    }

    auto cross = [](__int128 x1, __int128 y1, __int128 x2, __int128 y2) -> __int128 {
        return x1 * y2 - y1 * x2;
    };

    __int128 c = cross(x1, y1, x2, y2);
    if (cw) {
        return c < 0;
    }
    return c > 0;
}

#endif // ArgSort_HPP