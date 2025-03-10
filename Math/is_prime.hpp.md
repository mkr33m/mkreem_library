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
  bundledCode: "#line 1 \"Math/is_prime.hpp\"\n\n\n\n#include <vector>\n\nclass IsPrime\
    \ {\nprivate:\n    int N;\n    std::vector<bool> is_prime_;\n    std::vector<int>\
    \ primes_;\n\npublic:\n    IsPrime(int N) : N(N), is_prime_(N + 1, true), primes_()\
    \ {\n        is_prime_[0] = is_prime_[1] = false;\n        \n        for (int\
    \ i = 2; i * i <= N; i++) {\n            if (!is_prime_[i]) {\n              \
    \  continue;\n            }\n            for (int j = i * i; j <= N; j += i) {\n\
    \                is_prime_[j] = false;\n            }\n        }\n\n        for\
    \ (int i = 2; i <= N; i++) {\n            if (is_prime_[i]) {\n              \
    \  primes_.push_back(i);\n            }\n        }\n    }\n\n    bool is_prime(int\
    \ x) {\n        return is_prime_[x];\n    }\n    const std::vector<int>& get_primes()\
    \ const& {\n        return primes_;\n    }\n};\n\n\n"
  code: "#ifndef is_prime_HPP\n#define is_prime_HPP\n\n#include <vector>\n\nclass\
    \ IsPrime {\nprivate:\n    int N;\n    std::vector<bool> is_prime_;\n    std::vector<int>\
    \ primes_;\n\npublic:\n    IsPrime(int N) : N(N), is_prime_(N + 1, true), primes_()\
    \ {\n        is_prime_[0] = is_prime_[1] = false;\n        \n        for (int\
    \ i = 2; i * i <= N; i++) {\n            if (!is_prime_[i]) {\n              \
    \  continue;\n            }\n            for (int j = i * i; j <= N; j += i) {\n\
    \                is_prime_[j] = false;\n            }\n        }\n\n        for\
    \ (int i = 2; i <= N; i++) {\n            if (is_prime_[i]) {\n              \
    \  primes_.push_back(i);\n            }\n        }\n    }\n\n    bool is_prime(int\
    \ x) {\n        return is_prime_[x];\n    }\n    const std::vector<int>& get_primes()\
    \ const& {\n        return primes_;\n    }\n};\n\n#endif // is_prime_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/is_prime.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/is_prime.hpp
layout: document
redirect_from:
- /library/Math/is_prime.hpp
- /library/Math/is_prime.hpp.html
title: Math/is_prime.hpp
---
