---
title: UF_ComponentSum
documentation_of: //DataStructure/UF_ComponentSum.hpp
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

