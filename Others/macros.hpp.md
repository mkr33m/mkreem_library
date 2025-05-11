---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/next_pairing.hpp
    title: next_pairing
  - icon: ':warning:'
    path: Algorithm/next_pairing.hpp
    title: next_pairing
  - icon: ':warning:'
    path: DataStructure/RangeSet.hpp
    title: "[l, r) \u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\
      \u3069\u3046\u304B\u3092\u8FD4\u3059"
  - icon: ':warning:'
    path: Geometry/Point.hpp
    title: Geometry/Point.hpp
  - icon: ':warning:'
    path: Math/Binom.hpp
    title: Math/Binom.hpp
  - icon: ':warning:'
    path: Math/BinomMod_ll.hpp
    title: "a \u306E mod m \u306B\u304A\u3051\u308B\u9006\u5143 x \u3092\u6C42\u3081\
      \u308B"
  - icon: ':warning:'
    path: Math/math.hpp
    title: Math/math.hpp
  - icon: ':warning:'
    path: Others/ZobristHash.hpp
    title: "\u6E21\u3055\u308C\u305F vector \u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\
      \u3066\u3001\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u5272\u308A\u5F53\u3066\u308B"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Others/macros.hpp\"\n\n\n\n#include <vector>\n#include <queue>\n\
    #include <cmath>\n\nusing ll = long long;\nusing lll = __int128_t;\nusing ld =\
    \ long double;\n#define newl '\\n'\n#define REF const auto&\n#define INF 1000390039\n\
    #define LLINF 1000000039000000039\n#define IMAX INT_MAX\n#define IMIN INT_MIN\n\
    #define LLMAX LONG_LONG_MAX\n#define LLMIN LONG_LONG_MIN\n#define BIT(i) (1LL\
    \ << (i))\n#define tbit(n, k) ((n >> k) & 1) // n\u306E\uFF08\u4E0A\u304B\u3089\
    \uFF09k\u30D3\u30C3\u30C8\u76EE\n#define bit(n, k) (n & (1LL << (k))) // n\u306E\
    \uFF08\u4E0B\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define PI acos(-1)\n\
    #define inr(l, x, r) (l <= x && x < r)\n#define einr(l, x, r) (l <= x && x <=\
    \ r)\n#define rep(i, a, b) for(int i = (a); i < (b); i++)\n#define erep(i, a,\
    \ b) for(int i = (a); i <= (b); i++)\n#define rrep(i, a, b) for(int i = (a); i\
    \ >= (b); i--)\n#define repl(i, a, b) for(long long i = (a); i < (b); i++)\n#define\
    \ erepl(i, a, b) for(long long i = (a); i <= (b); i++)\n#define rrepl(i, a, b)\
    \ for(long long i = (a); i >= (b); i--)\n#define all(x) (x).begin(), (x).end()\n\
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
    \ <typename T>\nusing maxpq = std::priority_queue<T>;\ntemplate <typename T>\n\
    using minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\
    \u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1,\
    \ typename T2>\nbool chmax(T1 &a, const T2& b){\n    if (a < b) { a = b; return\
    \ 1; }\n    return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a,\
    \ const T2& b){\n    if (a > b) { a = b; return 1; }\n    return 0;\n}\n\nconst\
    \ int di4[4] = {-1, 0, 1, 0};\nconst int dj4[4] = {0, 1, 0, -1};\nconst int di8[8]\
    \ = {-1, -1, 0, 1, 1, 1, 0, -1};\nconst int dj8[8] = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    \nbool out_of_grid(const int& i, const int& j, const int& h, const int& w){\n\
    \    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n    return false;\n\
    }\n\n\n"
  code: "#ifndef macros_HPP\n#define macros_HPP\n\n#include <vector>\n#include <queue>\n\
    #include <cmath>\n\nusing ll = long long;\nusing lll = __int128_t;\nusing ld =\
    \ long double;\n#define newl '\\n'\n#define REF const auto&\n#define INF 1000390039\n\
    #define LLINF 1000000039000000039\n#define IMAX INT_MAX\n#define IMIN INT_MIN\n\
    #define LLMAX LONG_LONG_MAX\n#define LLMIN LONG_LONG_MIN\n#define BIT(i) (1LL\
    \ << (i))\n#define tbit(n, k) ((n >> k) & 1) // n\u306E\uFF08\u4E0A\u304B\u3089\
    \uFF09k\u30D3\u30C3\u30C8\u76EE\n#define bit(n, k) (n & (1LL << (k))) // n\u306E\
    \uFF08\u4E0B\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define PI acos(-1)\n\
    #define inr(l, x, r) (l <= x && x < r)\n#define einr(l, x, r) (l <= x && x <=\
    \ r)\n#define rep(i, a, b) for(int i = (a); i < (b); i++)\n#define erep(i, a,\
    \ b) for(int i = (a); i <= (b); i++)\n#define rrep(i, a, b) for(int i = (a); i\
    \ >= (b); i--)\n#define repl(i, a, b) for(long long i = (a); i < (b); i++)\n#define\
    \ erepl(i, a, b) for(long long i = (a); i <= (b); i++)\n#define rrepl(i, a, b)\
    \ for(long long i = (a); i >= (b); i--)\n#define all(x) (x).begin(), (x).end()\n\
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
    \ <typename T>\nusing maxpq = std::priority_queue<T>;\ntemplate <typename T>\n\
    using minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\
    \u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1,\
    \ typename T2>\nbool chmax(T1 &a, const T2& b){\n    if (a < b) { a = b; return\
    \ 1; }\n    return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a,\
    \ const T2& b){\n    if (a > b) { a = b; return 1; }\n    return 0;\n}\n\nconst\
    \ int di4[4] = {-1, 0, 1, 0};\nconst int dj4[4] = {0, 1, 0, -1};\nconst int di8[8]\
    \ = {-1, -1, 0, 1, 1, 1, 0, -1};\nconst int dj8[8] = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    \nbool out_of_grid(const int& i, const int& j, const int& h, const int& w){\n\
    \    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n    return false;\n\
    }\n\n#endif // macros_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/macros.hpp
  requiredBy:
  - Math/math.hpp
  - Math/Binom.hpp
  - Math/BinomMod_ll.hpp
  - DataStructure/RangeSet.hpp
  - Others/ZobristHash.hpp
  - Algorithm/next_pairing.hpp
  - Algorithm/next_pairing.hpp
  - Geometry/Point.hpp
  timestamp: '2025-05-11 23:56:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/macros.hpp
layout: document
redirect_from:
- /library/Others/macros.hpp
- /library/Others/macros.hpp.html
title: Others/macros.hpp
---
