---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/LazySegtree_arith.hpp
    title: "b, a+b, ..., (r-l)a + b \u3067\u66F4\u65B0"
  - icon: ':warning:'
    path: DataStructure/LazySegtree_arith_add.hpp
    title: "b, a+b, ..., (r-l)a + b \u3092\u52A0\u7B97"
  - icon: ':warning:'
    path: ac-library/atcoder/convolution.hpp
    title: ac-library/atcoder/convolution.hpp
  - icon: ':warning:'
    path: ac-library/atcoder/lazysegtree.hpp
    title: ac-library/atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: ac-library/atcoder/segtree.hpp
    title: ac-library/atcoder/segtree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ac-library/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \nnamespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\n\
    using std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\nunsigned\
    \ int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x < (unsigned\
    \ int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nint countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n\
    #include <bit>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus\
    \ >= 202002L\n\nusing std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\n\
    unsigned int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x\
    \ < (unsigned int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <=\
    \ n`\n// @return same with std::bit::countr_zero\nint countr_zero(unsigned int\
    \ n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n//\
    \ @param n `1 <= n`\n// @return same with std::bit::countr_zero\nconstexpr int\
    \ countr_zero_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1\
    \ << x))) x++;\n    return x;\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP"
  dependsOn: []
  isVerificationFile: false
  path: ac-library/atcoder/internal_bit.hpp
  requiredBy:
  - ac-library/atcoder/lazysegtree.hpp
  - ac-library/atcoder/convolution.hpp
  - ac-library/atcoder/segtree.hpp
  - DataStructure/LazySegtree_arith.hpp
  - DataStructure/LazySegtree_arith_add.hpp
  timestamp: '2024-09-28 19:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ac-library/atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/ac-library/atcoder/internal_bit.hpp
- /library/ac-library/atcoder/internal_bit.hpp.html
title: ac-library/atcoder/internal_bit.hpp
---
