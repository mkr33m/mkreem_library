---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "[0, i) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374"
    links: []
  bundledCode: "#line 1 \"Others/cum1D.hpp\"\n\n\n\n#include <vector>\n\ntemplate\
    \ <typename M>\nstruct cum1D {\nprivate:\n    using T = typename M::S;\n    int\
    \ N;\n    std::vector<T> prefix_prod, suffix_prod;\n\npublic:\n    cum1D() = default;\n\
    \    cum1D(const std::vector<T>& vec) : N(vec.size()){\n        prefix_prod.resize(N\
    \ + 1, M::e());\n        suffix_prod.resize(N + 1, M::e());\n\n        for(int\
    \ i = 0; i < N; i++){\n            prefix_prod[i + 1] = M::op(prefix_prod[i],\
    \ vec[i]);\n        }\n        for(int i = N - 1; i >= 0; i--){\n            suffix_prod[i]\
    \ = M::op(vec[i], suffix_prod[i + 1]);\n        }\n    }\n\n    /**\n     * @brief\
    \ [0, i) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n    T pref(const int&\
    \ i) const {\n        return prefix_prod[i];\n    }\n\n    /**\n     * @brief\
    \ [i, N) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n    T suff(const int&\
    \ i) const {\n        return suffix_prod[i];\n    }\n\n    /**\n     * @brief\
    \ [l, r) \u3092\u9664\u3044\u305F\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n   \
    \ T prod_exclude(const int& l, const int& r) const {\n        return M::op(prefix_prod[l],\
    \ suffix_prod[r]);\n    }\n\n    /**\n     * @brief i \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u9664\u3044\u305F\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n    T prod_exclude(const\
    \ int& i) const {\n        return M::op(prefix_prod[i], suffix_prod[i + 1]);\n\
    \    }\n\n    /**\n     * @brief [l, r) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374\n\
    \     * @remark \u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u4E8C\u9805\u6F14\u7B97\
    \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n     */\n    T prod(const int&\
    \ l, const int& r) const {\n        return M::op(prefix_prod[r], M::inv(prefix_prod[l]));\n\
    \    }\n};\n\n\n"
  code: "#ifndef cum1D_HPP\n#define cum1D_HPP\n\n#include <vector>\n\ntemplate <typename\
    \ M>\nstruct cum1D {\nprivate:\n    using T = typename M::S;\n    int N;\n   \
    \ std::vector<T> prefix_prod, suffix_prod;\n\npublic:\n    cum1D() = default;\n\
    \    cum1D(const std::vector<T>& vec) : N(vec.size()){\n        prefix_prod.resize(N\
    \ + 1, M::e());\n        suffix_prod.resize(N + 1, M::e());\n\n        for(int\
    \ i = 0; i < N; i++){\n            prefix_prod[i + 1] = M::op(prefix_prod[i],\
    \ vec[i]);\n        }\n        for(int i = N - 1; i >= 0; i--){\n            suffix_prod[i]\
    \ = M::op(vec[i], suffix_prod[i + 1]);\n        }\n    }\n\n    /**\n     * @brief\
    \ [0, i) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n    T pref(const int&\
    \ i) const {\n        return prefix_prod[i];\n    }\n\n    /**\n     * @brief\
    \ [i, N) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n    T suff(const int&\
    \ i) const {\n        return suffix_prod[i];\n    }\n\n    /**\n     * @brief\
    \ [l, r) \u3092\u9664\u3044\u305F\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n   \
    \ T prod_exclude(const int& l, const int& r) const {\n        return M::op(prefix_prod[l],\
    \ suffix_prod[r]);\n    }\n\n    /**\n     * @brief i \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u9664\u3044\u305F\u7DCF\u7A4D\u3092\u8FD4\u5374\n     */\n    T prod_exclude(const\
    \ int& i) const {\n        return M::op(prefix_prod[i], suffix_prod[i + 1]);\n\
    \    }\n\n    /**\n     * @brief [l, r) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374\n\
    \     * @remark \u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u4E8C\u9805\u6F14\u7B97\
    \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n     */\n    T prod(const int&\
    \ l, const int& r) const {\n        return M::op(prefix_prod[r], M::inv(prefix_prod[l]));\n\
    \    }\n};\n\n#endif // cum1D_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/cum1D.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/cum1D.hpp
layout: document
redirect_from:
- /library/Others/cum1D.hpp
- /library/Others/cum1D.hpp.html
title: "[0, i) \u306E\u7DCF\u7A4D\u3092\u8FD4\u5374"
---
