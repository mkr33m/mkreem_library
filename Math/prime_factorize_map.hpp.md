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
    links: []
  bundledCode: "#line 1 \"Math/prime_factorize_map.hpp\"\n\n\n\n#include <map>\n\n\
    template <typename T>\nstd::map<T, int> prime_factorize_map(T N) {\n    std::map<T,\
    \ int> res;\n\n    for (T i = 2; i * i <= N; i++) {\n        if(N % i != 0) {\n\
    \            continue;\n        }\n\n        int exp = 0;\n        while (N %\
    \ i == 0) {\n            exp++;\n            N /= i;\n        }\n        res[i]\
    \ = exp;\n    }\n\n    // \u7D20\u6570\u306E\u3068\u304D\u30012 ~ \u221AN \u306E\
    \u3044\u305A\u308C\u3067\u3082\u5272\u308A\u5207\u308B\u3053\u3068\u304C\u3067\
    \u304D\u306A\u3044\u306E\u3067\u3001N \u306F\u305D\u306E\u307E\u307E\n    if (N\
    \ != 1) {\n        res[N] = 1;\n    }\n\n    return res;\n}\n\n\n"
  code: "#ifndef prime_factorize_map_HPP\n#define prime_factorize_map_HPP\n\n#include\
    \ <map>\n\ntemplate <typename T>\nstd::map<T, int> prime_factorize_map(T N) {\n\
    \    std::map<T, int> res;\n\n    for (T i = 2; i * i <= N; i++) {\n        if(N\
    \ % i != 0) {\n            continue;\n        }\n\n        int exp = 0;\n    \
    \    while (N % i == 0) {\n            exp++;\n            N /= i;\n        }\n\
    \        res[i] = exp;\n    }\n\n    // \u7D20\u6570\u306E\u3068\u304D\u30012\
    \ ~ \u221AN \u306E\u3044\u305A\u308C\u3067\u3082\u5272\u308A\u5207\u308B\u3053\
    \u3068\u304C\u3067\u304D\u306A\u3044\u306E\u3067\u3001N \u306F\u305D\u306E\u307E\
    \u307E\n    if (N != 1) {\n        res[N] = 1;\n    }\n\n    return res;\n}\n\n\
    #endif // end prime_factorize_map_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime_factorize_map.hpp
  requiredBy:
  - all_includes.hpp
  timestamp: '2026-01-26 21:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime_factorize_map.hpp
layout: document
redirect_from:
- /library/Math/prime_factorize_map.hpp
- /library/Math/prime_factorize_map.hpp.html
title: Math/prime_factorize_map.hpp
---
