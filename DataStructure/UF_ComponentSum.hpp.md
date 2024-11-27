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
    document_title: "u \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
      \ sum \u3068 v \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
      \ sum \u3092\u7D71\u5408\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"DataStructure/UF_ComponentSum.hpp\"\n\n\n\n#include <vector>\n\
    \n#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\n/*\nverify\n\u30FBhttps://judge.yosupo.jp/problem/unionfind\n\
    */\n\n#line 10 \"DataStructure/UnionFind.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n\nclass UnionFind {\nprivate:\n    int N_;\n    std::vector<int>\
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
    \n#line 7 \"DataStructure/UF_ComponentSum.hpp\"\n\n/**\n * @param T \u30E2\u30CE\
    \u30A4\u30C9\uFF08\u9023\u7D50\u6210\u5206\u304C\u6301\u3064\u60C5\u5831\uFF09\
    \u306E\u578B\n */\ntemplate <typename T>\nusing merge_function = void(*)(T& component_sum1,\
    \ T component_sum2);\n\n// \u578B\u5F15\u6570\u3001\u975E\u578B\u5F15\u6570\uFF08\
    \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u5B9A\u307E\u308B\u3082\u306E\u306B\
    \u9650\u308B\uFF09\ntemplate <typename T, merge_function<T> f>\nclass UF_ComponentSum\
    \ : public UnionFind { // \u7D99\u627F\n    std::vector<T> sum_;\n\npublic:\n\
    \    UF_ComponentSum() = default;\n    UF_ComponentSum(const std::vector<T>& init)\
    \ : \n        UnionFind((int)init.size()), sum_(init) {}\n\n    /**\n     * @brief\
    \ u \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E sum \u3068 v\
    \ \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E sum \u3092\u7D71\
    \u5408\u3059\u308B\n     */\n    bool merge(const int& u, const int& v) {\n  \
    \      int prev_root_u = root(u), prev_root_v = root(v);\n        bool merged\
    \ = UnionFind::merge(u, v);\n        if (merged) {\n            int root_u = root(u);\n\
    \            /*\n            merge \u5F8C\u3001\n            \u30FBprev_root_u\
    \ == root_u -> \u9023\u7D50\u5F8C\u306E\u6210\u5206\u306E\u6839\u306F prev_root_u\n\
    \            \u30FBprev_root_u != root_u -> \u9023\u7D50\u5F8C\u306E\u6210\u5206\
    \u306E\u6839\u306F prev_root_v\n            */\n            if (prev_root_u !=\
    \ root_u) {\n                f(sum_[prev_root_v], std::move(sum_[prev_root_u]));\n\
    \            } else {\n                f(sum_[prev_root_u], std::move(sum_[prev_root_v]));\n\
    \            }\n        }\n\n        return merged;\n    }\n\n    T sum(const\
    \ int& v) {\n        int root_v = root(v);\n        return sum_[root_v];\n   \
    \ }\n\n};\n\n\n"
  code: "#ifndef UF_ComponentSum_HPP\n#define UF_ComponentSum_HPP\n\n#include <vector>\n\
    \n#include \"UnionFind.hpp\"\n\n/**\n * @param T \u30E2\u30CE\u30A4\u30C9\uFF08\
    \u9023\u7D50\u6210\u5206\u304C\u6301\u3064\u60C5\u5831\uFF09\u306E\u578B\n */\n\
    template <typename T>\nusing merge_function = void(*)(T& component_sum1, T component_sum2);\n\
    \n// \u578B\u5F15\u6570\u3001\u975E\u578B\u5F15\u6570\uFF08\u30B3\u30F3\u30D1\u30A4\
    \u30EB\u6642\u306B\u5B9A\u307E\u308B\u3082\u306E\u306B\u9650\u308B\uFF09\ntemplate\
    \ <typename T, merge_function<T> f>\nclass UF_ComponentSum : public UnionFind\
    \ { // \u7D99\u627F\n    std::vector<T> sum_;\n\npublic:\n    UF_ComponentSum()\
    \ = default;\n    UF_ComponentSum(const std::vector<T>& init) : \n        UnionFind((int)init.size()),\
    \ sum_(init) {}\n\n    /**\n     * @brief u \u304C\u6240\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E sum \u3068 v \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E sum \u3092\u7D71\u5408\u3059\u308B\n     */\n    bool merge(const\
    \ int& u, const int& v) {\n        int prev_root_u = root(u), prev_root_v = root(v);\n\
    \        bool merged = UnionFind::merge(u, v);\n        if (merged) {\n      \
    \      int root_u = root(u);\n            /*\n            merge \u5F8C\u3001\n\
    \            \u30FBprev_root_u == root_u -> \u9023\u7D50\u5F8C\u306E\u6210\u5206\
    \u306E\u6839\u306F prev_root_u\n            \u30FBprev_root_u != root_u -> \u9023\
    \u7D50\u5F8C\u306E\u6210\u5206\u306E\u6839\u306F prev_root_v\n            */\n\
    \            if (prev_root_u != root_u) {\n                f(sum_[prev_root_v],\
    \ std::move(sum_[prev_root_u]));\n            } else {\n                f(sum_[prev_root_u],\
    \ std::move(sum_[prev_root_v]));\n            }\n        }\n\n        return merged;\n\
    \    }\n\n    T sum(const int& v) {\n        int root_v = root(v);\n        return\
    \ sum_[root_v];\n    }\n\n};\n\n#endif // UF_ComponentSum_HPP"
  dependsOn:
  - DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: DataStructure/UF_ComponentSum.hpp
  requiredBy: []
  timestamp: '2024-11-27 20:14:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UF_ComponentSum.hpp
layout: document
title: UF_ComponentSum
---

## 概要

連結成分に情報（sum）を持たせた上で、merge を行う。merge 後の連結成分の sum は、merge 前の 2 連結成分の sum を基に計算を行う。

## テンプレート引数
```cpp
template <typename T, merge_function<T> f>
```
連結成分に持たせる sum の型と、merge のときの sum の計算を行う関数を渡す。**T は可換でないといけない**。
また、**ラムダ関数をテンプレート引数として使用することはできない**ため、外部引数を渡すこと。

## コンストラクタ

```cpp
    UF_ComponentSum() = default;
    UF_ComponentSum(const std::vector<T>& init) : 
        UnionFind((int)init.size()), sum_(init) {}
```
各連結成分の sum の情報は、vector として保持しておくが、その初期値を引数として渡す。

## `merge_function`

```cpp
template <typename T>
using merge_function = void(*)(T& component_sum1, T component_sum2);
```

2 つの引数両方に、merge の計算のときのオペランド（つまり、被 merge 連結成分の sum）を渡す。第一引数の方の sum を、merge 後の連結成分の sum として再利用することに注意。

## 機能

### merge

```cpp
bool merge (const int& u, const int& v)
```
`u` の属する連結成分と `v` の属する連結成分を merge する。このとき、merge 後に生成される連結成分の sum も同時に計算する。

### sum
```cpp
T sum (const int& v) const 
```
`v` が属する連結成分の sum を返す。

