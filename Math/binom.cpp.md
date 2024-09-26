---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/binom.cpp\"\n\n\n\n#include <vector>\n\n#line 1 \"\
    Others/macros.hpp\"\n\n\n\n#line 5 \"Others/macros.hpp\"\n#include <queue>\n#include\
    \ <cmath>\n\nusing ll = long long;\nusing lll = __int128_t;\nusing ld = long double;\n\
    #define newl '\\n'\n#define REF const auto&\n#define INF 1000390039\n#define LLINF\
    \ 1000000039000000039\n#define IMAX INT_MAX\n#define IMIN INT_MIN\n#define LLMAX\
    \ LONG_LONG_MAX\n#define LLMIN LONG_LONG_MIN\n#define BIT(i) (1LL << (i))\n#define\
    \ tbit(n, k) ((n >> k) & 1) // n\u306E\uFF08\u4E0A\u304B\u3089\uFF09k\u30D3\u30C3\
    \u30C8\u76EE\n#define bit(n, k) (n & (1LL << (k))) // n\u306E\uFF08\u4E0B\u304B\
    \u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define PI acos(-1)\n#define inr(l, x,\
    \ r) (l <= x && x < r)\n#define einr(l, x, r) (l <= x && x <= r)\n#define rep(i,\
    \ a, b) for(int i = (a); i < (b); i++)\n#define erep(i, a, b) for(int i = (a);\
    \ i <= (b); i++)\n#define rrep(i, a, b) for(int i = (a); i >= (b); i--)\n#define\
    \ repl(i, a, b) for(long long i = (a); i < (b); i++)\n#define erepl(i, a, b) for(long\
    \ long i = (a); i <= (b); i++)\n#define rrepl(i, a, b) for(long long i = (a);\
    \ i >= (b); i--)\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define FOR_subset(sub, bit) for (ll sub = (bit); sub >= 0; sub\
    \ = (sub == 0 ? -1 : (sub - 1) & (bit)))\n#define UNIQUE(v) (std::sort(all(v)),\
    \ (v).erase(std::unique(all(v)), (v).end()))\n#define pcnt(x) __builtin_popcount(x)\n\
    #define llpcnt(x) __builtin_popcountll(x)\n#define VC(name, type, ...) vector<type>\
    \ name(__VA_ARGS__)\n#define VVC(name, type, a, ...) vector<vector<type>> name(a,\
    \ vector<type>(__VA_ARGS__))\n#define VVVC(name, type, a, b, ...) vector<vector<vector<type>>>\
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
    \ 7 \"Math/binom.cpp\"\n\nstruct binom {\nprivate:\n    int N;\n    std::vector<std::vector<ll>>\
    \ C;\n\npublic:\n    binom() = default;\n    binom(const int& N) : N(N), C(N +\
    \ 1, std::vector<ll>(N + 1, 0)) {\n        for(int i = 0; i <= N; i++){\n    \
    \        C[i][0] = 1;\n        }\n        // nCk = (n-1)C(k-1) + (n-1)Ck\n   \
    \     for(int i = 1; i <= N; i++){\n            for(int j = 1; j <= N; j++){\n\
    \                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n            }\n   \
    \     }\n    }\n\n    ll val(int i, int j){\n        if(i < j || i < 0 || j <\
    \ 0){\n            return 0LL;\n        }\n        return C[i][j];\n    }\n};\n\
    \n\n"
  code: "#ifndef binom_HPP\n#define binom_HPP\n\n#include <vector>\n\n#include \"\
    ../Others/macros.hpp\"\n\nstruct binom {\nprivate:\n    int N;\n    std::vector<std::vector<ll>>\
    \ C;\n\npublic:\n    binom() = default;\n    binom(const int& N) : N(N), C(N +\
    \ 1, std::vector<ll>(N + 1, 0)) {\n        for(int i = 0; i <= N; i++){\n    \
    \        C[i][0] = 1;\n        }\n        // nCk = (n-1)C(k-1) + (n-1)Ck\n   \
    \     for(int i = 1; i <= N; i++){\n            for(int j = 1; j <= N; j++){\n\
    \                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n            }\n   \
    \     }\n    }\n\n    ll val(int i, int j){\n        if(i < j || i < 0 || j <\
    \ 0){\n            return 0LL;\n        }\n        return C[i][j];\n    }\n};\n\
    \n#endif // binom_HPP"
  dependsOn:
  - Others/macros.hpp
  isVerificationFile: false
  path: Math/binom.cpp
  requiredBy: []
  timestamp: '2024-09-26 23:38:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/binom.cpp
layout: document
redirect_from:
- /library/Math/binom.cpp
- /library/Math/binom.cpp.html
title: Math/binom.cpp
---
