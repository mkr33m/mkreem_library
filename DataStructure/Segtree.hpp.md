---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "seg[i] = x  \u914D\u5217\u306E i \u756A\u76EE\u306B\u5BFE\u5FDC\
      \u3059\u308B\u30CE\u30FC\u30C9\u3092 x \u3067\u30BB\u30C3\u30C8\u3057\u3001\u4E0A\
      \u306B\u3042\u308B\u30CE\u30FC\u30C9\u3092\u66F4\u65B0"
    links: []
  bundledCode: "#line 1 \"DataStructure/Segtree.hpp\"\n\n\n\n#include <vector>\n\n\
    template <typename Monoid>\nstruct Segtree {\nprivate:\n    /**\n     * @param\
    \ seg \u30BB\u30B0\u6728\n     * @param siz \u7BA1\u7406\u3059\u308B vector \u306E\
    \u30B5\u30A4\u30BA\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA\uFF08\u8449\u306E\
    \u6570\uFF09\n     * @param N vector \u306E\u30B5\u30A4\u30BA\n     */\n    using\
    \ T = typename Monoid::S;\n    std::vector<T> seg;\n    int N;\n    int siz =\
    \ 1;\n\n    struct Reference {\n        Segtree& seg_ref;\n        int index;\n\
    \n        Reference(Segtree& seg_ref, int index) : seg_ref(seg_ref), index(index)\
    \ {}\n\n        Reference& operator=(const T& x){\n            seg_ref.set(index,\
    \ x);\n            return *this;\n        }\n\n        operator T() const {\n\
    \            return seg_ref.seg[index + seg_ref.siz];\n        }\n    };\n\n \
    \   void set(int i, const T x){\n        i += siz;\n        seg[i] = x;\n    \
    \    while(i >>= 1){\n            seg[i] = Monoid::op(seg[(i << 1) + 0], seg[(i\
    \ << 1) + 1]);\n        }\n    }\n\npublic:\n    // vector \u30B5\u30A4\u30BA\u3092\
    \u6E21\u3057\u3066\u3001\u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\n    Segtree(const\
    \ int N) : N(N) {\n        while(siz < N) siz <<= 1;\n        seg.resize(2 * siz,\
    \ Monoid::e());\n    }\n    // vector \u30B5\u30A4\u30BA\u3068\u521D\u671F\u5024\
    \u3092\u6E21\u3057\u3066\u3001\u521D\u671F\u5024\u3067\u521D\u671F\u5316\n   \
    \ Segtree(const int N, const T init) : N(N) {\n        while(siz < N) siz <<=\
    \ 1;\n        seg.resize(2 * siz, init);\n    }\n    // vector \u3092\u6E21\u3057\
    \u3066\u521D\u671F\u5316\n    Segtree(const std::vector<T>& vec) : N(vec.size())\
    \ {\n        while(siz < N) siz <<= 1;\n        seg.resize(2 * siz, Monoid::e());\n\
    \        for(int i = 0; i < N; i++){\n            seg[i + siz] = vec[i];\n   \
    \     }\n        for(int i = siz - 1; i >= 0; i--){\n            seg[i] = Monoid::op(seg[(i\
    \ << 1) + 0], seg[(i << 1) + 1]);\n        }\n    }\n\n    /**\n     * @brief\
    \ seg[i] = x  \u914D\u5217\u306E i \u756A\u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\
    \u30FC\u30C9\u3092 x \u3067\u30BB\u30C3\u30C8\u3057\u3001\u4E0A\u306B\u3042\u308B\
    \u30CE\u30FC\u30C9\u3092\u66F4\u65B0\n     */\n    Reference operator[](const\
    \ int& i){\n        return Reference(*this, i);\n    }\n\n    /**\n     * @brief\
    \ \u914D\u5217\u306E i \u756A\u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \u306E\u5024\u3092\u8FD4\u5374\n     */\n    const T operator[](const int& i)\
    \ const {\n        return seg[i + siz];\n    }\n\n    /**\n     * @brief \u533A\
    \u9593 [l, r) \u3067\u306E\u5024\u3092\u53D6\u5F97\n     */\n    T prod(int l,\
    \ int r){\n        T ansl = Monoid::e(), ansr = Monoid::e();\n        l += siz,\
    \ r += siz;\n        while(l < r){\n            if(l & 1) ansl = Monoid::op(ansl,\
    \ seg[l++]);\n            if(r & 1) ansr = Monoid::op(seg[--r], ansr);\n     \
    \       l >>= 1, r >>= 1;\n        }\n        return Monoid::op(ansl, ansr);\n\
    \    }\n\n    T prod(const int& i){\n        return prod(i, i + 1);\n    }\n\n\
    \    T all_prod(){\n        return prod(0, N);\n    }\n};\n\n"
  code: "#ifndef Segtree_HPP\n#define Segtree_HPP\n\n#include <vector>\n\ntemplate\
    \ <typename Monoid>\nstruct Segtree {\nprivate:\n    /**\n     * @param seg \u30BB\
    \u30B0\u6728\n     * @param siz \u7BA1\u7406\u3059\u308B vector \u306E\u30B5\u30A4\
    \u30BA\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA\uFF08\u8449\u306E\u6570\uFF09\
    \n     * @param N vector \u306E\u30B5\u30A4\u30BA\n     */\n    using T = typename\
    \ Monoid::S;\n    std::vector<T> seg;\n    int N;\n    int siz = 1;\n\n    struct\
    \ Reference {\n        Segtree& seg_ref;\n        int index;\n\n        Reference(Segtree&\
    \ seg_ref, int index) : seg_ref(seg_ref), index(index) {}\n\n        Reference&\
    \ operator=(const T& x){\n            seg_ref.set(index, x);\n            return\
    \ *this;\n        }\n\n        operator T() const {\n            return seg_ref.seg[index\
    \ + seg_ref.siz];\n        }\n    };\n\n    void set(int i, const T x){\n    \
    \    i += siz;\n        seg[i] = x;\n        while(i >>= 1){\n            seg[i]\
    \ = Monoid::op(seg[(i << 1) + 0], seg[(i << 1) + 1]);\n        }\n    }\n\npublic:\n\
    \    // vector \u30B5\u30A4\u30BA\u3092\u6E21\u3057\u3066\u3001\u5358\u4F4D\u5143\
    \u3067\u521D\u671F\u5316\n    Segtree(const int N) : N(N) {\n        while(siz\
    \ < N) siz <<= 1;\n        seg.resize(2 * siz, Monoid::e());\n    }\n    // vector\
    \ \u30B5\u30A4\u30BA\u3068\u521D\u671F\u5024\u3092\u6E21\u3057\u3066\u3001\u521D\
    \u671F\u5024\u3067\u521D\u671F\u5316\n    Segtree(const int N, const T init) :\
    \ N(N) {\n        while(siz < N) siz <<= 1;\n        seg.resize(2 * siz, init);\n\
    \    }\n    // vector \u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n    Segtree(const\
    \ std::vector<T>& vec) : N(vec.size()) {\n        while(siz < N) siz <<= 1;\n\
    \        seg.resize(2 * siz, Monoid::e());\n        for(int i = 0; i < N; i++){\n\
    \            seg[i + siz] = vec[i];\n        }\n        for(int i = siz - 1; i\
    \ >= 0; i--){\n            seg[i] = Monoid::op(seg[(i << 1) + 0], seg[(i << 1)\
    \ + 1]);\n        }\n    }\n\n    /**\n     * @brief seg[i] = x  \u914D\u5217\u306E\
    \ i \u756A\u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092 x \u3067\
    \u30BB\u30C3\u30C8\u3057\u3001\u4E0A\u306B\u3042\u308B\u30CE\u30FC\u30C9\u3092\
    \u66F4\u65B0\n     */\n    Reference operator[](const int& i){\n        return\
    \ Reference(*this, i);\n    }\n\n    /**\n     * @brief \u914D\u5217\u306E i \u756A\
    \u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u306E\u5024\u3092\u8FD4\
    \u5374\n     */\n    const T operator[](const int& i) const {\n        return\
    \ seg[i + siz];\n    }\n\n    /**\n     * @brief \u533A\u9593 [l, r) \u3067\u306E\
    \u5024\u3092\u53D6\u5F97\n     */\n    T prod(int l, int r){\n        T ansl =\
    \ Monoid::e(), ansr = Monoid::e();\n        l += siz, r += siz;\n        while(l\
    \ < r){\n            if(l & 1) ansl = Monoid::op(ansl, seg[l++]);\n          \
    \  if(r & 1) ansr = Monoid::op(seg[--r], ansr);\n            l >>= 1, r >>= 1;\n\
    \        }\n        return Monoid::op(ansl, ansr);\n    }\n\n    T prod(const\
    \ int& i){\n        return prod(i, i + 1);\n    }\n\n    T all_prod(){\n     \
    \   return prod(0, N);\n    }\n};\n#endif // Segtree_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Segtree.hpp
  requiredBy: []
  timestamp: '2024-09-30 17:42:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Segtree.hpp
layout: document
redirect_from:
- /library/DataStructure/Segtree.hpp
- /library/DataStructure/Segtree.hpp.html
title: "seg[i] = x  \u914D\u5217\u306E i \u756A\u76EE\u306B\u5BFE\u5FDC\u3059\u308B\
  \u30CE\u30FC\u30C9\u3092 x \u3067\u30BB\u30C3\u30C8\u3057\u3001\u4E0A\u306B\u3042\
  \u308B\u30CE\u30FC\u30C9\u3092\u66F4\u65B0"
---
