#ifndef Monoids_HPP
#define Monoids_HPP

#include <cmath>

#include "/home/pomelo/ac-library/atcoder/modint.hpp"
#define ATCODER_MODINT_HPP // <- #include <ac-library/all> したときに重複してしまうから必須

// 加算モノイド
template <typename T>
struct AddMonoid {
    using S = T;
    static S e(){
        return 0;
    }
    static S op(const S& l, const S& r){
        return l + r;
    }
    static S inv(const S& x){
        return -x;
    }
};

// 掛算モノイド
template <typename T = atcoder::modint998244353>
struct MultiplyMonoid_998 {
    using S = T;
    static S e(){
        return 1;
    }
    static S op(const S& l, const S& r){
        return l * r;
    }
    static S inv(const S& x){
        return x.inv();
    }
};

// 掛算モノイド
template <typename T = atcoder::modint1000000007>
struct MultiplyMonoid_100 {
    using S = T;
    static S e(){
        return 1;
    }
    static S op(const S& l, const S& r){
        return l * r;
    }
    static S inv(const S& x){
        return x.inv();
    }
};

// 最大値モノイド
template <typename T>
struct MaxMonoid {
    using S = T;
    static S e(){
        return std::numeric_limits<S>::min();
    }
    static S op(const S& l, const S& r){
        return std::max(l, r);
    }
};

// 最小値モノイド
template <typename T>
struct MinMonoid {
    using S = T;
    static S e(){
        return std::numeric_limits<S>::max();
    }
    static S op(const S& l, const S& r){
        return std::min(l, r);
    }
};

// AND モノイド
template <typename T>
struct AndMonoid {
    using S = T;
    static S e(){
        return ~0;
    }
    static S op(const S& l, const S& r){
        return l & r;
    }
};

// OR モノイド
template <typename T>
struct OrMonoid {
    using S = T;
    static S e(){
        return 0;
    }
    static S op(const S& l, const S& r){
        return l | r;
    }
};

// XOR モノイド
template <typename T>
struct XorMonoid {
    using S = T;
    static S e(){
        return 0;
    }
    static S op(const S& l, const S& r){
        return l ^ r;
    }
    static S inv(const S& x){
        return x;
    }
};

#endif // Monoids_HPP