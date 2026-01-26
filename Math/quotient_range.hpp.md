---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all_includes.hpp
    title: all_includes.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "floor(N/i) (1<=i<=N) \u306B\u3064\u3044\u3066\u3001p=floor(N/i)\
      \ \u3068\u306A\u308B i \u306E\u7BC4\u56F2 [l,r] \u3092\u5168\u3066\u306E p \u3067\
      \u6C42\u3081\u308B"
    links: []
  bundledCode: "#line 1 \"Math/quotient_range.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <tuple>\n\n/**\n * @brief floor(N/i) (1<=i<=N) \u306B\u3064\u3044\u3066\u3001\
    p=floor(N/i) \u3068\u306A\u308B i \u306E\u7BC4\u56F2 [l,r] \u3092\u5168\u3066\u306E\
    \ p \u3067\u6C42\u3081\u308B\n * @remark floor(N/i) (1<=i<=N) \u306E\u8981\u7D20\
    \u306E\u500B\u6570\u306F\u9AD8\u3005 O(sqrt(N)) \u3067\u6291\u3048\u3089\u308C\
    \u308B\n * @remark [p,l,r] \u306E\u9806\u3067\u8A18\u9332\u3057\u305F vector<tuple<>>\
    \ \u3092\u8FD4\u3059\n */\n\ntemplate <typename T>\nstd::vector<std::tuple<T,\
    \ T, T>> quotient_range(T N) {\n    std::vector<std::tuple<T, T, T>> res;\n  \
    \  T L = 1;\n    while (L <= N) {\n        T p = N / L, R = N / p;\n        res.emplace_back(p,\
    \ L, R);\n        L = R + 1;\n    }\n    return res;\n}\n\n\n"
  code: "#ifndef quotient_range_HPP\n#define quotient_range_HPP\n\n#include <vector>\n\
    #include <tuple>\n\n/**\n * @brief floor(N/i) (1<=i<=N) \u306B\u3064\u3044\u3066\
    \u3001p=floor(N/i) \u3068\u306A\u308B i \u306E\u7BC4\u56F2 [l,r] \u3092\u5168\u3066\
    \u306E p \u3067\u6C42\u3081\u308B\n * @remark floor(N/i) (1<=i<=N) \u306E\u8981\
    \u7D20\u306E\u500B\u6570\u306F\u9AD8\u3005 O(sqrt(N)) \u3067\u6291\u3048\u3089\
    \u308C\u308B\n * @remark [p,l,r] \u306E\u9806\u3067\u8A18\u9332\u3057\u305F vector<tuple<>>\
    \ \u3092\u8FD4\u3059\n */\n\ntemplate <typename T>\nstd::vector<std::tuple<T,\
    \ T, T>> quotient_range(T N) {\n    std::vector<std::tuple<T, T, T>> res;\n  \
    \  T L = 1;\n    while (L <= N) {\n        T p = N / L, R = N / p;\n        res.emplace_back(p,\
    \ L, R);\n        L = R + 1;\n    }\n    return res;\n}\n\n#endif // quotient_range_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/quotient_range.hpp
  requiredBy:
  - all_includes.hpp
  timestamp: '2026-01-26 21:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/quotient_range.hpp
layout: document
redirect_from:
- /library/Math/quotient_range.hpp
- /library/Math/quotient_range.hpp.html
title: "floor(N/i) (1<=i<=N) \u306B\u3064\u3044\u3066\u3001p=floor(N/i) \u3068\u306A\
  \u308B i \u306E\u7BC4\u56F2 [l,r] \u3092\u5168\u3066\u306E p \u3067\u6C42\u3081\u308B"
---
