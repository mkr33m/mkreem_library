---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/math.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\u3092\u5229\u7528\u3057\u305F\
      \u3001x^n\u306E\u6C42\u5024"
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
    document_title: "(2,...,2)-shuffle \u3067\u3042\u308B 0, 1, ..., 2 * N - 1 \u306E\
      \u7F6E\u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B"
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
    \ __builtin_popcount(x)\n#define llpcnt(x) __builtin_popcountll(x)\n#define VC(name,\
    \ type, ...) vector<type> name(__VA_ARGS__)\n#define VVC(name, type, a, ...) vector<vector<type>>\
    \ name(a, vector<type>(__VA_ARGS__))\n#define VVVC(name, type, a, b, ...) vector<vector<vector<type>>>\
    \ name(a, vector<vector<type>>(b, vector<type>(__VA_ARGS__)))\n#define VVVVC(name,\
    \ type, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n#define VVVVVC(name, type,\
    \ a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>> name(a, vector<vector<vector<vector<type>>>>(b,\
    \ vector<vector<vector<type>>>(c, vector<vector<type>>(d, vector<type>(__VA_ARGS__)))));\n\
    template <typename T>\nint lwb(const std::vector<T>& vec, const T& x){\n    return\
    \ lower_bound(all(vec), x) - vec.begin();\n}\ntemplate <typename T>\nint upb(const\
    \ std::vector<T>& vec, const T& x){\n    return upper_bound(all(vec), x) - vec.begin();\n\
    }\ntemplate <typename T>\nT max(const std::vector<T>& vec){ return *max_element(all(vec));\
    \ }\ntemplate <typename T>\nT min(const std::vector<T>& vec){ return *min_element(all(vec));\
    \ }\ntemplate <typename T>\nT rad(const T& x){ return x * PI/180; }\ntemplate\
    \ <typename T>\nusing pq = std::priority_queue<T>;\ntemplate <typename T>\nusing\
    \ pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1, typename\
    \ T2>\nbool chmax(T1 &a, const T2& b){\n    if(a < b){ a = b; return 1; }\n  \
    \  else return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a, const\
    \ T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\n\n#line\
    \ 1 \"Math/math.hpp\"\n\n\n\n#line 5 \"Math/math.hpp\"\n\nnamespace math {\n\n\
    \    /**\n     * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\u3092\u5229\
    \u7528\u3057\u305F\u3001x^n\u306E\u6C42\u5024\n     */\n    ll pow(ll x, ll n){\n\
    \        ll res = 1;\n\n        while(n){\n            if(n & 1) res *= x;\n \
    \           x *= x;\n            n >>= 1;\n        }\n\n        return res;\n\
    \    }\n\n    /**\n     * @brief x/m\u306Efloor\uFF08x/m\u4EE5\u4E0B\u306E\u6700\
    \u5927\u306E\u6574\u6570\uFF09\u3092\u6C42\u3081\u308B\n     */\n    ll floor(const\
    \ ll& x, const ll& m){\n        ll r = (x % m + m) % m; // x\u3092m\u3067\u5272\
    \u3063\u305F\u4F59\u308A\n        return (x - r) / m;\n    }\n\n    /**\n    \
    \ * @brief x/m\u306Eceil\uFF08x/m\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u6574\u6570\
    \uFF09\u3092\u6C42\u3081\u308B\n     */\n    ll ceil(const ll& x, const ll& m){\n\
    \        return floor(x + m - 1, m); // x/m + (m-1)/m\n    }\n\n    /**\n    \
    \ * @brief log(2)N \u306E\u6574\u6570\u90E8\u5206\u3092\u6C42\u3081\u308B\n  \
    \   */\n    int log2_floor(long long N){\n        int res = -1;\n        while(N\
    \ != 0){\n            res++;\n            N /= 2;\n        }\n        return res;\n\
    \    }\n\n} // namespace math\n\n\n#line 13 \"Algorithm/next_pairing.hpp\"\n\n\
    template <typename T>\n/**\n * @brief (2,...,2)-shuffle \u3067\u3042\u308B 0,\
    \ 1, ..., 2 * N - 1 \u306E\u7F6E\u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\
    \u6319\u3059\u308B\n */\nbool next_pairing(const std::vector<T>& vec){\n    int\
    \ N = vec.size();\n    /**\n     * @param used vec \u3092\u53F3\u304B\u3089\u5DE6\
    \u3078\u8D70\u67FB\u3057\u305F\u3068\u304D\u3001\u3069\u306E\u6570\u5B57\u3092\
    \u898B\u305F\u304B\n     */\n    ll used = 0;\n    for(int i = N - 1; i >= 0;\
    \ i--){\n        used |= (1 << vec[i]);\n        if(i % 2 == 1 && vec[i] < math::log2_floor(used)){\n\
    \            vec[i] = __builtin_ctzll(used >> (vec[i] + 1)) + vec[i] + 1; // \u307E\
    \u3060\u898B\u3066\u3044\u306A\u3044\u6570\u5B57\u306E\u3046\u3061\u3001 vec[i]\
    \ \u3088\u308A\u5927\u304D\u3044\u3082\u306E\u306E\u4E2D\u3067\u6700\u5C0F\u306E\
    \u3082\u306E\n            used ^= (1 << vec[i]);\n            for(int j = i +\
    \ 1; j < N; j++){ // i \u3088\u308A\u5F8C\u308D\u3092\u8F9E\u66F8\u9806\u6700\u5C0F\
    \u306B\n                vec[j] = __builtin_ctzll(used);\n                used\
    \ ^= (1 << vec[j]);\n            }\n            return true;\n        }\n    }\n\
    \    return false;\n}\n\n\n"
  code: "#ifndef next_pairing_HPP\n#define next_pairing_HPP\n\n/*\nverify\n\u30FB\
    https://atcoder.jp/contests/abc236/tasks/abc236_d\n*/\n\n#include <vector>\n\n\
    #include \"../Others/macros.hpp\"\n#include \"../Math/math.hpp\"\n\ntemplate <typename\
    \ T>\n/**\n * @brief (2,...,2)-shuffle \u3067\u3042\u308B 0, 1, ..., 2 * N - 1\
    \ \u306E\u7F6E\u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B\
    \n */\nbool next_pairing(const std::vector<T>& vec){\n    int N = vec.size();\n\
    \    /**\n     * @param used vec \u3092\u53F3\u304B\u3089\u5DE6\u3078\u8D70\u67FB\
    \u3057\u305F\u3068\u304D\u3001\u3069\u306E\u6570\u5B57\u3092\u898B\u305F\u304B\
    \n     */\n    ll used = 0;\n    for(int i = N - 1; i >= 0; i--){\n        used\
    \ |= (1 << vec[i]);\n        if(i % 2 == 1 && vec[i] < math::log2_floor(used)){\n\
    \            vec[i] = __builtin_ctzll(used >> (vec[i] + 1)) + vec[i] + 1; // \u307E\
    \u3060\u898B\u3066\u3044\u306A\u3044\u6570\u5B57\u306E\u3046\u3061\u3001 vec[i]\
    \ \u3088\u308A\u5927\u304D\u3044\u3082\u306E\u306E\u4E2D\u3067\u6700\u5C0F\u306E\
    \u3082\u306E\n            used ^= (1 << vec[i]);\n            for(int j = i +\
    \ 1; j < N; j++){ // i \u3088\u308A\u5F8C\u308D\u3092\u8F9E\u66F8\u9806\u6700\u5C0F\
    \u306B\n                vec[j] = __builtin_ctzll(used);\n                used\
    \ ^= (1 << vec[j]);\n            }\n            return true;\n        }\n    }\n\
    \    return false;\n}\n\n#endif // next_pairing_HPP"
  dependsOn:
  - Others/macros.hpp
  - Math/math.hpp
  - Others/macros.hpp
  isVerificationFile: false
  path: Algorithm/next_pairing.hpp
  requiredBy: []
  timestamp: '2024-09-29 06:50:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/next_pairing.hpp
layout: document
redirect_from:
- /library/Algorithm/next_pairing.hpp
- /library/Algorithm/next_pairing.hpp.html
title: "(2,...,2)-shuffle \u3067\u3042\u308B 0, 1, ..., 2 * N - 1 \u306E\u7F6E\u63DB\
  \ A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B"
---