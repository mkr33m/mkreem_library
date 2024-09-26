---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ac-library/atcoder/modint.hpp
    title: ac-library/atcoder/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Others/Monoids.hpp\"\n\n\n\n#include <cmath>\n\n#line 1\
    \ \"ac-library/atcoder/modint.hpp\"\n\n\n\n#include <atcoder/internal_math>\n\
    #include <atcoder/internal_type_traits>\n#include <cassert>\n#include <numeric>\n\
    #include <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n    static_modint(bool\
    \ v) { _v = ((unsigned int)(v) % umod()); }\n\n    unsigned int val() const {\
    \ return _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }\n\n \
    \   unsigned int val() const { return _v; }\n\n    mint& operator++() {\n    \
    \    _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n    }\n\
    \    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt = 998244353;\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 7 \"Others/Monoids.hpp\"\
    \n\n// \u52A0\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct AddMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return 0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l + r;\n    }\n    static S inv(const\
    \ S& x){\n        return -x;\n    }\n};\n\n// \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T = atcoder::modint998244353>\nstruct MultiplyMonoid_998\
    \ {\n    using S = T;\n    static S e(){\n        return 1;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l * r;\n    }\n    static S inv(const\
    \ S& x){\n        return x.inv();\n    }\n};\n\n// \u639B\u7B97\u30E2\u30CE\u30A4\
    \u30C9\ntemplate <typename T = atcoder::modint1000000007>\nstruct MultiplyMonoid_100\
    \ {\n    using S = T;\n    static S e(){\n        return 1;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l * r;\n    }\n    static S inv(const\
    \ S& x){\n        return x.inv();\n    }\n};\n\n// \u6700\u5927\u5024\u30E2\u30CE\
    \u30A4\u30C9\ntemplate <typename T>\nstruct MaxMonoid {\n    using S = T;\n  \
    \  static S e(){\n        return std::numeric_limits<S>::min();\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return std::max(l, r);\n    }\n};\n\n\
    // \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct MinMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return std::numeric_limits<S>::max();\n\
    \    }\n    static S op(const S& l, const S& r){\n        return std::min(l, r);\n\
    \    }\n};\n\n// AND \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct AndMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return ~0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l & r;\n    }\n};\n\n// OR \u30E2\
    \u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct OrMonoid {\n    using S = T;\n\
    \    static S e(){\n        return 0;\n    }\n    static S op(const S& l, const\
    \ S& r){\n        return l | r;\n    }\n};\n\n// XOR \u30E2\u30CE\u30A4\u30C9\n\
    template <typename T>\nstruct XorMonoid {\n    using S = T;\n    static S e(){\n\
    \        return 0;\n    }\n    static S op(const S& l, const S& r){\n        return\
    \ l ^ r;\n    }\n    static S inv(const S& x){\n        return x;\n    }\n};\n\
    \n\n"
  code: "#ifndef Monoids_HPP\n#define Monoids_HPP\n\n#include <cmath>\n\n#include\
    \ \"../ac-library/atcoder/modint.hpp\"\n\n// \u52A0\u7B97\u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T>\nstruct AddMonoid {\n    using S = T;\n    static S e(){\n\
    \        return 0;\n    }\n    static S op(const S& l, const S& r){\n        return\
    \ l + r;\n    }\n    static S inv(const S& x){\n        return -x;\n    }\n};\n\
    \n// \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T = atcoder::modint998244353>\n\
    struct MultiplyMonoid_998 {\n    using S = T;\n    static S e(){\n        return\
    \ 1;\n    }\n    static S op(const S& l, const S& r){\n        return l * r;\n\
    \    }\n    static S inv(const S& x){\n        return x.inv();\n    }\n};\n\n\
    // \u639B\u7B97\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T = atcoder::modint1000000007>\n\
    struct MultiplyMonoid_100 {\n    using S = T;\n    static S e(){\n        return\
    \ 1;\n    }\n    static S op(const S& l, const S& r){\n        return l * r;\n\
    \    }\n    static S inv(const S& x){\n        return x.inv();\n    }\n};\n\n\
    // \u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct MaxMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return std::numeric_limits<S>::min();\n\
    \    }\n    static S op(const S& l, const S& r){\n        return std::max(l, r);\n\
    \    }\n};\n\n// \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\ntemplate <typename\
    \ T>\nstruct MinMonoid {\n    using S = T;\n    static S e(){\n        return\
    \ std::numeric_limits<S>::max();\n    }\n    static S op(const S& l, const S&\
    \ r){\n        return std::min(l, r);\n    }\n};\n\n// AND \u30E2\u30CE\u30A4\u30C9\
    \ntemplate <typename T>\nstruct AndMonoid {\n    using S = T;\n    static S e(){\n\
    \        return ~0;\n    }\n    static S op(const S& l, const S& r){\n       \
    \ return l & r;\n    }\n};\n\n// OR \u30E2\u30CE\u30A4\u30C9\ntemplate <typename\
    \ T>\nstruct OrMonoid {\n    using S = T;\n    static S e(){\n        return 0;\n\
    \    }\n    static S op(const S& l, const S& r){\n        return l | r;\n    }\n\
    };\n\n// XOR \u30E2\u30CE\u30A4\u30C9\ntemplate <typename T>\nstruct XorMonoid\
    \ {\n    using S = T;\n    static S e(){\n        return 0;\n    }\n    static\
    \ S op(const S& l, const S& r){\n        return l ^ r;\n    }\n    static S inv(const\
    \ S& x){\n        return x;\n    }\n};\n\n#endif // Monoids_HPP"
  dependsOn:
  - ac-library/atcoder/modint.hpp
  isVerificationFile: false
  path: Others/Monoids.hpp
  requiredBy: []
  timestamp: '2024-09-27 02:37:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Monoids.hpp
layout: document
redirect_from:
- /library/Others/Monoids.hpp
- /library/Others/Monoids.hpp.html
title: Others/Monoids.hpp
---
