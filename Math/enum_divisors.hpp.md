---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/enum_divisors.hpp\"\n\n\n\n#include <vector>\n\ntemplate<typename\
    \ T>\nstd::vector<T> enum_divisors(T N){\n    std::vector<T> res;\n\n    for (T\
    \ i = 1; i * i <= N; i++) {\n        if (N % i == 0) {\n            res.push_back(i);\n\
    \            if(N / i != i) res.push_back(N / i);\n        }\n    }\n\n    return\
    \ res; // \u672A\u30BD\u30FC\u30C8\n}\n\n\n"
  code: "#ifndef enum_divisors_HPP\n#define enum_divisors_HPP\n\n#include <vector>\n\
    \ntemplate<typename T>\nstd::vector<T> enum_divisors(T N){\n    std::vector<T>\
    \ res;\n\n    for (T i = 1; i * i <= N; i++) {\n        if (N % i == 0) {\n  \
    \          res.push_back(i);\n            if(N / i != i) res.push_back(N / i);\n\
    \        }\n    }\n\n    return res; // \u672A\u30BD\u30FC\u30C8\n}\n\n#endif\
    \ // enum_divisors_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/enum_divisors.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/enum_divisors.hpp
layout: document
redirect_from:
- /library/Math/enum_divisors.hpp
- /library/Math/enum_divisors.hpp.html
title: Math/enum_divisors.hpp
---
