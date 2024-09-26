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
  bundledCode: "#line 1 \"Others/Monoids.hpp\"\n\n\n\n#include <cmath>\n#include </home/pomelo/ac-library/atcoder/modint>\n\
    \n// \u52A0\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct AddMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return 0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l + r;\n    }\n    static S inv(const\
    \ S& x){\n        return -x;\n    }\n};\n\n// \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T = atcoder::modint998244353>\nstruct MultiplyMonoid_998\
    \ {\n    using S = T;\n    static S e(){\n        return 1;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l * r;\n    }\n    static S inv(const\
    \ S& x){\n        return x.inv();\n    }\n};\n\n// \u639B\u7B97\u30E2\u30CE\u30A4\
    \u30C9\ntemplate <typename T = atcoder::modint1000000007>\nstruct MultiplyMonoid_100\
    \ {\n    using S = T;\n    static S e(){\n        return 1;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l * r;\n    }\n    static S inv(const\
    \ S& x){\n        return x.inv();\n    }\n};\n\n// \u6700\u5927\u5024\u30E2\u30CE\
    \u30A4\u30C9\ntemplate <typename T>\nstruct MaxMonoid {\n    using S = T;\n  \
    \  static S e(){\n        return std::numeric_limits<S>::min();\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return std::max(l, r);\n    }\n};\n\n\
    // \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct MinMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return std::numeric_limits<S>::max();\n\
    \    }\n    static S op(const S& l, const S& r){\n        return std::min(l, r);\n\
    \    }\n};\n\n// AND \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct AndMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return ~0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l & r;\n    }\n};\n\n// OR \u30E2\
    \u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct OrMonoid {\n    using S = T;\n\
    \    static S e(){\n        return 0;\n    }\n    static S op(const S& l, const\
    \ S& r){\n        return l | r;\n    }\n};\n\n// XOR \u30E2\u30CE\u30A4\u30C9\n\
    template <typename T>\nstruct XorMonoid {\n    using S = T;\n    static S e(){\n\
    \        return 0;\n    }\n    static S op(const S& l, const S& r){\n        return\
    \ l ^ r;\n    }\n    static S inv(const S& x){\n        return x;\n    }\n};\n\
    \n\n"
  code: "#ifndef Monoids_HPP\n#define Monoids_HPP\n\n#include <cmath>\n#include </home/pomelo/ac-library/atcoder/modint>\n\
    \n// \u52A0\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct AddMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return 0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l + r;\n    }\n    static S inv(const\
    \ S& x){\n        return -x;\n    }\n};\n\n// \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T = atcoder::modint998244353>\nstruct MultiplyMonoid_998\
    \ {\n    using S = T;\n    static S e(){\n        return 1;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l * r;\n    }\n    static S inv(const\
    \ S& x){\n        return x.inv();\n    }\n};\n\n// \u639B\u7B97\u30E2\u30CE\u30A4\
    \u30C9\ntemplate <typename T = atcoder::modint1000000007>\nstruct MultiplyMonoid_100\
    \ {\n    using S = T;\n    static S e(){\n        return 1;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l * r;\n    }\n    static S inv(const\
    \ S& x){\n        return x.inv();\n    }\n};\n\n// \u6700\u5927\u5024\u30E2\u30CE\
    \u30A4\u30C9\ntemplate <typename T>\nstruct MaxMonoid {\n    using S = T;\n  \
    \  static S e(){\n        return std::numeric_limits<S>::min();\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return std::max(l, r);\n    }\n};\n\n\
    // \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct MinMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return std::numeric_limits<S>::max();\n\
    \    }\n    static S op(const S& l, const S& r){\n        return std::min(l, r);\n\
    \    }\n};\n\n// AND \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct AndMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return ~0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l & r;\n    }\n};\n\n// OR \u30E2\
    \u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct OrMonoid {\n    using S = T;\n\
    \    static S e(){\n        return 0;\n    }\n    static S op(const S& l, const\
    \ S& r){\n        return l | r;\n    }\n};\n\n// XOR \u30E2\u30CE\u30A4\u30C9\n\
    template <typename T>\nstruct XorMonoid {\n    using S = T;\n    static S e(){\n\
    \        return 0;\n    }\n    static S op(const S& l, const S& r){\n        return\
    \ l ^ r;\n    }\n    static S inv(const S& x){\n        return x;\n    }\n};\n\
    \n#endif // Monoids_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/Monoids.hpp
  requiredBy: []
  timestamp: '2024-09-26 23:19:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Monoids.hpp
layout: document
redirect_from:
- /library/Others/Monoids.hpp
- /library/Others/Monoids.hpp.html
title: Others/Monoids.hpp
---
