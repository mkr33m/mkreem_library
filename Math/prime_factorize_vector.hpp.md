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
    document_title: "N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\
      \u7D50\u679C\u3092 map \u306B\u683C\u7D0D\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"Math/prime_factorize_vector.hpp\"\n\n\n\n#include <vector>\n\
    #include <tuple>\n\n/**\n * @brief N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\
    \u3001\u305D\u306E\u7D50\u679C\u3092 map \u306B\u683C\u7D0D\u3059\u308B\n */\n\
    template<typename T>\nstd::vector<std::pair<T, int>> prime_factorize_vector(T\
    \ N) {\n    std::vector<std::pair<T, int>> res;\n\n    for (T i = 2; i * i <=\
    \ N; i++) {\n        if(N % i != 0) {\n            continue;\n        }\n\n  \
    \      int exp = 0;\n        while (N % i == 0) {\n            exp++;\n      \
    \      N /= i;\n        }\n        res.emplace_back(i, exp);\n    }\n\n    //\
    \ \u7D20\u6570\u306E\u3068\u304D\u30012 ~ \u221AN \u306E\u3044\u305A\u308C\u3067\
    \u3082\u5272\u308A\u5207\u308B\u3053\u3068\u304C\u3067\u304D\u306A\u3044\u306E\
    \u3067\u3001N \u306F\u305D\u306E\u307E\u307E\n    if (N != 1) {\n        res.emplace_back(N,\
    \ 1);\n    }\n\n    return res;\n}\n\n\n"
  code: "#ifndef prime_factorize_vector_HPP\n#define prime_factorize_vector_HPP\n\n\
    #include <vector>\n#include <tuple>\n\n/**\n * @brief N \u306E\u7D20\u56E0\u6570\
    \u5206\u89E3\u3057\u3001\u305D\u306E\u7D50\u679C\u3092 map \u306B\u683C\u7D0D\u3059\
    \u308B\n */\ntemplate<typename T>\nstd::vector<std::pair<T, int>> prime_factorize_vector(T\
    \ N) {\n    std::vector<std::pair<T, int>> res;\n\n    for (T i = 2; i * i <=\
    \ N; i++) {\n        if(N % i != 0) {\n            continue;\n        }\n\n  \
    \      int exp = 0;\n        while (N % i == 0) {\n            exp++;\n      \
    \      N /= i;\n        }\n        res.emplace_back(i, exp);\n    }\n\n    //\
    \ \u7D20\u6570\u306E\u3068\u304D\u30012 ~ \u221AN \u306E\u3044\u305A\u308C\u3067\
    \u3082\u5272\u308A\u5207\u308B\u3053\u3068\u304C\u3067\u304D\u306A\u3044\u306E\
    \u3067\u3001N \u306F\u305D\u306E\u307E\u307E\n    if (N != 1) {\n        res.emplace_back(N,\
    \ 1);\n    }\n\n    return res;\n}\n\n#endif // prime_factorize_vector_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime_factorize_vector.hpp
  requiredBy:
  - all_includes.hpp
  timestamp: '2026-01-26 21:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime_factorize_vector.hpp
layout: document
redirect_from:
- /library/Math/prime_factorize_vector.hpp
- /library/Math/prime_factorize_vector.hpp.html
title: "N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\u7D50\u679C\
  \u3092 map \u306B\u683C\u7D0D\u3059\u308B"
---
