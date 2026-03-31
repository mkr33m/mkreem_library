#ifndef kth_root_integer_HPP
#define kth_root_integer_HPP

#include <stdint.h>

/**
 * @brief floor(a^{1/k}) を返す
 * @remark a<2^64, K<=64
 */
uint64_t kth_root_integer(uint64_t a, int k) {
    if (k == 1) {
        return a;
    }
    if (k >= 64) { // K>=64 なら、x^k<=a を満たす x は 1 しかない
        return 1;
    }
    // x^k <= a
    // x^{k+1} > a
    // を満たす最大の正整数 x を求めたい
    auto check = [&](uint32_t x) -> bool {
        uint64_t mul = 1;
        for (int _ = 0; _ < k; _++) {
            if (mul > a / x) {
                return false;
            }
            mul *= x;
        }
        return mul <= a;
    };
    // k>=2 なら、x<2^32
    uint64_t res = 0;
    for (int i = 31; i >= 0; i--) {
        if (check(res | (1u << i))) {
            res |= (1u << i);
        }
    }
    return res;
}

#endif // kth_root_integer_HPP