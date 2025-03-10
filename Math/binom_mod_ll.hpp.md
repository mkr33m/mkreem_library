---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/extended_gcd.hpp
    title: "a * x + b * y == gcd(a, b)\u3092\u6E80\u305F\u3059 x, y \u3092\u898B\u3064\
      \u3051\u308B"
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "a \u306E mod m \u306B\u304A\u3051\u308B\u9006\u5143 x \u3092\u6C42\
      \u3081\u308B"
    links: []
  bundledCode: "#line 1 \"Math/binom_mod_ll.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n\n#line 1 \"Others/macros.hpp\"\n\n\n\n#line 5 \"Others/macros.hpp\"\
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
    \ <typename T>\nusing maxpq = std::priority_queue<T>;\ntemplate <typename T>\n\
    using minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\
    \u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1,\
    \ typename T2>\nbool chmax(T1 &a, const T2& b){\n    if(a < b){ a = b; return\
    \ 1; }\n    else return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1\
    \ &a, const T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\
    \nconst int di4[4] = {-1, 0, 1, 0};\nconst int dj4[4] = {0, 1, 0, -1};\nconst\
    \ int di8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};\nconst int dj8[8] = {0, 1, 1, 1, 0,\
    \ -1, -1, -1};\n\nbool out_of_grid(const int& i, const int& j, const int& h, const\
    \ int& w){\n    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n    return\
    \ false;\n}\n\n\n#line 1 \"Math/extended_gcd.hpp\"\n\n\n\n/**\n * @brief a * x\
    \ + b * y == gcd(a, b)\u3092\u6E80\u305F\u3059 x, y \u3092\u898B\u3064\u3051\u308B\
    \n * @return gcd(a, b)\n * x \u304C a \u306E\u9006\u5143\u306B\u76F8\u5F53\n */\n\
    long long extended_gcd(long long a, long long b, long long &x, long long &y) {\n\
    \    /*\n    a * x0 + b * y0 == gcd(a, b)\n    \u2193 a = q * b + r\uFF08\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF09\n    -> b * x1 +\
    \ r * y1 == gcd(a, b)\n    -> ...\n    -> gcd(a, b) * xn + 0 * yn == gcd(a, b)\n\
    \    */\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    long long prev_x, prev_y;\n    long long gcd = extended_gcd(b, a %\
    \ b, prev_x, prev_y);\n    // \u5E30\u308A\u304C\u3051\u306B\u4FC2\u6570\u3092\
    \u66F4\u65B0\n    x = prev_y;\n    y = prev_x - (a / b) * prev_y;\n    \n    return\
    \ gcd;\n}\n\n\n#line 9 \"Math/binom_mod_ll.hpp\"\n\nstruct BinomModLL {\nprivate:\n\
    \    int MAX_N;\n    ll MOD;\n    std::vector<ll> factorial, factorial_inv;\n\n\
    \    /**\n     * @brief a \u306E mod m \u306B\u304A\u3051\u308B\u9006\u5143 x\
    \ \u3092\u6C42\u3081\u308B\n     * a*x == 1 \u3092\u6E80\u305F\u3059 x \u3092\u6C42\
    \u3081\u305F\u3044\u3068\u3044\u3046\u3053\u3068\u306F\u3001a*x + b*y == 1 \u3092\
    \u6E80\u305F\u3059 x \u3092\u6C42\u3081\u305F\u3044\u3068\u3044\u3046\u3053\u3068\
    \n     */\n    ll mod_inverse(ll a, ll m) {\n        ll x, y;\n        ll g =\
    \ extended_gcd(a, m, x, y);\n        assert(g == 1);\n        return (x % m +\
    \ m) % m;\n    }\n\npublic:\n    BinomModLL(int MAX_N = 10000000, ll MOD = 998244353)\
    \ : MAX_N(MAX_N), MOD(MOD) {\n        factorial[0] = 1;\n        for (int i =\
    \ 1; i <= MAX_N; i++) {\n            factorial[i] = factorial[i - 1] * i % MOD;\n\
    \        }\n        factorial_inv[MAX_N] = mod_inverse(factorial[MAX_N], MOD);\n\
    \        for (int i = MAX_N - 1; i >= 0; i--) {\n            /*\n            ((i+1)!)^(-1)\
    \ \u2261 (i+1)^(-1) * (i!)^(-1)\n            \u3088\u308A\u3001\n            (i!)^(-1)\
    \ == ((i+1)!)^(-1) * (i+1)\n            */\n            factorial_inv[i] = factorial_inv[i\
    \ + 1] * (i + 1) % MOD;\n        }\n    }\n\n    ll val(int N, int K) {\n    \
    \    if (N < K || N < 0 || K < 0) {\n            return 0;\n        }\n      \
    \  return factorial[N] * (factorial_inv[K] * factorial_inv[N - K] % MOD) % MOD;\n\
    \    }\n};\n\n\n"
  code: "#ifndef binom_mod_ll_HPP\n#define binom_mod_ll_HPP\n\n#include <vector>\n\
    #include <cassert>\n\n#include \"../Others/macros.hpp\"\n#include \"extended_gcd.hpp\"\
    \n\nstruct BinomModLL {\nprivate:\n    int MAX_N;\n    ll MOD;\n    std::vector<ll>\
    \ factorial, factorial_inv;\n\n    /**\n     * @brief a \u306E mod m \u306B\u304A\
    \u3051\u308B\u9006\u5143 x \u3092\u6C42\u3081\u308B\n     * a*x == 1 \u3092\u6E80\
    \u305F\u3059 x \u3092\u6C42\u3081\u305F\u3044\u3068\u3044\u3046\u3053\u3068\u306F\
    \u3001a*x + b*y == 1 \u3092\u6E80\u305F\u3059 x \u3092\u6C42\u3081\u305F\u3044\
    \u3068\u3044\u3046\u3053\u3068\n     */\n    ll mod_inverse(ll a, ll m) {\n  \
    \      ll x, y;\n        ll g = extended_gcd(a, m, x, y);\n        assert(g ==\
    \ 1);\n        return (x % m + m) % m;\n    }\n\npublic:\n    BinomModLL(int MAX_N\
    \ = 10000000, ll MOD = 998244353) : MAX_N(MAX_N), MOD(MOD) {\n        factorial[0]\
    \ = 1;\n        for (int i = 1; i <= MAX_N; i++) {\n            factorial[i] =\
    \ factorial[i - 1] * i % MOD;\n        }\n        factorial_inv[MAX_N] = mod_inverse(factorial[MAX_N],\
    \ MOD);\n        for (int i = MAX_N - 1; i >= 0; i--) {\n            /*\n    \
    \        ((i+1)!)^(-1) \u2261 (i+1)^(-1) * (i!)^(-1)\n            \u3088\u308A\
    \u3001\n            (i!)^(-1) == ((i+1)!)^(-1) * (i+1)\n            */\n     \
    \       factorial_inv[i] = factorial_inv[i + 1] * (i + 1) % MOD;\n        }\n\
    \    }\n\n    ll val(int N, int K) {\n        if (N < K || N < 0 || K < 0) {\n\
    \            return 0;\n        }\n        return factorial[N] * (factorial_inv[K]\
    \ * factorial_inv[N - K] % MOD) % MOD;\n    }\n};\n\n#endif //binom_mod_ll_HPP"
  dependsOn:
  - Others/macros.hpp
  - Math/extended_gcd.hpp
  isVerificationFile: false
  path: Math/binom_mod_ll.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/binom_mod_ll.hpp
layout: document
redirect_from:
- /library/Math/binom_mod_ll.hpp
- /library/Math/binom_mod_ll.hpp.html
title: "a \u306E mod m \u306B\u304A\u3051\u308B\u9006\u5143 x \u3092\u6C42\u3081\u308B"
---
