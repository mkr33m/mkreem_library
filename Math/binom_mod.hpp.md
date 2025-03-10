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
  bundledCode: "#line 1 \"Math/binom_mod.hpp\"\n\n\n\n#include <vector>\n\ntemplate\
    \ <typename T>\nstruct BinomMod {\nprivate:\n    int MAX_N;\n    int mod;\n  \
    \  std::vector<T> factorial, factorial_inv;\n\npublic:\n    BinomMod() = default;\n\
    \    BinomMod(int MAX_N = 10000000) : MAX_N(MAX_N), mod(mod), factorial(MAX_N\
    \ + 1, 0), factorial_inv(MAX_N + 1, 0) {\n        factorial[0] = 1;\n        for\
    \ (int i = 1; i <= MAX_N; i++) {\n            factorial[i] = factorial[i - 1]\
    \ * i;\n        }\n        factorial_inv[MAX_N] = factorial[MAX_N].inv();\n  \
    \      for (int i = MAX_N - 1; i >= 0; i--) {\n            factorial_inv[i] =\
    \ factorial_inv[i + 1] * (i + 1);\n        }\n    }\n\n    T val(int N, int K)\
    \ {\n        if (N < K || N < 0 || K < 0) {\n            return T(0);\n      \
    \  }\n        return factorial[N] * factorial_inv[K] * factorial_inv[N - K];\n\
    \    }\n};\n\n\n"
  code: "#ifndef binom_mod_HPP\n#define binom_mod_HPP\n\n#include <vector>\n\ntemplate\
    \ <typename T>\nstruct BinomMod {\nprivate:\n    int MAX_N;\n    int mod;\n  \
    \  std::vector<T> factorial, factorial_inv;\n\npublic:\n    BinomMod() = default;\n\
    \    BinomMod(int MAX_N = 10000000) : MAX_N(MAX_N), mod(mod), factorial(MAX_N\
    \ + 1, 0), factorial_inv(MAX_N + 1, 0) {\n        factorial[0] = 1;\n        for\
    \ (int i = 1; i <= MAX_N; i++) {\n            factorial[i] = factorial[i - 1]\
    \ * i;\n        }\n        factorial_inv[MAX_N] = factorial[MAX_N].inv();\n  \
    \      for (int i = MAX_N - 1; i >= 0; i--) {\n            factorial_inv[i] =\
    \ factorial_inv[i + 1] * (i + 1);\n        }\n    }\n\n    T val(int N, int K)\
    \ {\n        if (N < K || N < 0 || K < 0) {\n            return T(0);\n      \
    \  }\n        return factorial[N] * factorial_inv[K] * factorial_inv[N - K];\n\
    \    }\n};\n\n#endif // binom_mod_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/binom_mod.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/binom_mod.hpp
layout: document
redirect_from:
- /library/Math/binom_mod.hpp
- /library/Math/binom_mod.hpp.html
title: Math/binom_mod.hpp
---
