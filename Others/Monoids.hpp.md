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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: /home/pomelo/ac-library/atcoder/modint:\
    \ line -1: no such header\n"
  code: "#ifndef Monoids_HPP\n#define Monoids_HPP\n\n#include <cmath>\n#include \"\
    /home/pomelo/ac-library/atcoder/modint\"\n\n// \u52A0\u7B97\u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T>\nstruct AddMonoid {\n    using S = T;\n    static S e(){\n\
    \        return 0;\n    }\n    static S op(const S& l, const S& r){\n        return\
    \ l + r;\n    }\n    static S inv(const S& x){\n        return -x;\n    }\n};\n\
    \n// \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T = atcoder::modint998244353>\n\
    struct MultiplyMonoid_998 {\n    using S = T;\n    static S e(){\n        return\
    \ 1;\n    }\n    static S op(const S& l, const S& r){\n        return l * r;\n\
    \    }\n    static S inv(const S& x){\n        return x.inv();\n    }\n};\n\n\
    // \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T = atcoder::modint1000000007>\n\
    struct MultiplyMonoid_100 {\n    using S = T;\n    static S e(){\n        return\
    \ 1;\n    }\n    static S op(const S& l, const S& r){\n        return l * r;\n\
    \    }\n    static S inv(const S& x){\n        return x.inv();\n    }\n};\n\n\
    // \u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct MaxMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return std::numeric_limits<S>::min();\n\
    \    }\n    static S op(const S& l, const S& r){\n        return std::max(l, r);\n\
    \    }\n};\n\n// \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename\
    \ T>\nstruct MinMonoid {\n    using S = T;\n    static S e(){\n        return\
    \ std::numeric_limits<S>::max();\n    }\n    static S op(const S& l, const S&\
    \ r){\n        return std::min(l, r);\n    }\n};\n\n// AND \u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T>\nstruct AndMonoid {\n    using S = T;\n    static S e(){\n\
    \        return ~0;\n    }\n    static S op(const S& l, const S& r){\n       \
    \ return l & r;\n    }\n};\n\n// OR \u30E2\u30CE\u30A4\u30C9\ntemplate <typename\
    \ T>\nstruct OrMonoid {\n    using S = T;\n    static S e(){\n        return 0;\n\
    \    }\n    static S op(const S& l, const S& r){\n        return l | r;\n    }\n\
    };\n\n// XOR \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct XorMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return 0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l ^ r;\n    }\n    static S inv(const\
    \ S& x){\n        return x;\n    }\n};\n\n#endif // Monoids_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/Monoids.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Monoids.hpp
layout: document
redirect_from:
- /library/Others/Monoids.hpp
- /library/Others/Monoids.hpp.html
title: Others/Monoids.hpp
---
