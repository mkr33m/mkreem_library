#ifndef AbelianGroup_HPP
#define AbelianGroup_HPP

/**
 * 保証される代数的構造
 * ・結合法則
 * ・単位元の存在
 * ・逆元の存在
 * ・可換性
 */

#include <cmath>

#include "/home/pomelo/github.com/mkreem_library/ac-library/atcoder/modint.hpp"
#ifndef ATCODER_MODINT_HPP
#define ATCODER_MODINT_HPP // <- #include <ac-library/all> したときに重複してしまうから必須
#endif

// 加算群
template <typename T>
struct AdditiveGroup {
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

// 乗算群
template <typename T = atcoder::modint998244353>
struct MultiplicativeGroup_998 {
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

// 乗算群
template <typename T = atcoder::modint1000000007>
struct MultiplicativeGroup_100 {
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

// XOR 群
template <typename T>
struct XorGroup {
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


#endif // AbelianGroup_HPP