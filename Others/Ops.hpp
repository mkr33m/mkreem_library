#ifndef Ops_HPP
#define Ops_HPP

#include <cmath>
#include <numeric>
#include "macros.hpp"
#include "../Math/Matrix.hpp"

template <typename S>
struct AddMulOps {
    using T = S;
    static T add(T a, T b) { return a + b; }
    static T mul(T a, T b) { return a * b; }
    static T zero() { return T(0); }
    static T one() { return T(1); }
};

struct MinPlusOps {
    using T = long long;
    static T add(T a, T b) { return std::min(a, b); }
    static T mul(T a, T b) { return a + b; }
    static T zero() { return LLINF; }
    static T one() { return 0LL; }
};

template <typename S>
struct MaxPlusOps {
    using T = long long;
    static T add(T a, T b) { return std::max(a, b); }
    static T mul(T a, T b) { return a + b; }
    static T zero() { return -LLINF; }
    static T one() { return 0LL; }
};

#endif // Ops_HPP