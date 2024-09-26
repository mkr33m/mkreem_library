---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "N \u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u306B\u3064\u3044\
      \u3066\u3001\u7D20\u6570\u306E\u7A2E\u985E\u6570\u3092\u6570\u3048\u308B\uFF08\
      1 \u7A2E\u985E\u306A\u3089\u7D20\u6570\uFF09"
    links: []
  bundledCode: "#line 1 \"Math/sieve.hpp\"\n\n\n\n#include <vector>\n\n/**\n * @brief\
    \ N \u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u306B\u3064\u3044\u3066\u3001\u7D20\
    \u6570\u306E\u7A2E\u985E\u6570\u3092\u6570\u3048\u308B\uFF081 \u7A2E\u985E\u306A\
    \u3089\u7D20\u6570\uFF09\n * @remark (Nloglog(N))\n */\nstd::vector<int> sieve(int\
    \ N){\n    std::vector<int> res(N + 1);\n    for(int i = 2; i <= N; i++){\n  \
    \      if(res[i] != 0) continue; // \u5408\u6210\u6570\n        for(int j = 1;\
    \ i * j <= N; j++){\n            res[i * j]++;\n        }\n    }\n    return res;\n\
    }\n\n\n"
  code: "#ifndef sieve_HPP\n#define sieve_HPP\n\n#include <vector>\n\n/**\n * @brief\
    \ N \u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u306B\u3064\u3044\u3066\u3001\u7D20\
    \u6570\u306E\u7A2E\u985E\u6570\u3092\u6570\u3048\u308B\uFF081 \u7A2E\u985E\u306A\
    \u3089\u7D20\u6570\uFF09\n * @remark (Nloglog(N))\n */\nstd::vector<int> sieve(int\
    \ N){\n    std::vector<int> res(N + 1);\n    for(int i = 2; i <= N; i++){\n  \
    \      if(res[i] != 0) continue; // \u5408\u6210\u6570\n        for(int j = 1;\
    \ i * j <= N; j++){\n            res[i * j]++;\n        }\n    }\n    return res;\n\
    }\n\n#endif // sieve_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sieve.hpp
layout: document
redirect_from:
- /library/Math/sieve.hpp
- /library/Math/sieve.hpp.html
title: "N \u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u306B\u3064\u3044\u3066\u3001\
  \u7D20\u6570\u306E\u7A2E\u985E\u6570\u3092\u6570\u3048\u308B\uFF081 \u7A2E\u985E\
  \u306A\u3089\u7D20\u6570\uFF09"
---
