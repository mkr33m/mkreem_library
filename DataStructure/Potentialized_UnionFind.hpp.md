---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\
      \u30E3\u30EB\u3092\u8FD4\u3059"
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"DataStructure/Potentialized_UnionFind.hpp\"\n\n\n\n/*\n\
    verify\nhttps://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\n*/\n\n#include <vector>\n\
    #include <cassert>\n#include <numeric>\n\ntemplate <typename Abel>\nstruct Potentialized_UnionFind\
    \ {\nprivate:\n    using S = typename Abel::S;\n    std::vector<int> parent;\n\
    \    std::vector<S> potential_from_parent; // \u89AA\u304B\u3089\u898B\u305F\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\n    std::vector<int> size_;\n\npublic:\n    Potentialized_UnionFind(int\
    \ N) : parent(N), potential_from_parent(N, Abel::e()), size_(N, 1) {\n       \
    \ std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    int root(int v){\n\
    \        static std::vector<int> tmp;\n        while(parent[v] != v){ // \u6839\
    \u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\n            tmp.push_back(v);\n  \
    \          v = parent[v];\n        }\n        int par = v;\n        while(!tmp.empty()){\n\
    \            int pos = tmp.back(); tmp.pop_back();\n            parent[pos] =\
    \ v; // \u7D4C\u8DEF\u5727\u7E2E\n            potential_from_parent[pos] = Abel::op(potential_from_parent[pos],\
    \ potential_from_parent[par]);\n            par = pos;\n        }\n        return\
    \ v;\n    }\n\n    bool same(int u, int v){\n        return root(u) == root(v);\n\
    \    }\n\n    /**\n     * @brief root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\n     */\n    S weight(int u){\n\
    \        root(u);\n        return potential_from_parent[u];\n    }\n\n    /**\n\
    \     * @param delta v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\n     */\n    bool merge(int u, int v, S delta){\n        int root_u\
    \ = root(u), root_v = root(v);\n        // root_v \u304B\u3089\u898B\u305F root_u\
    \ \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306B\u5909\u63DB\n        /*\n \
    \       v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \ -> w\n        v \u304B\u3089\u898B\u305F root_u \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB -> w -\uFF08root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\uFF09\n        root_u \u304B\u3089\u898B\u305F v \u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB -> w +\uFF08root_v \u304B\u3089\u898B\u305F v \u306E\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\uFF09\n        */\n        delta = Abel::op(delta,\
    \ weight(v));\n        delta = Abel::op(delta, Abel::inv(weight(u)));\n\n    \
    \    if(root_u == root_v){\n            return false;\n        }\n\n        if(size_[root_u]\
    \ > size_[root_v]){\n            std::swap(root_u, root_v); // \u30DE\u30FC\u30B8\
    \u30C6\u30AF\n            delta = Abel::inv(delta);\n            //delta = -delta;\n\
    \        }\n        size_[root_v] += size_[root_u];\n        parent[root_u] =\
    \ root_v;\n        potential_from_parent[root_u] = delta;\n        return true;\n\
    \    }\n\n    /**\n     * @brief v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\n     */\n    S weight(int u, int v){\n\
    \        assert(same(u, v));\n        return Abel::op(weight(u), Abel::inv(weight(v)));\n\
    \    }\n\n    int size(int v){\n        return size_[v];\n    }\n};\n\n\n"
  code: "#ifndef Potentialized_UnionFind_HPP\n#define Potentialized_UnionFind_HPP\n\
    \n/*\nverify\nhttps://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\n*/\n\n#include\
    \ <vector>\n#include <cassert>\n#include <numeric>\n\ntemplate <typename Abel>\n\
    struct Potentialized_UnionFind {\nprivate:\n    using S = typename Abel::S;\n\
    \    std::vector<int> parent;\n    std::vector<S> potential_from_parent; // \u89AA\
    \u304B\u3089\u898B\u305F\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\n    std::vector<int>\
    \ size_;\n\npublic:\n    Potentialized_UnionFind(int N) : parent(N), potential_from_parent(N,\
    \ Abel::e()), size_(N, 1) {\n        std::iota(parent.begin(), parent.end(), 0);\n\
    \    }\n\n    int root(int v){\n        static std::vector<int> tmp;\n       \
    \ while(parent[v] != v){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\n\
    \            tmp.push_back(v);\n            v = parent[v];\n        }\n      \
    \  int par = v;\n        while(!tmp.empty()){\n            int pos = tmp.back();\
    \ tmp.pop_back();\n            parent[pos] = v; // \u7D4C\u8DEF\u5727\u7E2E\n\
    \            potential_from_parent[pos] = Abel::op(potential_from_parent[pos],\
    \ potential_from_parent[par]);\n            par = pos;\n        }\n        return\
    \ v;\n    }\n\n    bool same(int u, int v){\n        return root(u) == root(v);\n\
    \    }\n\n    /**\n     * @brief root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\n     */\n    S weight(int u){\n\
    \        root(u);\n        return potential_from_parent[u];\n    }\n\n    /**\n\
    \     * @param delta v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\n     */\n    bool merge(int u, int v, S delta){\n        int root_u\
    \ = root(u), root_v = root(v);\n        // root_v \u304B\u3089\u898B\u305F root_u\
    \ \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306B\u5909\u63DB\n        /*\n \
    \       v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \ -> w\n        v \u304B\u3089\u898B\u305F root_u \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB -> w -\uFF08root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\uFF09\n        root_u \u304B\u3089\u898B\u305F v \u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB -> w +\uFF08root_v \u304B\u3089\u898B\u305F v \u306E\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\uFF09\n        */\n        delta = Abel::op(delta,\
    \ weight(v));\n        delta = Abel::op(delta, Abel::inv(weight(u)));\n\n    \
    \    if(root_u == root_v){\n            return false;\n        }\n\n        if(size_[root_u]\
    \ > size_[root_v]){\n            std::swap(root_u, root_v); // \u30DE\u30FC\u30B8\
    \u30C6\u30AF\n            delta = Abel::inv(delta);\n            //delta = -delta;\n\
    \        }\n        size_[root_v] += size_[root_u];\n        parent[root_u] =\
    \ root_v;\n        potential_from_parent[root_u] = delta;\n        return true;\n\
    \    }\n\n    /**\n     * @brief v \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\n     */\n    S weight(int u, int v){\n\
    \        assert(same(u, v));\n        return Abel::op(weight(u), Abel::inv(weight(v)));\n\
    \    }\n\n    int size(int v){\n        return size_[v];\n    }\n};\n\n#endif\
    \ // Potentialized_UnionFind_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Potentialized_UnionFind.hpp
  requiredBy: []
  timestamp: '2024-10-04 17:49:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Potentialized_UnionFind.hpp
layout: document
redirect_from:
- /library/DataStructure/Potentialized_UnionFind.hpp
- /library/DataStructure/Potentialized_UnionFind.hpp.html
title: "root_u \u304B\u3089\u898B\u305F u \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
  \u3092\u8FD4\u3059"
---
