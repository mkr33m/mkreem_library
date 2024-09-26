---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/next_pairing.hpp
    title: "(2,...,2)-shuffle \u3067\u3042\u308B 0, 1, ..., 2 * N - 1 \u306E\u7F6E\
      \u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B"
  - icon: ':warning:'
    path: Algorithm/next_pairing.hpp
    title: "(2,...,2)-shuffle \u3067\u3042\u308B 0, 1, ..., 2 * N - 1 \u306E\u7F6E\
      \u63DB A \u3092\u3001\u8F9E\u66F8\u9806\u3067\u5217\u6319\u3059\u308B"
  - icon: ':warning:'
    path: DataStructure/RangeSet.hpp
    title: "\u9589\u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B"
  - icon: ':warning:'
    path: Geometry/Point.hpp
    title: Geometry/Point.hpp
  - icon: ':warning:'
    path: Math/binom.cpp
    title: Math/binom.cpp
  - icon: ':warning:'
    path: Math/binom_mod_ll.cpp
    title: "a \u306E mod m \u306B\u304A\u3051\u308B\u9006\u5143 x \u3092\u6C42\u3081\
      \u308B"
  - icon: ':warning:'
    path: Math/math.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\u3092\u5229\u7528\u3057\u305F\
      \u3001x^n\u306E\u6C42\u5024"
  - icon: ':warning:'
    path: Others/ZobristHash.hpp
    title: "\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u3001\u30CF\u30C3\u30B7\u30E5\
      \u5024\u3092\u5272\u308A\u5F53\u3066\u308B"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Others/macros.hpp\"\n\n\n\n#include <vector>\n#include <queue>\n\
    #include <cmath>\n#include <../ac-library/atcoder/modint>\n\nusing ll = long long;\n\
    using lll = __int128_t;\nusing ld = long double;\n#define newl '\\n'\n#define\
    \ REF const auto&\n#define INF 1000390039\n#define LLINF 1000000039000000039\n\
    #define IMAX INT_MAX\n#define IMIN INT_MIN\n#define LLMAX LONG_LONG_MAX\n#define\
    \ LLMIN LONG_LONG_MIN\n#define BIT(i) (1LL << (i))\n#define tbit(n, k) ((n >>\
    \ k) & 1) // n\u306E\uFF08\u4E0A\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n\
    #define bit(n, k) (n & (1LL << (k))) // n\u306E\uFF08\u4E0B\u304B\u3089\uFF09\
    k\u30D3\u30C3\u30C8\u76EE\n#define PI acos(-1)\n#define inr(l, x, r) (l <= x &&\
    \ x < r)\n#define einr(l, x, r) (l <= x && x <= r)\n#define rep(i, a, b) for(int\
    \ i = (a); i < (b); i++)\n#define erep(i, a, b) for(int i = (a); i <= (b); i++)\n\
    #define rrep(i, a, b) for(int i = (a); i >= (b); i--)\n#define repl(i, a, b) for(long\
    \ long i = (a); i < (b); i++)\n#define erepl(i, a, b) for(long long i = (a); i\
    \ <= (b); i++)\n#define rrepl(i, a, b) for(long long i = (a); i >= (b); i--)\n\
    #define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define FOR_subset(sub, bit) for (ll sub = (bit); sub >= 0; sub = (sub == 0 ?\
    \ -1 : (sub - 1) & (bit)))\n#define UNIQUE(v) (std::sort(all(v)), (v).erase(std::unique(all(v)),\
    \ (v).end()))\n#define pcnt(x) __builtin_popcount(x)\n#define llpcnt(x) __builtin_popcountll(x)\n\
    #define VC(name, type, ...) vector<type> name(__VA_ARGS__)\n#define VVC(name,\
    \ type, a, ...) vector<vector<type>> name(a, vector<type>(__VA_ARGS__))\n#define\
    \ VVVC(name, type, a, b, ...) vector<vector<vector<type>>> name(a, vector<vector<type>>(b,\
    \ vector<type>(__VA_ARGS__)))\n#define VVVVC(name, type, a, b, c, ...) vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    #define VVVVVC(name, type, a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>>\
    \ name(a, vector<vector<vector<vector<type>>>>(b, vector<vector<vector<type>>>(c,\
    \ vector<vector<type>>(d, vector<type>(__VA_ARGS__)))));\ntemplate <typename T>\n\
    int lwb(const std::vector<T>& vec, const T& x){\n    return lower_bound(all(vec),\
    \ x) - vec.begin();\n}\ntemplate <typename T>\nint upb(const std::vector<T>& vec,\
    \ const T& x){\n    return upper_bound(all(vec), x) - vec.begin();\n}\ntemplate\
    \ <typename T>\nT max(const std::vector<T>& vec){ return *max_element(all(vec));\
    \ }\ntemplate <typename T>\nT min(const std::vector<T>& vec){ return *min_element(all(vec));\
    \ }\ntemplate <typename T>\nT rad(const T& x){ return x * PI/180; }\ntemplate\
    \ <typename T>\nusing pq = std::priority_queue<T>;\ntemplate <typename T>\nusing\
    \ pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1, typename\
    \ T2>\nbool chmax(T1 &a, const T2& b){\n    if(a < b){ a = b; return 1; }\n  \
    \  else return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a, const\
    \ T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\n\n"
  code: "#ifndef macros_HPP\n#define macros_HPP\n\n#include <vector>\n#include <queue>\n\
    #include <cmath>\n#include <../ac-library/atcoder/modint>\n\nusing ll = long long;\n\
    using lll = __int128_t;\nusing ld = long double;\n#define newl '\\n'\n#define\
    \ REF const auto&\n#define INF 1000390039\n#define LLINF 1000000039000000039\n\
    #define IMAX INT_MAX\n#define IMIN INT_MIN\n#define LLMAX LONG_LONG_MAX\n#define\
    \ LLMIN LONG_LONG_MIN\n#define BIT(i) (1LL << (i))\n#define tbit(n, k) ((n >>\
    \ k) & 1) // n\u306E\uFF08\u4E0A\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n\
    #define bit(n, k) (n & (1LL << (k))) // n\u306E\uFF08\u4E0B\u304B\u3089\uFF09\
    k\u30D3\u30C3\u30C8\u76EE\n#define PI acos(-1)\n#define inr(l, x, r) (l <= x &&\
    \ x < r)\n#define einr(l, x, r) (l <= x && x <= r)\n#define rep(i, a, b) for(int\
    \ i = (a); i < (b); i++)\n#define erep(i, a, b) for(int i = (a); i <= (b); i++)\n\
    #define rrep(i, a, b) for(int i = (a); i >= (b); i--)\n#define repl(i, a, b) for(long\
    \ long i = (a); i < (b); i++)\n#define erepl(i, a, b) for(long long i = (a); i\
    \ <= (b); i++)\n#define rrepl(i, a, b) for(long long i = (a); i >= (b); i--)\n\
    #define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define FOR_subset(sub, bit) for (ll sub = (bit); sub >= 0; sub = (sub == 0 ?\
    \ -1 : (sub - 1) & (bit)))\n#define UNIQUE(v) (std::sort(all(v)), (v).erase(std::unique(all(v)),\
    \ (v).end()))\n#define pcnt(x) __builtin_popcount(x)\n#define llpcnt(x) __builtin_popcountll(x)\n\
    #define VC(name, type, ...) vector<type> name(__VA_ARGS__)\n#define VVC(name,\
    \ type, a, ...) vector<vector<type>> name(a, vector<type>(__VA_ARGS__))\n#define\
    \ VVVC(name, type, a, b, ...) vector<vector<vector<type>>> name(a, vector<vector<type>>(b,\
    \ vector<type>(__VA_ARGS__)))\n#define VVVVC(name, type, a, b, c, ...) vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    #define VVVVVC(name, type, a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>>\
    \ name(a, vector<vector<vector<vector<type>>>>(b, vector<vector<vector<type>>>(c,\
    \ vector<vector<type>>(d, vector<type>(__VA_ARGS__)))));\ntemplate <typename T>\n\
    int lwb(const std::vector<T>& vec, const T& x){\n    return lower_bound(all(vec),\
    \ x) - vec.begin();\n}\ntemplate <typename T>\nint upb(const std::vector<T>& vec,\
    \ const T& x){\n    return upper_bound(all(vec), x) - vec.begin();\n}\ntemplate\
    \ <typename T>\nT max(const std::vector<T>& vec){ return *max_element(all(vec));\
    \ }\ntemplate <typename T>\nT min(const std::vector<T>& vec){ return *min_element(all(vec));\
    \ }\ntemplate <typename T>\nT rad(const T& x){ return x * PI/180; }\ntemplate\
    \ <typename T>\nusing pq = std::priority_queue<T>;\ntemplate <typename T>\nusing\
    \ pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1, typename\
    \ T2>\nbool chmax(T1 &a, const T2& b){\n    if(a < b){ a = b; return 1; }\n  \
    \  else return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a, const\
    \ T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\n#endif\
    \ // macros"
  dependsOn: []
  isVerificationFile: false
  path: Others/macros.hpp
  requiredBy:
  - Geometry/Point.hpp
  - DataStructure/RangeSet.hpp
  - Math/math.hpp
  - Math/binom.cpp
  - Math/binom_mod_ll.cpp
  - Algorithm/next_pairing.hpp
  - Algorithm/next_pairing.hpp
  - Others/ZobristHash.hpp
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/macros.hpp
layout: document
redirect_from:
- /library/Others/macros.hpp
- /library/Others/macros.hpp.html
title: Others/macros.hpp
---
