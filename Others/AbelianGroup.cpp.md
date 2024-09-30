---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: /home/pomelo/github.com/mkreem_library/ac-library/atcoder/modint.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef AbelianGroup_HPP\n#define AbelianGroup_HPP\n\n/**\n * \u4FDD\u8A3C\
    \u3055\u308C\u308B\u4EE3\u6570\u7684\u69CB\u9020\n * \u30FB\u7D50\u5408\u6CD5\u5247\
    \n * \u30FB\u5358\u4F4D\u5143\u306E\u5B58\u5728\n * \u30FB\u9006\u5143\u306E\u5B58\
    \u5728\n * \u30FB\u53EF\u63DB\u6027\n */\n\n#include <cmath>\n\n#include \"/home/pomelo/github.com/mkreem_library/ac-library/atcoder/modint.hpp\"\
    \n#ifndef ATCODER_MODINT_HPP\n#define ATCODER_MODINT_HPP // <- #include <ac-library/all>\
    \ \u3057\u305F\u3068\u304D\u306B\u91CD\u8907\u3057\u3066\u3057\u307E\u3046\u304B\
    \u3089\u5FC5\u9808\n#endif\n\n// \u52A0\u7B97\u7FA4\ntemplate <typename T>\nstruct\
    \ AdditiveMonoid {\n    using S = T;\n    static S e(){\n        return 0;\n \
    \   }\n    static S op(const S& l, const S& r){\n        return l + r;\n    }\n\
    \    static S inv(const S& x){\n        return -x;\n    }\n};\n\n// \u4E57\u7B97\
    \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T = atcoder::modint998244353>\nstruct\
    \ MultiplicativeMonoid_998 {\n    using S = T;\n    static S e(){\n        return\
    \ 1;\n    }\n    static S op(const S& l, const S& r){\n        return l * r;\n\
    \    }\n    static S inv(const S& x){\n        return x.inv();\n    }\n};\n\n\
    // \u4E57\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T = atcoder::modint1000000007>\n\
    struct MultiplicativeGroup_100 {\n    using S = T;\n    static S e(){\n      \
    \  return 1;\n    }\n    static S op(const S& l, const S& r){\n        return\
    \ l * r;\n    }\n    static S inv(const S& x){\n        return x.inv();\n    }\n\
    };\n\n// XOR \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct XorMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return 0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l ^ r;\n    }\n    static S inv(const\
    \ S& x){\n        return x;\n    }\n};\n\n\n#endif // AbelianGroup_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/AbelianGroup.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/AbelianGroup.cpp
layout: document
redirect_from:
- /library/Others/AbelianGroup.cpp
- /library/Others/AbelianGroup.cpp.html
title: Others/AbelianGroup.cpp
---
