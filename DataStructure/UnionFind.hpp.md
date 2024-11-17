---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/UF_ComponentSum.hpp
    title: UF_ComponentSum
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\n/*\nverify\n\u30FB\
    https://judge.yosupo.jp/problem/unionfind\n*/\n\n#include <vector>\n#include <algorithm>\n\
    #include <numeric>\n\nclass UnionFind {\nprivate:\n    int N_;\n    std::vector<int>\
    \ parent_;\n    std::vector<int> size_;\n\npublic:\n    UnionFind() = default;\n\
    \    UnionFind(int N) : N_(N), parent_(N), size_(N, 1) {\n        std::iota(parent_.begin(),\
    \ parent_.end(), 0);\n    }\n\n    int root(int v){\n        static std::vector<int>\
    \ tmp;\n        while(parent_[v] != v){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\
    \u3044\u304F\n            tmp.push_back(v);\n            v = parent_[v];\n   \
    \     }\n        while(!tmp.empty()){ // \u7D4C\u8DEF\u5727\u7E2E\n          \
    \  parent_[tmp.back()] = v;\n            tmp.pop_back();\n        }\n        return\
    \ v;\n    }\n\n    bool same(int u, int v){\n        return root(u) == root(v);\n\
    \    }\n\n    bool merge(int u, int v){\n        int root_u = root(u), root_v\
    \ = root(v);\n\n        if(root_u == root_v){\n            return false; // \u6839\
    \u304C\u540C\u3058\u306A\u3089\u3001\u65E2\u306B\u540C\u3058\u96C6\u5408\n   \
    \     }\n\n        if(size_[root_u] < size_[root_v]){\n            std::swap(root_u,\
    \ root_v); // \u30DE\u30FC\u30B8\u30C6\u30AF\n        }\n        size_[root_u]\
    \ += size_[root_v];\n        parent_[root_v] = root_u;\n        return true;\n\
    \    }\n\n    int size(int v){\n        return size_[root(v)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups(){\n        std::vector<std::vector<int>> res(N_);\n        for(int i\
    \ = 0; i < N_; i++){\n            res[root(i)].push_back(i);\n        }\n    \
    \    res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>&\
    \ vec){ return vec.empty(); }), res.end());\n        return res;\n    }\n};\n\n\
    \n"
  code: "#ifndef UnionFind_HPP\n#define UnionFind_HPP\n\n/*\nverify\n\u30FBhttps://judge.yosupo.jp/problem/unionfind\n\
    */\n\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\nclass UnionFind\
    \ {\nprivate:\n    int N_;\n    std::vector<int> parent_;\n    std::vector<int>\
    \ size_;\n\npublic:\n    UnionFind() = default;\n    UnionFind(int N) : N_(N),\
    \ parent_(N), size_(N, 1) {\n        std::iota(parent_.begin(), parent_.end(),\
    \ 0);\n    }\n\n    int root(int v){\n        static std::vector<int> tmp;\n \
    \       while(parent_[v] != v){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\
    \n            tmp.push_back(v);\n            v = parent_[v];\n        }\n    \
    \    while(!tmp.empty()){ // \u7D4C\u8DEF\u5727\u7E2E\n            parent_[tmp.back()]\
    \ = v;\n            tmp.pop_back();\n        }\n        return v;\n    }\n\n \
    \   bool same(int u, int v){\n        return root(u) == root(v);\n    }\n\n  \
    \  bool merge(int u, int v){\n        int root_u = root(u), root_v = root(v);\n\
    \n        if(root_u == root_v){\n            return false; // \u6839\u304C\u540C\
    \u3058\u306A\u3089\u3001\u65E2\u306B\u540C\u3058\u96C6\u5408\n        }\n\n  \
    \      if(size_[root_u] < size_[root_v]){\n            std::swap(root_u, root_v);\
    \ // \u30DE\u30FC\u30B8\u30C6\u30AF\n        }\n        size_[root_u] += size_[root_v];\n\
    \        parent_[root_v] = root_u;\n        return true;\n    }\n\n    int size(int\
    \ v){\n        return size_[root(v)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups(){\n        std::vector<std::vector<int>> res(N_);\n        for(int i\
    \ = 0; i < N_; i++){\n            res[root(i)].push_back(i);\n        }\n    \
    \    res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>&\
    \ vec){ return vec.empty(); }), res.end());\n        return res;\n    }\n};\n\n\
    #endif // UnionFind_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.hpp
  requiredBy:
  - DataStructure/UF_ComponentSum.hpp
  timestamp: '2024-11-18 02:37:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.hpp
- /library/DataStructure/UnionFind.hpp.html
title: DataStructure/UnionFind.hpp
---
