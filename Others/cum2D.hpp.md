---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "[i1, j1) * [i2, j2) \u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\
      \u308B"
    links: []
  bundledCode: "#line 1 \"Others/cum2D.hpp\"\n\n\n\n#include <vector>\n\n/**\n * @remark\
    \ \u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u4E8C\u9805\u6F14\u7B97\u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\n */\ntemplate <typename M>\nstruct cum2D\
    \ {\nprivate:\n    using T = typename M::S;\n    int H, W;\n    std::vector<std::vector<T>>\
    \ prefix_prod, suffix_prod;\n\npublic:\n    cum2D() = default;\n    cum2D(const\
    \ std::vector<std::vector<T>>& grid) : H(grid.size()), W(grid[0].size()) {\n \
    \       prefix_prod.resize(H + 1, std::vector<T>(W + 1, M::e()));\n        suffix_prod.resize(H\
    \ + 1, std::vector<T>(W + 1, M::e()));\n        for(int i = 0; i < H; i++){\n\
    \            for(int j = 0; j < W; j++){\n                prefix_prod[i + 1][j\
    \ + 1] = M::op( M::op( M::op( grid[i][j], prefix_prod[i][j + 1] ), prefix_prod[i\
    \ + 1][j] ), M::inv(prefix_prod[i][j]) );\n            }\n        }\n        for(int\
    \ i = H - 1; i >= 0; i--){\n            for(int j = W - 1; j >= 0; j--){\n   \
    \             suffix_prod[i][j] = M::op( M::op( M::op( grid[i][j], suffix_prod[i\
    \ + 1][j] ), suffix_prod[i][j + 1] ), M::inv(suffix_prod[i + 1][j + 1]) );\n \
    \           }\n        }\n    }\n\n    /**\n     * @brief [i1, j1) * [i2, j2)\
    \ \u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\n     */\n    T prod(const\
    \ int& i1, const int& j1, const int& i2, const int& j2){\n        if(i2 <= i1\
    \ || j2 <= j1){\n            return 0;\n        }\n        return M::op( M::op(\
    \ M::op( prefix_prod[i2][j2], M::inv(prefix_prod[i1][j2]) ), M::inv(prefix_prod[i2][j1])\
    \ ), prefix_prod[i1][j1] );\n    }\n\n    T pref(const int& i, const int& j){\n\
    \        return prefix_prod[i][j];\n    }\n\n    T suff(const int& i, const int&\
    \ j){\n        return suffix_prod[i][j];\n    }\n};\n\n\n\n"
  code: "#ifndef cum2D_HPP\n#define cum2D_HPP\n\n#include <vector>\n\n/**\n * @remark\
    \ \u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u4E8C\u9805\u6F14\u7B97\u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\n */\ntemplate <typename M>\nstruct cum2D\
    \ {\nprivate:\n    using T = typename M::S;\n    int H, W;\n    std::vector<std::vector<T>>\
    \ prefix_prod, suffix_prod;\n\npublic:\n    cum2D() = default;\n    cum2D(const\
    \ std::vector<std::vector<T>>& grid) : H(grid.size()), W(grid[0].size()) {\n \
    \       prefix_prod.resize(H + 1, std::vector<T>(W + 1, M::e()));\n        suffix_prod.resize(H\
    \ + 1, std::vector<T>(W + 1, M::e()));\n        for(int i = 0; i < H; i++){\n\
    \            for(int j = 0; j < W; j++){\n                prefix_prod[i + 1][j\
    \ + 1] = M::op( M::op( M::op( grid[i][j], prefix_prod[i][j + 1] ), prefix_prod[i\
    \ + 1][j] ), M::inv(prefix_prod[i][j]) );\n            }\n        }\n        for(int\
    \ i = H - 1; i >= 0; i--){\n            for(int j = W - 1; j >= 0; j--){\n   \
    \             suffix_prod[i][j] = M::op( M::op( M::op( grid[i][j], suffix_prod[i\
    \ + 1][j] ), suffix_prod[i][j + 1] ), M::inv(suffix_prod[i + 1][j + 1]) );\n \
    \           }\n        }\n    }\n\n    /**\n     * @brief [i1, j1) * [i2, j2)\
    \ \u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\n     */\n    T prod(const\
    \ int& i1, const int& j1, const int& i2, const int& j2){\n        if(i2 <= i1\
    \ || j2 <= j1){\n            return 0;\n        }\n        return M::op( M::op(\
    \ M::op( prefix_prod[i2][j2], M::inv(prefix_prod[i1][j2]) ), M::inv(prefix_prod[i2][j1])\
    \ ), prefix_prod[i1][j1] );\n    }\n\n    T pref(const int& i, const int& j){\n\
    \        return prefix_prod[i][j];\n    }\n\n    T suff(const int& i, const int&\
    \ j){\n        return suffix_prod[i][j];\n    }\n};\n\n\n#endif  // cum2D_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/cum2D.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/cum2D.hpp
layout: document
redirect_from:
- /library/Others/cum2D.hpp
- /library/Others/cum2D.hpp.html
title: "[i1, j1) * [i2, j2) \u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B"
---
