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
    #include <cassert>\n\n#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\n/*\nverify\n\
    \u30FBhttps://judge.yosupo.jp/problem/unionfind\n*/\n\n#line 10 \"DataStructure/UnionFind.hpp\"\
    \n#include <algorithm>\n#include <numeric>\n\nclass UnionFind {\nprivate:\n  \
    \  int N_;\n    std::vector<int> parent_;\n    std::vector<int> size_;\n\npublic:\n\
    \    UnionFind() = default;\n    UnionFind(int N) : N_(N), parent_(N), size_(N,\
    \ 1) {\n        std::iota(parent_.begin(), parent_.end(), 0);\n    }\n\n    int\
    \ root(int v) {\n        static std::vector<int> tmp;\n        while (parent_[v]\
    \ != v) { // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\n            tmp.push_back(v);\n\
    \            v = parent_[v];\n        }\n        while (!tmp.empty()) { // \u7D4C\
    \u8DEF\u5727\u7E2E\n            parent_[tmp.back()] = v;\n            tmp.pop_back();\n\
    \        }\n        return v;\n    }\n\n    bool same(int u, int v) {\n      \
    \  return root(u) == root(v);\n    }\n\n    int merge(int u, int v) {\n      \
    \  int root_u = root(u), root_v = root(v);\n\n        if (root_u == root_v) {\n\
    \            return root_u; // \u6839\u304C\u540C\u3058\u306A\u3089\u3001\u65E2\
    \u306B\u540C\u3058\u96C6\u5408\n        }\n\n        if (size_[root_u] < size_[root_v])\
    \ {\n            std::swap(root_u, root_v);\n        }\n        size_[root_u]\
    \ += size_[root_v];\n        parent_[root_v] = root_u;\n        return root_u;\n\
    \    }\n\n    int size(int v) {\n        return size_[root(v)];\n    }\n\n   \
    \ std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(N_);\n        for (int i = 0; i < N_; i++) {\n            res[root(i)].push_back(i);\n\
    \        }\n        res.erase(std::remove_if(res.begin(), res.end(), [](const\
    \ std::vector<int>& vec){ return vec.empty(); }), res.end());\n        return\
    \ res;\n    }\n};\n\n\n#line 8 \"DataStructure/UF_ComponentSum.hpp\"\n\ntemplate\
    \ <typename Op>\nclass UF_ComponentSum : public UnionFind { // \u7D99\u627F\n\
    \    int N; // \u9802\u70B9\u6570\n    Op op;\n\npublic:\n                   \
    \                                          // UF \u3092\u521D\u671F\u5316\n  \
    \  UF_ComponentSum(int N, const Op& op) : N(N), op(op), UnionFind(N) {}\n\n  \
    \  bool merge(int u, int v) { // \u4E0A\u66F8\u304D\n        int ru = root(u),\
    \ rv = root(v);\n        int r = UnionFind::merge(u, v);\n        bool merged\
    \ = (r != ru) || (r != rv);\n        if (merged) {\n            if (r == ru) {\n\
    \                op(r, rv);\n            } else { // r == pv\n               \
    \ op(r, ru);\n            }\n        }\n        return merged;\n    }\n};\n\n\n"
  code: "#ifndef UF_ComponentSum_HPP\n#define UF_ComponentSum_HPP\n\n#include <vector>\n\
    #include <cassert>\n\n#include \"UnionFind.hpp\"\n\ntemplate <typename Op>\nclass\
    \ UF_ComponentSum : public UnionFind { // \u7D99\u627F\n    int N; // \u9802\u70B9\
    \u6570\n    Op op;\n\npublic:\n                                              \
    \               // UF \u3092\u521D\u671F\u5316\n    UF_ComponentSum(int N, const\
    \ Op& op) : N(N), op(op), UnionFind(N) {}\n\n    bool merge(int u, int v) { //\
    \ \u4E0A\u66F8\u304D\n        int ru = root(u), rv = root(v);\n        int r =\
    \ UnionFind::merge(u, v);\n        bool merged = (r != ru) || (r != rv);\n   \
    \     if (merged) {\n            if (r == ru) {\n                op(r, rv);\n\
    \            } else { // r == pv\n                op(r, ru);\n            }\n\
    \        }\n        return merged;\n    }\n};\n\n#endif // UF_ComponentSum_HPP"
  dependsOn:
  - DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: DataStructure/UF_ComponentSum.hpp
  requiredBy: []
  timestamp: '2025-05-27 22:26:13+09:00'
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

