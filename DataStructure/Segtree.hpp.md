---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/Segtree.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <functional>\n#include <iostream>\n\ntemplate <typename\
    \ Monoid>\nclass Segtree {\n\nusing T = typename Monoid::S;\nstd::vector<T> seg_;\
    \ // 1-indexed \u3067\u7BA1\u7406\nint N_;\nint seg_N_;\n\nusing F = std::function<bool(const\
    \ T&)>; // \u4E8C\u5206\u63A2\u7D22\u306E\u5224\u5B9A\u95A2\u6570\n\nint min_pow(int\
    \ N) const {\n    int res = 1;\n    while (res < N) {\n        res <<= 1;\n  \
    \  }\n    return res;\n}\n\nvoid update_node(int i) {\n    int left_child_idx\
    \ = i << 1;\n    int right_child_idx = (i << 1) + 1;\n    seg_[i] = Monoid::op(seg_[left_child_idx],\
    \ seg_[right_child_idx]);\n}\n\npublic:\n    Segtree(const std::vector<T>& data)\
    \ : N_(data.size()) {\n        seg_N_ = min_pow(N_);\n        seg_.assign(2 *\
    \ seg_N_, Monoid::e());\n\n        for (int i = 0; i < N_; i++) {\n          \
    \  seg_[seg_N_ + i] = data[i];\n        }\n        for (int i = seg_N_ - 1; i\
    \ >= 1; i--) {\n            update_node(i);\n        }\n    }\n    Segtree(int\
    \ N, T initial_value) : Segtree(std::vector<T>(N, initial_value)) {}\n    Segtree(int\
    \ N) : Segtree(std::vector<T>(N, T())) {}\n    Segtree() : seg_(), N_(0), seg_N_(0)\
    \ {}\n\n    void set(int i, T x) {\n        assert(0 <= i && i < N_);\n\n    \
    \    i += seg_N_;\n        seg_[i] = x;\n\n        while (i > 1) { // \u89AA\u3092\
    \u8FBF\u3063\u3066\u66F4\u65B0\u3057\u3066\u3044\u304F\n            i >>= 1;\n\
    \            update_node(i);\n        }\n    }\n\n    T prod(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= N_);\n\n        T left_val = Monoid::e(),\
    \ right_val = Monoid::e();\n        l += seg_N_, r += seg_N_;\n        while (l\
    \ < r) {\n            if (l & 1) {\n                // \u5947\u6570 -> \u8DB3\u3057\
    \u3066\u304B\u3089\u305A\u3089\u3059\n                left_val = Monoid::op(left_val,\
    \ seg_[l++]);\n            }\n            if (r & 1) { \n                // \u5076\
    \u6570 -> \u305A\u3089\u3057\u3066\u304B\u3089\u8DB3\u3059\uFF08\u958B\u533A\u9593\
    \u3060\u304B\u3089\uFF09\n                right_val = Monoid::op(seg_[--r], right_val);\n\
    \            }\n            \n            l >>= 1, r >>= 1;\n        }\n     \
    \   return Monoid::op(left_val, right_val);\n    }\n\n    T all_prod() const {\n\
    \        return seg_[1];\n    }\n\n    T get(int i) const {\n        assert(0\
    \ <= i && i < N_);\n\n        return seg_[seg_N_ + i];\n    }\n\n    template\
    \ <typename F>\n    int max_right(int l, const F& f) const {\n        assert(0\
    \ <= l && l < N_);\n        assert(f(Monoid::e()));\n\n        if (!f(seg_[l +\
    \ seg_N_])) { // r \u304C\u5B58\u5728\u3057\u306A\u3044\n            return l;\
    \ // (== r)\n        }\n\n        l += seg_N_;\n        T prod = Monoid::e();\n\
    \        int r = l;\n        int next_r = r + 1;\n\n        while (1) {\n    \
    \        if (!(next_r & 1)) { // \u5076\u6570\u306A\u3089\u3001\u89AA\u30CE\u30FC\
    \u30C9\u3078\n                next_r >>= 1;\n            }\n            T next_prod\
    \ = Monoid::op(prod, seg_[next_r]);\n            if (!f(next_prod)) {\n      \
    \          while (next_r < seg_N_ && !f(next_prod)) {\n                    next_r\
    \ <<= 1; // \u6761\u4EF6\u3092\u6E80\u305F\u3057\u3066\u304F\u308C\u308B\u307E\
    \u3067\u3001\u5DE6\u306E\u5B50\u3092\u8FBF\u3063\u3066\u3044\u304F\n         \
    \           next_prod = Monoid::op(prod, seg_[next_r]);\n                }\n \
    \               if (!f(next_prod)) {\n                    break;\n           \
    \     }\n            }\n            r = next_r; // r \u3092\u66F4\u65B0\n    \
    \        prod = next_prod; // prod \u3092\u66F4\u65B0\n            next_r = r\
    \ + 1; // \u6B21\u306E\u30CE\u30FC\u30C9\n\n            if ((next_r & (next_r\
    \ - 1)) == 0) { // 2 \u51AA\u306B\u306A\u3063\u305F\u3089\u7D42\u4E86\n      \
    \          break;\n            }\n        }\n\n        // r \u304C\u8449\u306B\
    \u305F\u3069\u308A\u7740\u304F\u307E\u3067\u6F5C\u3063\u3066\u3044\u304F\n   \
    \     while (r < seg_N_) {\n            r <<= 1;\n            r++;\n        }\n\
    \n        r -= seg_N_;\n\n        return r + 1; // \u958B\u533A\u9593\u306B\u623B\
    \u3059\n    }\n\n    template <typename F> \n    int min_left(int r, const F&\
    \ f) {\n        assert(0 <= r && r <= N_);\n        assert(f(Monoid::e()));\n\n\
    \        if (r == 0 || !f(seg_[r - 1 + seg_N_])) { // l \u304C\u5B58\u5728\u3057\
    \u306A\u3044\n            return r; // (== l)\n        }\n\n        r += seg_N_;\n\
    \        T prod = Monoid::e();\n        int l = r;\n        int next_l = l - 1;\n\
    \n        while (1) {\n            if (next_l & 1) { // \u5947\u6570\u306A\u3089\
    \u3001\u89AA\u30CE\u30FC\u30C9\u3078\n                next_l >>= 1;\n        \
    \    }\n            T next_prod = Monoid::op(prod, seg_[next_l]);\n          \
    \  if (!f(next_prod)) {\n                while (next_l < seg_N_ && !f(next_prod))\
    \ {\n                    next_l <<= 1; // \u6761\u4EF6\u3092\u6E80\u305F\u3057\
    \u3066\u304F\u308C\u308B\u307E\u3067\u3001\u53F3\u306E\u5B50\u3092\u8FBF\u3063\
    \u3066\u3044\u304F\n                    next_l++;\n                    next_prod\
    \ = Monoid::op(prod, seg_[next_l]);\n                }\n                if (!f(next_prod))\
    \ {\n                    break;\n                }\n            }\n          \
    \  l = next_l; // l \u3092\u66F4\u65B0\n            prod = next_prod; // prod\
    \ \u3092\u66F4\u65B0\n            next_l = l - 1; // \u6B21\u306E\u30CE\u30FC\u30C9\
    \n\n            if (((next_l + 1) & next_l) == 0) { // 2^n - 1 \u306E\u5F62\u306B\
    \u306A\u3063\u305F\u3089\u7D42\u4E86\n                break;\n            }\n\
    \        }\n\n        // r \u304C\u8449\u306B\u305F\u3069\u308A\u7740\u304F\u307E\
    \u3067\u6F5C\u3063\u3066\u3044\u304F\n        while (l < seg_N_) {\n         \
    \   l <<= 1;\n        }\n\n        l -= seg_N_;\n\n        return l; // \u958B\
    \u533A\u9593\u306B\u623B\u3059\n    }\n\n};\n\n\n"
  code: "#ifndef Segtree_HPP\n#define Segtree_HPP\n\n#include <vector>\n#include <cassert>\n\
    #include <functional>\n#include <iostream>\n\ntemplate <typename Monoid>\nclass\
    \ Segtree {\n\nusing T = typename Monoid::S;\nstd::vector<T> seg_; // 1-indexed\
    \ \u3067\u7BA1\u7406\nint N_;\nint seg_N_;\n\nusing F = std::function<bool(const\
    \ T&)>; // \u4E8C\u5206\u63A2\u7D22\u306E\u5224\u5B9A\u95A2\u6570\n\nint min_pow(int\
    \ N) const {\n    int res = 1;\n    while (res < N) {\n        res <<= 1;\n  \
    \  }\n    return res;\n}\n\nvoid update_node(int i) {\n    int left_child_idx\
    \ = i << 1;\n    int right_child_idx = (i << 1) + 1;\n    seg_[i] = Monoid::op(seg_[left_child_idx],\
    \ seg_[right_child_idx]);\n}\n\npublic:\n    Segtree(const std::vector<T>& data)\
    \ : N_(data.size()) {\n        seg_N_ = min_pow(N_);\n        seg_.assign(2 *\
    \ seg_N_, Monoid::e());\n\n        for (int i = 0; i < N_; i++) {\n          \
    \  seg_[seg_N_ + i] = data[i];\n        }\n        for (int i = seg_N_ - 1; i\
    \ >= 1; i--) {\n            update_node(i);\n        }\n    }\n    Segtree(int\
    \ N, T initial_value) : Segtree(std::vector<T>(N, initial_value)) {}\n    Segtree(int\
    \ N) : Segtree(std::vector<T>(N, T())) {}\n    Segtree() : seg_(), N_(0), seg_N_(0)\
    \ {}\n\n    void set(int i, T x) {\n        assert(0 <= i && i < N_);\n\n    \
    \    i += seg_N_;\n        seg_[i] = x;\n\n        while (i > 1) { // \u89AA\u3092\
    \u8FBF\u3063\u3066\u66F4\u65B0\u3057\u3066\u3044\u304F\n            i >>= 1;\n\
    \            update_node(i);\n        }\n    }\n\n    T prod(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= N_);\n\n        T left_val = Monoid::e(),\
    \ right_val = Monoid::e();\n        l += seg_N_, r += seg_N_;\n        while (l\
    \ < r) {\n            if (l & 1) {\n                // \u5947\u6570 -> \u8DB3\u3057\
    \u3066\u304B\u3089\u305A\u3089\u3059\n                left_val = Monoid::op(left_val,\
    \ seg_[l++]);\n            }\n            if (r & 1) { \n                // \u5076\
    \u6570 -> \u305A\u3089\u3057\u3066\u304B\u3089\u8DB3\u3059\uFF08\u958B\u533A\u9593\
    \u3060\u304B\u3089\uFF09\n                right_val = Monoid::op(seg_[--r], right_val);\n\
    \            }\n            \n            l >>= 1, r >>= 1;\n        }\n     \
    \   return Monoid::op(left_val, right_val);\n    }\n\n    T all_prod() const {\n\
    \        return seg_[1];\n    }\n\n    T get(int i) const {\n        assert(0\
    \ <= i && i < N_);\n\n        return seg_[seg_N_ + i];\n    }\n\n    template\
    \ <typename F>\n    int max_right(int l, const F& f) const {\n        assert(0\
    \ <= l && l < N_);\n        assert(f(Monoid::e()));\n\n        if (!f(seg_[l +\
    \ seg_N_])) { // r \u304C\u5B58\u5728\u3057\u306A\u3044\n            return l;\
    \ // (== r)\n        }\n\n        l += seg_N_;\n        T prod = Monoid::e();\n\
    \        int r = l;\n        int next_r = r + 1;\n\n        while (1) {\n    \
    \        if (!(next_r & 1)) { // \u5076\u6570\u306A\u3089\u3001\u89AA\u30CE\u30FC\
    \u30C9\u3078\n                next_r >>= 1;\n            }\n            T next_prod\
    \ = Monoid::op(prod, seg_[next_r]);\n            if (!f(next_prod)) {\n      \
    \          while (next_r < seg_N_ && !f(next_prod)) {\n                    next_r\
    \ <<= 1; // \u6761\u4EF6\u3092\u6E80\u305F\u3057\u3066\u304F\u308C\u308B\u307E\
    \u3067\u3001\u5DE6\u306E\u5B50\u3092\u8FBF\u3063\u3066\u3044\u304F\n         \
    \           next_prod = Monoid::op(prod, seg_[next_r]);\n                }\n \
    \               if (!f(next_prod)) {\n                    break;\n           \
    \     }\n            }\n            r = next_r; // r \u3092\u66F4\u65B0\n    \
    \        prod = next_prod; // prod \u3092\u66F4\u65B0\n            next_r = r\
    \ + 1; // \u6B21\u306E\u30CE\u30FC\u30C9\n\n            if ((next_r & (next_r\
    \ - 1)) == 0) { // 2 \u51AA\u306B\u306A\u3063\u305F\u3089\u7D42\u4E86\n      \
    \          break;\n            }\n        }\n\n        // r \u304C\u8449\u306B\
    \u305F\u3069\u308A\u7740\u304F\u307E\u3067\u6F5C\u3063\u3066\u3044\u304F\n   \
    \     while (r < seg_N_) {\n            r <<= 1;\n            r++;\n        }\n\
    \n        r -= seg_N_;\n\n        return r + 1; // \u958B\u533A\u9593\u306B\u623B\
    \u3059\n    }\n\n    template <typename F> \n    int min_left(int r, const F&\
    \ f) {\n        assert(0 <= r && r <= N_);\n        assert(f(Monoid::e()));\n\n\
    \        if (r == 0 || !f(seg_[r - 1 + seg_N_])) { // l \u304C\u5B58\u5728\u3057\
    \u306A\u3044\n            return r; // (== l)\n        }\n\n        r += seg_N_;\n\
    \        T prod = Monoid::e();\n        int l = r;\n        int next_l = l - 1;\n\
    \n        while (1) {\n            if (next_l & 1) { // \u5947\u6570\u306A\u3089\
    \u3001\u89AA\u30CE\u30FC\u30C9\u3078\n                next_l >>= 1;\n        \
    \    }\n            T next_prod = Monoid::op(prod, seg_[next_l]);\n          \
    \  if (!f(next_prod)) {\n                while (next_l < seg_N_ && !f(next_prod))\
    \ {\n                    next_l <<= 1; // \u6761\u4EF6\u3092\u6E80\u305F\u3057\
    \u3066\u304F\u308C\u308B\u307E\u3067\u3001\u53F3\u306E\u5B50\u3092\u8FBF\u3063\
    \u3066\u3044\u304F\n                    next_l++;\n                    next_prod\
    \ = Monoid::op(prod, seg_[next_l]);\n                }\n                if (!f(next_prod))\
    \ {\n                    break;\n                }\n            }\n          \
    \  l = next_l; // l \u3092\u66F4\u65B0\n            prod = next_prod; // prod\
    \ \u3092\u66F4\u65B0\n            next_l = l - 1; // \u6B21\u306E\u30CE\u30FC\u30C9\
    \n\n            if (((next_l + 1) & next_l) == 0) { // 2^n - 1 \u306E\u5F62\u306B\
    \u306A\u3063\u305F\u3089\u7D42\u4E86\n                break;\n            }\n\
    \        }\n\n        // r \u304C\u8449\u306B\u305F\u3069\u308A\u7740\u304F\u307E\
    \u3067\u6F5C\u3063\u3066\u3044\u304F\n        while (l < seg_N_) {\n         \
    \   l <<= 1;\n        }\n\n        l -= seg_N_;\n\n        return l; // \u958B\
    \u533A\u9593\u306B\u623B\u3059\n    }\n\n};\n\n#endif // Segtree_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Segtree.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Segtree.hpp
layout: document
redirect_from:
- /library/DataStructure/Segtree.hpp
- /library/DataStructure/Segtree.hpp.html
title: DataStructure/Segtree.hpp
---
