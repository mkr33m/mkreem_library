---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\
      \u30E3\u30EB\u3092\u8FD4\u3059"
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"DataStructure/Potentialized_UnionFind.cpp\"\n\n\n\n/*\n\
    verify\nhttps://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\n*/\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <typename Abel>\nstruct Potentialized_UnionFind\
    \ {\nprivate:\n    using S = typename Abel::S;\n    std::vector<int> parent;\n\
    \    std::vector<Abel> potential_from_parent; // \u89AA\u304B\u3089\u898B\u305F\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\n    std::vector<int> size;\n\npublic:\n\
    \    Potentialized_UnionFind(int N) : parent(N), potential_from_parent(N, Abel::e()),\
    \ size(N, 1) {\n        for(int i = 0; i < N; i++){\n            parent[i] = i;\n\
    \        }\n    }\n\n    int root(int v){\n        if(parent[v] == v){\n     \
    \       return v;\n        }\n        static std::vector<int> tmp;\n        while(parent[v]\
    \ != v){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\n            tmp.push_back(v);\n\
    \            potential_from_parent[v] = Abel::op(potential_from_parent[v], potential_from_parent[parent[v]]);\n\
    \            v = parent[v];\n        }\n        while(!tmp.empty()){ // \u7D4C\
    \u8DEF\u5727\u7E2E\n            parent[tmp.back()] = v;\n            tmp.pop_back();\n\
    \        }\n        return v;\n    }\n\n    /**\n     * @param delta v \u304B\u3089\
    \u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\n     */\n    bool merge(int\
    \ u, int v, const S& delta){\n        int root_u = root(u), root_v = root(v);\n\
    \n        if(root_u == root_v){\n            return false;\n        }\n\n    \
    \    if(size[root_u] < size[root_v]){\n            std::swap(root_u, root_v);\
    \ // \u30DE\u30FC\u30B8\u30C6\u30AF\n        }\n        parent[root_v] = root_u;\n\
    \        /**\n         * @param new_weight \n         */\n        /*\n       \
    \ \u91CD\u307F u - \u91CD\u307F v == delta\n        \u91CD\u307F u - \u91CD\u307F\
    \ ru == pfp u\n        \u91CD\u307F v - \u91CD\u307F rv == pfp v\n        \u3059\
    \u306A\u308F\u3061\u3001\n        new_weight = \u91CD\u307F u - \u91CD\u307F v\
    \ + delta\n        */\n        S new_weight = Abel::op(potential_from_parent[u],\
    \ Abel::inverse(potential_from_parent[v]));\n        new_weight = Abel::op(new_weight,\
    \ delta);\n        size[root_u] += size[root_v];\n        return true;\n    }\n\
    \n    bool same(int u, int v){\n        return root(u) == root(v);\n    }\n\n\
    \    /**\n     * @brief root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3092\u8FD4\u3059\n     */\n    S weight_to_root(int u){\n\
    \        root(u);\n        return potential_from_parent[u];\n    }\n\n    /**\n\
    \     * @brief v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u3092\u8FD4\u3059\n     */\n    S weight_between(int u, int v){\n     \
    \   assert(same(u, v));\n        return Abel::op(potential_from_parent(u), Abel::inv(potential_from_parent[v]));\n\
    \    }\n};\n\n\n"
  code: "#ifndef Potentialized_UnionFind_HPP\n#define Potentialized_UnionFind_HPP\n\
    \n/*\nverify\nhttps://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\n*/\n\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate <typename Abel>\nstruct Potentialized_UnionFind\
    \ {\nprivate:\n    using S = typename Abel::S;\n    std::vector<int> parent;\n\
    \    std::vector<Abel> potential_from_parent; // \u89AA\u304B\u3089\u898B\u305F\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\n    std::vector<int> size;\n\npublic:\n\
    \    Potentialized_UnionFind(int N) : parent(N), potential_from_parent(N, Abel::e()),\
    \ size(N, 1) {\n        for(int i = 0; i < N; i++){\n            parent[i] = i;\n\
    \        }\n    }\n\n    int root(int v){\n        if(parent[v] == v){\n     \
    \       return v;\n        }\n        static std::vector<int> tmp;\n        while(parent[v]\
    \ != v){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\n            tmp.push_back(v);\n\
    \            potential_from_parent[v] = Abel::op(potential_from_parent[v], potential_from_parent[parent[v]]);\n\
    \            v = parent[v];\n        }\n        while(!tmp.empty()){ // \u7D4C\
    \u8DEF\u5727\u7E2E\n            parent[tmp.back()] = v;\n            tmp.pop_back();\n\
    \        }\n        return v;\n    }\n\n    /**\n     * @param delta v \u304B\u3089\
    \u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\n     */\n    bool merge(int\
    \ u, int v, const S& delta){\n        int root_u = root(u), root_v = root(v);\n\
    \n        if(root_u == root_v){\n            return false;\n        }\n\n    \
    \    if(size[root_u] < size[root_v]){\n            std::swap(root_u, root_v);\
    \ // \u30DE\u30FC\u30B8\u30C6\u30AF\n        }\n        parent[root_v] = root_u;\n\
    \        /**\n         * @param new_weight \n         */\n        /*\n       \
    \ \u91CD\u307F u - \u91CD\u307F v == delta\n        \u91CD\u307F u - \u91CD\u307F\
    \ ru == pfp u\n        \u91CD\u307F v - \u91CD\u307F rv == pfp v\n        \u3059\
    \u306A\u308F\u3061\u3001\n        new_weight = \u91CD\u307F u - \u91CD\u307F v\
    \ + delta\n        */\n        S new_weight = Abel::op(potential_from_parent[u],\
    \ Abel::inverse(potential_from_parent[v]));\n        new_weight = Abel::op(new_weight,\
    \ delta);\n        size[root_u] += size[root_v];\n        return true;\n    }\n\
    \n    bool same(int u, int v){\n        return root(u) == root(v);\n    }\n\n\
    \    /**\n     * @brief root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3092\u8FD4\u3059\n     */\n    S weight_to_root(int u){\n\
    \        root(u);\n        return potential_from_parent[u];\n    }\n\n    /**\n\
    \     * @brief v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u3092\u8FD4\u3059\n     */\n    S weight_between(int u, int v){\n     \
    \   assert(same(u, v));\n        return Abel::op(potential_from_parent(u), Abel::inv(potential_from_parent[v]));\n\
    \    }\n};\n\n#endif // Potentialized_UnionFind_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Potentialized_UnionFind.cpp
  requiredBy: []
  timestamp: '2024-09-30 17:42:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Potentialized_UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/Potentialized_UnionFind.cpp
- /library/DataStructure/Potentialized_UnionFind.cpp.html
title: "root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
  \u3092\u8FD4\u3059"
---
