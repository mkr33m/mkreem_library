---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/math.hpp
    title: "floor(sqrt(N)) \u3092\u6C42\u3081\u308B"
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc236/tasks/abc236_d
  bundledCode: "#line 1 \"Algorithm/next_pairing.hpp\"\n\n\n\n/*\nverify\n\u30FBhttps://atcoder.jp/contests/abc236/tasks/abc236_d\n\
    */\n\n#include <vector>\n\n#line 1 \"Others/macros.hpp\"\n\n\n\n#line 5 \"Others/macros.hpp\"\
    \n#include <queue>\n#include <cmath>\n\nusing ll = long long;\nusing lll = __int128_t;\n\
    using ld = long double;\n#define newl '\\n'\n#define REF const auto&\n#define\
    \ INF 1000390039\n#define LLINF 1000000039000000039\n#define IMAX INT_MAX\n#define\
    \ IMIN INT_MIN\n#define LLMAX LONG_LONG_MAX\n#define LLMIN LONG_LONG_MIN\n#define\
    \ BIT(i) (1LL << (i))\n#define tbit(n, k) ((n >> k) & 1) // n\u306E\uFF08\u4E0A\
    \u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define bit(n, k) (n & (1LL << (k)))\
    \ // n\u306E\uFF08\u4E0B\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define PI\
    \ acos(-1)\n#define inr(l, x, r) (l <= x && x < r)\n#define einr(l, x, r) (l <=\
    \ x && x <= r)\n#define rep(i, a, b) for(int i = (a); i < (b); i++)\n#define erep(i,\
    \ a, b) for(int i = (a); i <= (b); i++)\n#define rrep(i, a, b) for(int i = (a);\
    \ i >= (b); i--)\n#define repl(i, a, b) for(long long i = (a); i < (b); i++)\n\
    #define erepl(i, a, b) for(long long i = (a); i <= (b); i++)\n#define rrepl(i,\
    \ a, b) for(long long i = (a); i >= (b); i--)\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define FOR_subset(sub, bit) for (ll\
    \ sub = (bit); sub >= 0; sub = (sub == 0 ? -1 : (sub - 1) & (bit)))\n#define UNIQUE(v)\
    \ (std::sort(all(v)), (v).erase(std::unique(all(v)), (v).end()))\n#define pcnt(x)\
    \ __builtin_popcount(x)\n#define llpcnt(x) __builtin_popcountll(x)\n// 1D\n#define\
    \ VC(name, type, ...) \\\n    vector<type> name( \\\n        __VA_ARGS__ \\\n\
    \    )\n// 2D\n#define VVC(name, type, a, ...) \\\n    vector<vector<type>> name(\
    \ \\\n        (a), vector<type>( \\\n            __VA_ARGS__ \\\n        ) \\\n\
    \    )\n// 3D\n#define VVVC(name, type, a, b, ...) \\\n    vector<vector<vector<type>>>\
    \ name( \\\n        (a), vector<vector<type>>( \\\n            (b), vector<type>(\
    \ \\\n                __VA_ARGS__ \\\n            ) \\\n        ) \\\n    )\n\
    // 4D\n#define VVVVC(name, type, a, b, c, ...) \\\n    vector<vector<vector<vector<type>>>>\
    \ name( \\\n        (a), vector<vector<vector<type>>>( \\\n            (b), vector<vector<type>>(\
    \ \\\n                (c), vector<type>( \\\n                    __VA_ARGS__ \\\
    \n                ) \\\n            ) \\\n        ) \\\n    )\n// 5D\n#define\
    \ VVVVVC(name, type, a, b, c, d, ...) \\\n    vector<vector<vector<vector<vector<type>>>>>\
    \ name( \\\n        (a), vector<vector<vector<vector<type>>>>( \\\n          \
    \  (b), vector<vector<vector<type>>>( \\\n                (c), vector<vector<type>>(\
    \ \\\n                    (d), vector<type>( \\\n                        __VA_ARGS__\
    \ \\\n                    ) \\\n                ) \\\n            ) \\\n     \
    \   ) \\\n    )\n// 6D\n#define VVVVVVC(name, type, a, b, c, d, e, ...) \\\n \
    \   vector<vector<vector<vector<vector<vector<type>>>>>> name( \\\n        (a),\
    \ vector<vector<vector<vector<vector<type>>>>>( \\\n            (b), vector<vector<vector<vector<type>>>>(\
    \ \\\n                (c), vector<vector<vector<type>>>( \\\n                \
    \    (d), vector<vector<type>>( \\\n                        (e), vector<type>(\
    \ \\\n                            __VA_ARGS__ \\\n                        ) \\\
    \n                    ) \\\n                ) \\\n            ) \\\n        )\
    \ \\\n    )\ntemplate <typename T>\nint lwb(const std::vector<T>& vec, const T&\
    \ x){\n    return lower_bound(all(vec), x) - vec.begin();\n}\ntemplate <typename\
    \ T>\nint upb(const std::vector<T>& vec, const T& x){\n    return upper_bound(all(vec),\
    \ x) - vec.begin();\n}\ntemplate <typename T>\nT max(const std::vector<T>& vec){\
    \ return *max_element(all(vec)); }\ntemplate <typename T>\nT min(const std::vector<T>&\
    \ vec){ return *min_element(all(vec)); }\ntemplate <typename T>\nT rad(const T&\
    \ x){ return x * PI/180; }\ntemplate <typename T>\nusing maxpq = std::priority_queue<T>;\n\
    template <typename T>\nusing minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    // \u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename\
    \ T1, typename T2>\nbool chmax(T1 &a, const T2& b){\n    if (a < b) { a = b; return\
    \ 1; }\n    return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a,\
    \ const T2& b){\n    if (a > b) { a = b; return 1; }\n    return 0;\n}\n\nconst\
    \ int di4[4] = {0, -1, 0, 1};\nconst int dj4[4] = {1, 0, -1, 0};\nconst int di8[8]\
    \ = {0, -1, -1, -1, 0, 1, 1, 1};\nconst int dj8[8] = {1, 1, 0, -1, -1, -1, 0,\
    \ 1};\n\nbool out_of_grid(const int& i, const int& j, const int& h, const int&\
    \ w){\n    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n    return false;\n\
    }\n\n\n#line 1 \"Math/math.hpp\"\n\n\n\n#line 5 \"Math/math.hpp\"\n#include <cassert>\n\
    \nnamespace math {\n\n    ll pow(ll N, ll e) {\n        ll res = 1;\n        while\
    \ (e) {\n            if (e & 1) {\n                res *= N;\n            }\n\
    \            N *= N;\n            e >>= 1;\n        }\n        return res;\n \
    \   }\n\n    template <typename T>\n    T floor (const T& x, const T& m) {\n \
    \       T r = (x % m + m) % m;\n        return (x - r) / m;\n    }\n\n    template\
    \ <typename T>\n    T ceil (const T& x, const T& m) {\n        return floor(x\
    \ + m - 1, m);\n    }\n\n    /**\n     * @brief floor(sqrt(N)) \u3092\u6C42\u3081\
    \u308B\n     */\n    template <typename T>\n    T sqrt_floor(T N) {\n        assert(N\
    \ >= 0);\n        ll R = sqrt(N);\n        // R*R>N \u306A\u3089\u5927\u304D\u3059\
    \u304E\u308B\u306E\u3067\u6E1B\u3089\u3059\n        while (R * R > N) {\n    \
    \        R--;\n        }\n        // \u4E8C\u4E57\u3057\u3066 N \u3092\u8D85\u3048\
    \u306A\u3044\u30AE\u30EA\u30AE\u30EA\u307E\u3067\u5897\u3084\u3059\n        while\
    \ ((R + 1) * (R + 1) <= N) {\n            R++;\n        }\n        return R;\n\
    \    }\n\n    /**\n     * @brief ceil(sqrt(N)) \u3092\u6C42\u3081\u308B\n    \
    \ */\n    template <typename T>\n    T sqrt_ceil(T N) {\n        ll R = sqrt_floor(N);\n\
    \        if (R * R == N) {\n            return R;\n        }\n        return R\
    \ + 1;\n    }\n\n    int log2_floor(ll N) {\n        int res = -1;\n        while\
    \ (N != 0) {\n            res++;\n            N /= 2;\n        }\n        return\
    \ res;\n    }\n\n} // namespace math\n\n\n#line 13 \"Algorithm/next_pairing.hpp\"\
    \n\ntemplate <typename T>\nbool next_pairing(std::vector<T>& vec) {\n    int N\
    \ = vec.size();\n    /**\n     * @param used vec \u3092\u53F3\u304B\u3089\u5DE6\
    \u3078\u8D70\u67FB\u3057\u305F\u3068\u304D\u3001\u3069\u306E\u6570\u5B57\u3092\
    \u898B\u305F\u304B\n     */\n    ll used = 0;\n    for (int i = N - 1; i >= 0;\
    \ i--) {\n        used |= (1 << vec[i]);\n        if (i % 2 == 1 && vec[i] < math::log2_floor(used))\
    \ {\n            vec[i] = __builtin_ctzll(used >> (vec[i] + 1)) + vec[i] + 1;\
    \ // \u307E\u3060\u898B\u3066\u3044\u306A\u3044\u6570\u5B57\u306E\u3046\u3061\u3001\
    \ vec[i] \u3088\u308A\u5927\u304D\u3044\u3082\u306E\u306E\u4E2D\u3067\u6700\u5C0F\
    \u306E\u3082\u306E\n            used ^= (1 << vec[i]);\n            for (int j\
    \ = i + 1; j < N; j++) { // i \u3088\u308A\u5F8C\u308D\u3092\u8F9E\u66F8\u9806\
    \u6700\u5C0F\u306B\n                vec[j] = __builtin_ctzll(used);\n        \
    \        used ^= (1 << vec[j]);\n            }\n            return true;\n   \
    \     }\n    }\n    return false;\n}\n\n\n"
  code: "#ifndef next_pairing_HPP\n#define next_pairing_HPP\n\n/*\nverify\n\u30FB\
    https://atcoder.jp/contests/abc236/tasks/abc236_d\n*/\n\n#include <vector>\n\n\
    #include \"../Others/macros.hpp\"\n#include \"../Math/math.hpp\"\n\ntemplate <typename\
    \ T>\nbool next_pairing(std::vector<T>& vec) {\n    int N = vec.size();\n    /**\n\
    \     * @param used vec \u3092\u53F3\u304B\u3089\u5DE6\u3078\u8D70\u67FB\u3057\
    \u305F\u3068\u304D\u3001\u3069\u306E\u6570\u5B57\u3092\u898B\u305F\u304B\n   \
    \  */\n    ll used = 0;\n    for (int i = N - 1; i >= 0; i--) {\n        used\
    \ |= (1 << vec[i]);\n        if (i % 2 == 1 && vec[i] < math::log2_floor(used))\
    \ {\n            vec[i] = __builtin_ctzll(used >> (vec[i] + 1)) + vec[i] + 1;\
    \ // \u307E\u3060\u898B\u3066\u3044\u306A\u3044\u6570\u5B57\u306E\u3046\u3061\u3001\
    \ vec[i] \u3088\u308A\u5927\u304D\u3044\u3082\u306E\u306E\u4E2D\u3067\u6700\u5C0F\
    \u306E\u3082\u306E\n            used ^= (1 << vec[i]);\n            for (int j\
    \ = i + 1; j < N; j++) { // i \u3088\u308A\u5F8C\u308D\u3092\u8F9E\u66F8\u9806\
    \u6700\u5C0F\u306B\n                vec[j] = __builtin_ctzll(used);\n        \
    \        used ^= (1 << vec[j]);\n            }\n            return true;\n   \
    \     }\n    }\n    return false;\n}\n\n#endif // next_pairing_HPP"
  dependsOn:
  - Others/macros.hpp
  - Math/math.hpp
  - Others/macros.hpp
  isVerificationFile: false
  path: Algorithm/next_pairing.hpp
  requiredBy: []
  timestamp: '2025-11-23 17:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/next_pairing.hpp
layout: document
title: next_pairing
---

## 概要

(2,...,2)-shuffle である 0, 1, ..., 2 * N - 1 の置換 A を、辞書順で列挙する。

## 注意点

引数の vector は、あらかじめソートしておく必要がある。
