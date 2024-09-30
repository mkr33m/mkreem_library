---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/UnionFind.hpp
    title: DataStructure/UnionFind.hpp
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
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ DataStructure/UF_ComponentSum.hpp: line 6: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "#ifndef UF_ComponetSum_HPP\n#define UF_ComponentSum_HPP\n\n#include <vector>\n\
    \n#include \"UnionFind.hpp\"\n\n/**\n * @param T \u30E2\u30CE\u30A4\u30C9\uFF08\
    \u9023\u7D50\u6210\u5206\u304C\u6301\u3064\u60C5\u5831\uFF09\u306E\u578B\n */\n\
    template <typename T>\nusing merge_function = void(*)(T& parent_data, T child_data);\n\
    \ntemplate <typename T, merge_function<T> f>\nstruct UF_ComponentSum : UnionFind\
    \ {\nprivate:\n    std::vector<T> sum_;\n\npublic:\n    UF_ComponentSum() : UF_ComponentSum(0)\
    \ {}\n    UF_ComponentSum(int N, const T& init_value = T{}) : UF_ComponentSum(std::vector<T>(N,\
    \ init_value)) {}\n    UF_ComponentSum(const std::vector<T>& init_values) : UnionFind(init_values.size()),\
    \ sum_(init_values) {}\n\n    bool merge(int x, int y){\n        x = root(x),\
    \ y = root(y); // <- \u6839\n        bool res = UnionFind::merge(x, y);\n    \
    \    if(res){\n            if(root(x) == y) std::swap(x, y); // \u30DE\u30FC\u30B8\
    \u5F8C\u306E\u9023\u7D50\u6210\u5206\u306E\u6839\u304C x \u3068\u306A\u308B\u3088\
    \u3046\u8ABF\u6574\n            f(sum_[x], std::move(sum_[y]));\n        }\n \
    \       return res;\n    }\n\n    const T& sum(int x){\n        return sum_[root(x)];\n\
    \    }\n};\n\n#endif // UF_ComponentSum_HPP"
  dependsOn:
  - DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: DataStructure/UF_ComponentSum.hpp
  requiredBy: []
  timestamp: '2024-09-30 17:42:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UF_ComponentSum.hpp
layout: document
redirect_from:
- /library/DataStructure/UF_ComponentSum.hpp
- /library/DataStructure/UF_ComponentSum.hpp.html
title: DataStructure/UF_ComponentSum.hpp
---
