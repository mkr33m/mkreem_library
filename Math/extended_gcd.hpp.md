---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/binom_mod_ll.cpp
    title: "a \u306E mod m \u306B\u304A\u3051\u308B\u9006\u5143 x \u3092\u6C42\u3081\
      \u308B"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "a * x + b * y == gcd(a, b)\u3092\u6E80\u305F\u3059 x, y \u3092\
      \u898B\u3064\u3051\u308B"
    links: []
  bundledCode: "#line 1 \"Math/extended_gcd.hpp\"\n\n\n\n/**\n * @brief a * x + b\
    \ * y == gcd(a, b)\u3092\u6E80\u305F\u3059 x, y \u3092\u898B\u3064\u3051\u308B\
    \n * @return gcd(a, b)\n * x \u304C a \u306E\u9006\u5143\u306B\u76F8\u5F53\n */\n\
    long long extended_gcd(long long a, long long b, long long &x, long long &y){\n\
    \    /*\n    a * x0 + b * y0 == gcd(a, b)\n    -> b * x1 + r * b1 == gcd(a, b)\n\
    \    -> ...\n    -> gcd(a, b) * xn + 0 * yn == gcd(a, b)\n    */\n    if(b ==\
    \ 0){\n        x = 1;\n        y = 0;\n        return a;\n    }\n    long long\
    \ nx, ny;\n    long long gcd = extended_gcd(b, a % b, nx, ny);\n    // \u5E30\u308A\
    \u304C\u3051\u306B\u4FC2\u6570\u3092\u66F4\u65B0\n    x = ny;\n    y = nx - (a\
    \ / b) * ny;\n    return gcd;\n}\n\n\n"
  code: "#ifndef H_extended_gcd\n#define H_extended_gcd\n\n/**\n * @brief a * x +\
    \ b * y == gcd(a, b)\u3092\u6E80\u305F\u3059 x, y \u3092\u898B\u3064\u3051\u308B\
    \n * @return gcd(a, b)\n * x \u304C a \u306E\u9006\u5143\u306B\u76F8\u5F53\n */\n\
    long long extended_gcd(long long a, long long b, long long &x, long long &y){\n\
    \    /*\n    a * x0 + b * y0 == gcd(a, b)\n    -> b * x1 + r * b1 == gcd(a, b)\n\
    \    -> ...\n    -> gcd(a, b) * xn + 0 * yn == gcd(a, b)\n    */\n    if(b ==\
    \ 0){\n        x = 1;\n        y = 0;\n        return a;\n    }\n    long long\
    \ nx, ny;\n    long long gcd = extended_gcd(b, a % b, nx, ny);\n    // \u5E30\u308A\
    \u304C\u3051\u306B\u4FC2\u6570\u3092\u66F4\u65B0\n    x = ny;\n    y = nx - (a\
    \ / b) * ny;\n    return gcd;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/extended_gcd.hpp
  requiredBy:
  - Math/binom_mod_ll.cpp
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/extended_gcd.hpp
layout: document
redirect_from:
- /library/Math/extended_gcd.hpp
- /library/Math/extended_gcd.hpp.html
title: "a * x + b * y == gcd(a, b)\u3092\u6E80\u305F\u3059 x, y \u3092\u898B\u3064\
  \u3051\u308B"
---