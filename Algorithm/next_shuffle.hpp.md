---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "(K,N - K)-shuffle \u3067\u3042\u308B0, 1, ..., N - 1 \u306E\u7F6E\
      \u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B"
    links:
    - https://atcoder.jp/contests/abc328/tasks/abc328_e
  bundledCode: "#line 1 \"Algorithm/next_shuffle.hpp\"\n\n\n\n/*\nverify\n\u30FBhttps://atcoder.jp/contests/abc328/tasks/abc328_e\n\
    */\n\n#include <vector>\n#include <limits>\n#include <algorithm>\n\ntemplate <typename\
    \ T>\n/**\n * @brief (K,N - K)-shuffle \u3067\u3042\u308B0, 1, ..., N - 1 \u306E\
    \u7F6E\u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B\n\
    \ */\nbool next_shuffle(std::vector<T>& vec, const int& K){\n    int N = vec.size();\n\
    \    if(N <= K){\n        return false;\n    }\n\n    // \u524D K \u9805 := L\n\
    \    // \u5F8C\u308DN - K\u9805 := R\n    auto left = vec.begin();\n    auto right\
    \ = vec.begin() + K;\n    T R_max = *std::max_element(right, vec.end());\n   \
    \ T tmp = (std::numeric_limits<T>::min)();\n    /**\n     * @param i L \u306E\u8981\
    \u7D20\u306E\u4E2D\u3067\u3001R \u306E\u8981\u7D20\u306E\u6700\u5927\u5024\u3088\
    \u308A\u3082\u5C0F\u3055\u3044\u3082\u306E\u306E\u3046\u3061\u3001\u6700\u5927\
    \u306E\u3082\u306E\u306E\u30A4\u30C6\u30EC\u30FC\u30BF (*i := L_(i))\n     */\n\
    \    auto tmpi = left, i = right;\n    while(tmpi != right){\n        if(tmp <=\
    \ *tmpi && *tmpi < R_max){\n            tmp = *tmpi;\n            i = tmpi;\n\
    \        }\n        tmpi++;\n    }\n    if(i == right){\n        std::sort(vec.begin(),\
    \ vec.end());\n        return false;\n    }\n\n    /**\n     * @param j R \u306E\
    \u8981\u7D20\u306E\u4E2D\u3067\u3001L_(i) \u3088\u308A\u3082\u5927\u304D\u3044\
    \u3082\u306E\u306E\u3046\u3061\u3001\u6700\u5C0F\u306E\u3082\u306E\u306E\u30A4\
    \u30C6\u30EC\u30FC\u30BF (*j := R_(j))\n     */\n    tmp = (std::numeric_limits<T>::max)();\n\
    \    auto tmpj = right, j = vec.end();\n    while(tmpj != vec.end()){\n      \
    \  if(tmp >= *tmpj && *tmpj > *i){\n            tmp = *tmpj;\n            j =\
    \ tmpj;\n        }\n        tmpj++;\n    }\n\n    std::iter_swap(i, j); // L_(i)\u3068\
    R_(j)\u3092swap\n    i++, j++;\n    // \u3084\u308A\u305F\u3044\u3053\u3068\uFF1A\
    L_(i + 1)\uFF5EL_(K - 1)(:= X) \u3068 R_(j + 1)\uFF5ER_(N - K - 1)(:= Y) \u3092\
    \u63A5\u7D9A\u3057\u3001R_(j + 1) \u304C\u5148\u982D\u306B\u6765\u308B\u3088\u3046\
    \u306B\u56DE\u8EE2\u3059\u308B\n    int X_len = K - std::distance(left, i);\n\
    \    int Y_len = N - K - std::distance(right, j);\n    int swap_len = std::min(X_len,\
    \ Y_len);\n    // X \u306E\u672B\u5C3E swap_len \u9805\u3068 Y \u306E\u672B\u5C3E\
    \ swap_len \u9805\u3092 swap \u3059\u308B\n    std::swap_ranges(right - swap_len,\
    \ right, j);\n    if(swap_len == X_len){\n        std::rotate(j, j + swap_len,\
    \ vec.end());\n    }\n    else{\n        std::rotate(i, right - swap_len, right);\n\
    \    }\n\n    return true;\n}\n\n\n"
  code: "#ifndef next_shuffle_HPP\n#define next_shuffle_HPP\n\n/*\nverify\n\u30FB\
    https://atcoder.jp/contests/abc328/tasks/abc328_e\n*/\n\n#include <vector>\n#include\
    \ <limits>\n#include <algorithm>\n\ntemplate <typename T>\n/**\n * @brief (K,N\
    \ - K)-shuffle \u3067\u3042\u308B0, 1, ..., N - 1 \u306E\u7F6E\u63DB A \u3092\u3001\
    \u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B\n */\nbool next_shuffle(std::vector<T>&\
    \ vec, const int& K){\n    int N = vec.size();\n    if(N <= K){\n        return\
    \ false;\n    }\n\n    // \u524D K \u9805 := L\n    // \u5F8C\u308DN - K\u9805\
    \ := R\n    auto left = vec.begin();\n    auto right = vec.begin() + K;\n    T\
    \ R_max = *std::max_element(right, vec.end());\n    T tmp = (std::numeric_limits<T>::min)();\n\
    \    /**\n     * @param i L \u306E\u8981\u7D20\u306E\u4E2D\u3067\u3001R \u306E\
    \u8981\u7D20\u306E\u6700\u5927\u5024\u3088\u308A\u3082\u5C0F\u3055\u3044\u3082\
    \u306E\u306E\u3046\u3061\u3001\u6700\u5927\u306E\u3082\u306E\u306E\u30A4\u30C6\
    \u30EC\u30FC\u30BF (*i := L_(i))\n     */\n    auto tmpi = left, i = right;\n\
    \    while(tmpi != right){\n        if(tmp <= *tmpi && *tmpi < R_max){\n     \
    \       tmp = *tmpi;\n            i = tmpi;\n        }\n        tmpi++;\n    }\n\
    \    if(i == right){\n        std::sort(vec.begin(), vec.end());\n        return\
    \ false;\n    }\n\n    /**\n     * @param j R \u306E\u8981\u7D20\u306E\u4E2D\u3067\
    \u3001L_(i) \u3088\u308A\u3082\u5927\u304D\u3044\u3082\u306E\u306E\u3046\u3061\
    \u3001\u6700\u5C0F\u306E\u3082\u306E\u306E\u30A4\u30C6\u30EC\u30FC\u30BF (*j :=\
    \ R_(j))\n     */\n    tmp = (std::numeric_limits<T>::max)();\n    auto tmpj =\
    \ right, j = vec.end();\n    while(tmpj != vec.end()){\n        if(tmp >= *tmpj\
    \ && *tmpj > *i){\n            tmp = *tmpj;\n            j = tmpj;\n        }\n\
    \        tmpj++;\n    }\n\n    std::iter_swap(i, j); // L_(i)\u3068R_(j)\u3092\
    swap\n    i++, j++;\n    // \u3084\u308A\u305F\u3044\u3053\u3068\uFF1AL_(i + 1)\uFF5E\
    L_(K - 1)(:= X) \u3068 R_(j + 1)\uFF5ER_(N - K - 1)(:= Y) \u3092\u63A5\u7D9A\u3057\
    \u3001R_(j + 1) \u304C\u5148\u982D\u306B\u6765\u308B\u3088\u3046\u306B\u56DE\u8EE2\
    \u3059\u308B\n    int X_len = K - std::distance(left, i);\n    int Y_len = N -\
    \ K - std::distance(right, j);\n    int swap_len = std::min(X_len, Y_len);\n \
    \   // X \u306E\u672B\u5C3E swap_len \u9805\u3068 Y \u306E\u672B\u5C3E swap_len\
    \ \u9805\u3092 swap \u3059\u308B\n    std::swap_ranges(right - swap_len, right,\
    \ j);\n    if(swap_len == X_len){\n        std::rotate(j, j + swap_len, vec.end());\n\
    \    }\n    else{\n        std::rotate(i, right - swap_len, right);\n    }\n\n\
    \    return true;\n}\n\n#endif // next_shuffle_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/next_shuffle.hpp
  requiredBy: []
  timestamp: '2024-10-02 11:00:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/next_shuffle.hpp
layout: document
redirect_from:
- /library/Algorithm/next_shuffle.hpp
- /library/Algorithm/next_shuffle.hpp.html
title: "(K,N - K)-shuffle \u3067\u3042\u308B0, 1, ..., N - 1 \u306E\u7F6E\u63DB A\
  \ \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B"
---
