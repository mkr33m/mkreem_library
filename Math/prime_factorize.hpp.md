---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\
      \u7D50\u679C\u3092 map \u306B\u683C\u7D0D\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"Math/prime_factorize.hpp\"\n\n\n\n#include <map>\n\n/**\n\
    \ * @brief N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\u7D50\
    \u679C\u3092 map \u306B\u683C\u7D0D\u3059\u308B\n */\ntemplate<typename T>\nstd::map<T,\
    \ int> prime_factorize(T N){\n    std::map<T, int> res;\n\n    for(T i = 2; i\
    \ * i <= N; i++){\n        if(N % i != 0) continue;\n\n        int exp = 0; //\
    \ \u6307\u6570\n        // \u5272\u308C\u308B\u9650\u308A\u5272\u308A\u7D9A\u3051\
    \u308B\n        while(N % i == 0){\n            exp++;\n            N /= i;\n\
    \        }\n        res[i] = exp;\n    }\n\n    // \u7D20\u6570\u306E\u3068\u304D\
    \u30012 ~ \u221AN \u306E\u3044\u305A\u308C\u3067\u3082\u5272\u308A\u5207\u308B\
    \u3053\u3068\u304C\u3067\u304D\u306A\u3044\u306E\u3067\u3001N \u306F\u305D\u306E\
    \u307E\u307E\u306B\u306A\u308B\n    if(N != 1) res[N] = 1;\n    return res;\n\
    }\n\n\n"
  code: "#ifndef prime_factorize_HPP\n#define prime_factorize_HPP\n\n#include <map>\n\
    \n/**\n * @brief N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\
    \u7D50\u679C\u3092 map \u306B\u683C\u7D0D\u3059\u308B\n */\ntemplate<typename\
    \ T>\nstd::map<T, int> prime_factorize(T N){\n    std::map<T, int> res;\n\n  \
    \  for(T i = 2; i * i <= N; i++){\n        if(N % i != 0) continue;\n\n      \
    \  int exp = 0; // \u6307\u6570\n        // \u5272\u308C\u308B\u9650\u308A\u5272\
    \u308A\u7D9A\u3051\u308B\n        while(N % i == 0){\n            exp++;\n   \
    \         N /= i;\n        }\n        res[i] = exp;\n    }\n\n    // \u7D20\u6570\
    \u306E\u3068\u304D\u30012 ~ \u221AN \u306E\u3044\u305A\u308C\u3067\u3082\u5272\
    \u308A\u5207\u308B\u3053\u3068\u304C\u3067\u304D\u306A\u3044\u306E\u3067\u3001\
    N \u306F\u305D\u306E\u307E\u307E\u306B\u306A\u308B\n    if(N != 1) res[N] = 1;\n\
    \    return res;\n}\n\n#endif // H_prime_factorize"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime_factorize.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime_factorize.hpp
layout: document
redirect_from:
- /library/Math/prime_factorize.hpp
- /library/Math/prime_factorize.hpp.html
title: "N \u306E\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\u7D50\u679C\
  \u3092 map \u306B\u683C\u7D0D\u3059\u308B"
---