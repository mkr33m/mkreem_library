---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E0B\u4F4D\u96C6\u5408\u65B9\u5411\u306E\u9AD8\u901F\u30BC\u30FC\
      \u30BF\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"Math/zeta_mobius.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <bit>\n\ntemplate <typename T>\n/**\n * @brief \u4E0B\u4F4D\u96C6\u5408\u65B9\
    \u5411\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\n * \u4E0B i \u6841\u304C\
    \ S \u306E\u4E0B\u4F4D\u96C6\u5408\u3067\u3001\u4E0B i \u6841\u4EE5\u5916\u304C\
    \ S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] + F_{i}[S - (1 << i)]\n * @remark\
    \ F_{i+1}[S - (1 << i)] == F_{i}[S - (1 << i)] \u3060\u304B\u3089\u3001in-place\
    \ \u306B\u66F4\u65B0\u53EF\u80FD\n */\nvoid subset_zeta_transform(std::vector<T>&\
    \ F) {\n    int N = 0, sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) ==\
    \ 0);\n    while ((1 << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i\
    \ < N; i++) {\n        for (int S = 0; S < (1 << N); S++) {\n            if (S\
    \ & (1 << i)) {\n                F[S] = F[S] + F[S - (1 << i)];\n            }\n\
    \        }\n    }\n}\n\ntemplate <typename T>\n/**\n * @brief \u4E0B\u4F4D\u96C6\
    \u5408\u65B9\u5411\u306E\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n * \u4E0B\
    \ i \u6841\u304C S \u306E\u4E0B\u4F4D\u96C6\u5408\u3067\u3001\u4E0B i \u6841\u4EE5\
    \u5916\u304C S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] - F_{i}[S - (1 <<\
    \ i)]\n */\nvoid subset_mobius_transform(std::vector<T>& F) {\n    int N = 0,\
    \ sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) == 0);\n    while ((1\
    \ << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i < N; i++) {\n    \
    \    for (int S = 0; S < (1 << N); S++) {\n            if (S & (1 << i)) {\n \
    \               F[S] = F[S] - F[S - (1 << i)];\n            }\n        }\n   \
    \ }\n}\n\ntemplate <typename T>\n/**\n * @brief \u4E0A\u4F4D\u96C6\u5408\u65B9\
    \u5411\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\n * \u4E0B i \u6841\u304C\
    \ S \u306E\u4E0A\u4F4D\u96C6\u5408\u3067\u3001\u4E0B i \u6841\u4EE5\u5916\u304C\
    \ S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] + F_{i}[S + (1 << i)]\n * @remark\
    \ F_{i+1}[S + (1 << i)] == F_{i}[S + (1 << i)] \u3060\u304B\u3089\u3001in-place\
    \ \u306B\u66F4\u65B0\u53EF\u80FD\n */\nvoid superset_zeta_transform(std::vector<T>&\
    \ F) {\n    int N = 0, sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) ==\
    \ 0);\n    while ((1 << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i\
    \ < N; i++) {\n        for (int S = 0; S < (1 << N); S++) {\n            if (!(S\
    \ & (1 << i))) {\n                F[S] = F[S] + F[S + (1 << i)];\n           \
    \ }\n        }\n    }\n}\n\ntemplate <typename T>\n/**\n * @brief \u4E0A\u4F4D\
    \u96C6\u5408\u65B9\u5411\u306E\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\
    \n * \u4E0B i \u6841\u304C S \u306E\u4E0A\u4F4D\u96C6\u5408\u3067\u3001\u4E0B\
    \ i \u6841\u4EE5\u5916\u304C S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] -\
    \ F_{i}[S + (1 << i)]\n */\nvoid superset_mobius_transform(std::vector<T>& F)\
    \ {\n    int N = 0, sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) == 0);\n\
    \    while ((1 << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i < N;\
    \ i++) {\n        for (int S = 0; S < (1 << N); S++) {\n            if (!(S &\
    \ (1 << i))) {\n                F[S] = F[S] - F[S + (1 << i)];\n            }\n\
    \        }\n    }\n} \n\n\n\n"
  code: "#ifndef ZETA_MOBIUS_HPP\n#define ZETA_MOBIUS_HPP\n\n#include <vector>\n#include\
    \ <bit>\n\ntemplate <typename T>\n/**\n * @brief \u4E0B\u4F4D\u96C6\u5408\u65B9\
    \u5411\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\n * \u4E0B i \u6841\u304C\
    \ S \u306E\u4E0B\u4F4D\u96C6\u5408\u3067\u3001\u4E0B i \u6841\u4EE5\u5916\u304C\
    \ S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] + F_{i}[S - (1 << i)]\n * @remark\
    \ F_{i+1}[S - (1 << i)] == F_{i}[S - (1 << i)] \u3060\u304B\u3089\u3001in-place\
    \ \u306B\u66F4\u65B0\u53EF\u80FD\n */\nvoid subset_zeta_transform(std::vector<T>&\
    \ F) {\n    int N = 0, sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) ==\
    \ 0);\n    while ((1 << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i\
    \ < N; i++) {\n        for (int S = 0; S < (1 << N); S++) {\n            if (S\
    \ & (1 << i)) {\n                F[S] = F[S] + F[S - (1 << i)];\n            }\n\
    \        }\n    }\n}\n\ntemplate <typename T>\n/**\n * @brief \u4E0B\u4F4D\u96C6\
    \u5408\u65B9\u5411\u306E\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n * \u4E0B\
    \ i \u6841\u304C S \u306E\u4E0B\u4F4D\u96C6\u5408\u3067\u3001\u4E0B i \u6841\u4EE5\
    \u5916\u304C S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] - F_{i}[S - (1 <<\
    \ i)]\n */\nvoid subset_mobius_transform(std::vector<T>& F) {\n    int N = 0,\
    \ sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) == 0);\n    while ((1\
    \ << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i < N; i++) {\n    \
    \    for (int S = 0; S < (1 << N); S++) {\n            if (S & (1 << i)) {\n \
    \               F[S] = F[S] - F[S - (1 << i)];\n            }\n        }\n   \
    \ }\n}\n\ntemplate <typename T>\n/**\n * @brief \u4E0A\u4F4D\u96C6\u5408\u65B9\
    \u5411\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\n * \u4E0B i \u6841\u304C\
    \ S \u306E\u4E0A\u4F4D\u96C6\u5408\u3067\u3001\u4E0B i \u6841\u4EE5\u5916\u304C\
    \ S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] + F_{i}[S + (1 << i)]\n * @remark\
    \ F_{i+1}[S + (1 << i)] == F_{i}[S + (1 << i)] \u3060\u304B\u3089\u3001in-place\
    \ \u306B\u66F4\u65B0\u53EF\u80FD\n */\nvoid superset_zeta_transform(std::vector<T>&\
    \ F) {\n    int N = 0, sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) ==\
    \ 0);\n    while ((1 << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i\
    \ < N; i++) {\n        for (int S = 0; S < (1 << N); S++) {\n            if (!(S\
    \ & (1 << i))) {\n                F[S] = F[S] + F[S + (1 << i)];\n           \
    \ }\n        }\n    }\n}\n\ntemplate <typename T>\n/**\n * @brief \u4E0A\u4F4D\
    \u96C6\u5408\u65B9\u5411\u306E\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\
    \n * \u4E0B i \u6841\u304C S \u306E\u4E0A\u4F4D\u96C6\u5408\u3067\u3001\u4E0B\
    \ i \u6841\u4EE5\u5916\u304C S \u306B\u4E00\u81F4\n * F_{i+1}[S] = F_{i}[S] -\
    \ F_{i}[S + (1 << i)]\n */\nvoid superset_mobius_transform(std::vector<T>& F)\
    \ {\n    int N = 0, sz = (int)F.size();\n    assert(sz && (sz & (sz - 1)) == 0);\n\
    \    while ((1 << N) < sz) {\n        N++;\n    }\n    for (int i = 0; i < N;\
    \ i++) {\n        for (int S = 0; S < (1 << N); S++) {\n            if (!(S &\
    \ (1 << i))) {\n                F[S] = F[S] - F[S + (1 << i)];\n            }\n\
    \        }\n    }\n} \n\n\n#endif // ZETA_MOBIUS_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/zeta_mobius.hpp
  requiredBy: []
  timestamp: '2025-11-23 17:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/zeta_mobius.hpp
layout: document
redirect_from:
- /library/Math/zeta_mobius.hpp
- /library/Math/zeta_mobius.hpp.html
title: "\u4E0B\u4F4D\u96C6\u5408\u65B9\u5411\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\
  \u63DB"
---
