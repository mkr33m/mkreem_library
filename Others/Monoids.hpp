#ifndef Monoids_HPP
#define Monoids_HPP

/**
 * 保証される代数的構造
 * ・結合法則
 * ・単位元の存在
 * （・可換性）
 */

#include <cmath>

#include "/home/pomelo/github.com/mkreem_library/ac-library/atcoder/modint.hpp"
#ifndef ATCODER_MODINT_HPP
#define ATCODER_MODINT_HPP // <- #include <ac-library/all> したときにもっかいもう一度インクルードしてしまうから必須
#endif

// 加算モノイド
template <typename T>
struct AddMonoid {
    using S = T;
    static S e() {
        return 0;
    }
    static S op(const S& l, const S& r) {
        return l + r;
    }
};

// 乗算モノイド
template <typename T = atcoder::modint998244353>
struct MultiplyMonoid_998 {
    using S = T;
    static S e() {
        return 1;
    }
    static S op(const S& l, const S& r) {
        return l * r;
    }
};

// 乗算モノイド
template <typename T = atcoder::modint1000000007>
struct MultiplyMonoid_100 {
    using S = T;
    static S e() {
        return 1;
    }
    static S op(const S& l, const S& r) {
        return l * r;
    }
};

// 最大値モノイド
template <typename T>
struct MaxMonoid {
    using S = T;
    static S e() {
        return std::numeric_limits<S>::min();
    }
    static S op(const S& l, const S& r) {
        return std::max(l, r);
    }
};

// 最小値モノイド
template <typename T>
struct MinMonoid {
    using S = T;
    static S e() {
        return std::numeric_limits<S>::max();
    }
    static S op(const S& l, const S& r) {
        return std::min(l, r);
    }
};

// AND モノイド
template <typename T>
struct AndMonoid {
    using S = T;
    static S e() {
        return ~0;
    }
    static S op(const S& l, const S& r) {
        return l & r;
    }
};

// OR モノイド
template <typename T>
struct OrMonoid {
    using S = T;
    static S e() {
        return 0;
    }
    static S op(const S& l, const S& r) {
        return l | r;
    }
};

// XOR モノイド
template <typename T>
struct XorMonoid {
    using S = T;
    static S e() {
        return 0;
    }
    static S op(const S& l, const S& r) {
        return l ^ r;
    }
};

#endif // Monoids_HPP