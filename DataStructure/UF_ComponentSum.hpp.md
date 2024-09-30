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
  bundledCode: "#line 1 \"DataStructure/UF_ComponentSum.hpp\"\n\n\n\n#include <vector>\n\
    \n#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\n/*\nverify\n\u30FBhttps://judge.yosupo.jp/problem/unionfind\n\
    */\n\n#line 10 \"DataStructure/UnionFind.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n\nstruct UnionFind {\nprivate:\n    int N;\n    std::vector<int>\
    \ parent;\n    std::vector<int> size_;\n\npublic:\n    UnionFind() = default;\n\
    \    UnionFind(int N) : N(N), parent(N), size_(N, 1) {\n        std::iota(parent.begin(),\
    \ parent.end(), 0);\n    }\n\n    int root(int v){\n        static std::vector<int>\
    \ tmp;\n        while(parent[v] != v){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\
    \u3044\u304F\n            tmp.push_back(v);\n            v = parent[v];\n    \
    \    }\n        while(!tmp.empty()){ // \u7D4C\u8DEF\u5727\u7E2E\n           \
    \ parent[tmp.back()] = v;\n            tmp.pop_back();\n        }\n        return\
    \ v;\n    }\n\n    bool same(int u, int v){\n        return root(u) == root(v);\n\
    \    }\n\n    bool merge(int u, int v){\n        int root_u = root(u), root_v\
    \ = root(v);\n\n        if(root_u == root_v){\n            return false; // \u6839\
    \u304C\u540C\u3058\u306A\u3089\u3001\u65E2\u306B\u540C\u3058\u96C6\u5408\n   \
    \     }\n\n        if(size_[root_u] < size_[root_v]){\n            std::swap(root_u,\
    \ root_v); // \u30DE\u30FC\u30B8\u30C6\u30AF\n        }\n        size_[root_u]\
    \ += size_[root_v];\n        parent[root_v] = root_u;\n        return true;\n\
    \    }\n\n    int size(int v){\n        return size_[root(v)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups(){\n        std::vector<std::vector<int>> res(N);\n        for(int i\
    \ = 0; i < N; i++){\n            res[root(i)].push_back(i);\n        }\n     \
    \   res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>&\
    \ vec){ return vec.empty(); }), res.end());\n        return res;\n    }\n};\n\n\
    \n#line 7 \"DataStructure/UF_ComponentSum.hpp\"\n\n/**\n * @param T \u30E2\u30CE\
    \u30A4\u30C9\uFF08\u9023\u7D50\u6210\u5206\u304C\u6301\u3064\u60C5\u5831\uFF09\
    \u306E\u578B\n */\ntemplate <typename T>\nusing merge_function = void(*)(T& parent_data,\
    \ T child_data);\n\ntemplate <typename T, merge_function<T> f>\nstruct UF_ComponentSum\
    \ : UnionFind {\nprivate:\n    std::vector<T> sum_;\n\npublic:\n    UF_ComponentSum()\
    \ : UF_ComponentSum(0) {}\n    UF_ComponentSum(int N, const T& init_value = T{})\
    \ : UF_ComponentSum(std::vector<T>(N, init_value)) {}\n    UF_ComponentSum(const\
    \ std::vector<T>& init_values) : UnionFind(init_values.size()), sum_(init_values)\
    \ {}\n\n    bool merge(int x, int y){\n        x = root(x), y = root(y); // <-\
    \ \u6839\n        bool res = UnionFind::merge(x, y);\n        if(res){\n     \
    \       if(root(x) == y) std::swap(x, y); // \u30DE\u30FC\u30B8\u5F8C\u306E\u9023\
    \u7D50\u6210\u5206\u306E\u6839\u304C x \u3068\u306A\u308B\u3088\u3046\u8ABF\u6574\
    \n            f(sum_[x], std::move(sum_[y]));\n        }\n        return res;\n\
    \    }\n\n    const T& sum(int x){\n        return sum_[root(x)];\n    }\n};\n\
    \n\n"
  code: "#ifndef UF_ComponentSum_HPP\n#define UF_ComponentSum_HPP\n\n#include <vector>\n\
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
  timestamp: '2024-09-30 23:45:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UF_ComponentSum.hpp
layout: document
redirect_from:
- /library/DataStructure/UF_ComponentSum.hpp
- /library/DataStructure/UF_ComponentSum.hpp.html
title: DataStructure/UF_ComponentSum.hpp
---
