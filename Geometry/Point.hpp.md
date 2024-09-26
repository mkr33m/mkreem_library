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
  bundledCode: "#line 1 \"Geometry/Point.hpp\"\n\n\n\n#line 1 \"Others/macros.hpp\"\
    \n\n\n\n#include <vector>\n#include <queue>\n#include <cmath>\n#include <../ac-library/atcoder/modint>\n\
    \nusing ll = long long;\nusing lll = __int128_t;\nusing ld = long double;\n#define\
    \ newl '\\n'\n#define REF const auto&\n#define INF 1000390039\n#define LLINF 1000000039000000039\n\
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
    \ T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\n\n#line\
    \ 5 \"Geometry/Point.hpp\"\n\nstruct Point {\nprivate:\n    /**\n     * @remark\
    \ \u5927\u307E\u304B\u306B\u306F\u3001\u30B0\u30EB\u30FC\u30D7\u306E\u6607\u9806\
    \u3067\u30BD\u30FC\u30C8\u3002\n     * @remark \u539F\u70B9\u306E\u6271\u3044\u306B\
    \u6CE8\u610F\u3002\u3069\u3053\u306B\u6301\u3063\u3066\u304F\u308B\u304B\u306B\
    \u3088\u3063\u3066\u30B0\u30EB\u30FC\u30D4\u30F3\u30B0\u3092\u8A2D\u5B9A\u3059\
    \u308B\u3002\n     */\n    int grouping(const Point& p) const {\n        /**\n\
    \         * \u504F\u89D2\u306E\u7BC4\u56F2\uFF1A[0, 2\u03C0)\n         * \u5206\
    \u5272\uFF1A[0, \u03C0/2], (\u03C0/2, \u03C0], (\u03C0, 2\u03C0)\n         * @remark\
    \ \u539F\u70B9\u306F\u3001\u5148\u982D\u306B\u6301\u3063\u3066\u304F\u308B\u3088\
    \u3046\u306B\u3057\u3066\u3044\u308B\uFF08\u3064\u307E\u308A\u3001\u504F\u89D2\
    \u30920\u3068\u307F\u306A\u3057\u3066\u3044\u308B\uFF09\u3002\n         */\n \
    \       if(p.x == 0 && p.y == 0){\n            return 0;\n        } else if(p.y\
    \ < 0){ // (\u03C0, 2\u03C0)\n            return 3;\n        } else if(p.x < 0){\
    \ // (\u03C0/2, \u03C0]\n            return 2;\n        } else{ // [0, \u03C0\
    /2]\n            return 1;\n        }\n\n        /*\n        * \u504F\u89D2\u306E\
    \u7BC4\u56F2\uFF1A(-\u03C0/2, \u03C0/2]\n        * \u5206\u5272 (-\u03C0/2, 0],\
    \ (0, \u03C0/2]\n        * @remark \u539F\u70B9\u306E\u504F\u89D2\u306F\u3001\
    0\u3068\u307F\u306A\u3057\u3066\u3044\u308B\u3002\n        */\n        /* if(p.x\
    \ == 0 && p.y == 0){ // \u539F\u70B9\n            return 0;\n        } else if(p.y\
    \ < 0 || (p.y == 0 && p.x > 0)){ // (-\u03C0/2, 0]\n            return -1;\n \
    \       } else{ // (0, \u03C0/2]\n            return 1;\n        } */\n    }\n\
    \npublic:\n    long long x, y;\n    Point() : x(0LL), y(0LL)  {}\n    Point(long\
    \ long x, long long y) : x(x), y(y) {}\n\n    bool operator!=(const Point& q)\
    \ const {\n        return x != q.x || y != q.y;\n    }\n    bool operator==(const\
    \ Point& q) const {\n        return !(*this == q);\n    }\n    /**\n     * \u70B9\
    \u306E\u6BD4\u8F03\u306F\u3001\u504F\u89D2\u306E\u5927\u304D\u3055\u306B\u3088\
    \u308B\n     */\n    bool operator<(const Point& q) const {\n        int group_p\
    \ = grouping(*this);\n        int group_q = grouping(q);\n\n        if(group_p\
    \ != group_q){\n            return group_p < group_q;\n        }\n\n        return\
    \ y * q.x < x * q.y; // p.y / p.x < q.y / q.x\n    }\n    bool operator<=(const\
    \ Point& q) const {\n        return *this < q || *this == q;\n    }\n    bool\
    \ operator>(const Point& q) const {\n        return !(*this <= q);\n    }\n  \
    \  bool operator>=(const Point& q) const {\n        return !(*this < q);\n   \
    \ }\n\n    /**\n     * \u6F14\u7B97\u306E\u5B9A\u7FA9\n     */\n    Point operator+(const\
    \ Point& p) const {\n        return Point(x + p.x, y + p.y);\n    }\n    Point\
    \ operator-(const Point& p) const {\n        return Point(x - p.x, y - p.y);\n\
    \    }\n    Point operator*(ll k) const {\n        return Point(k * x, k * y);\n\
    \    }\n    long long length2() const {\n        return x * x + y * y;\n    }\n\
    \    long long dist2(const Point& p) const {\n        return (x - p.x) * (x -\
    \ p.x) + (y - p.y) + (y - p.y);\n    }\n    long long dot(const Point& p) const\
    \ { // \u5185\u7A4D\uFF08dot product\uFF09\n        return x * p.x + y * p.y;\n\
    \    }\n    long long cross(const Point& p) const { // \u5916\u7A4D\uFF08cross\
    \ product\uFF09\n        return x * p.y - y * p.x;\n    }\n};\n\n\n"
  code: "#ifndef H_Point\n#define H_Point\n\n#include \"../Others/macros.hpp\"\n\n\
    struct Point {\nprivate:\n    /**\n     * @remark \u5927\u307E\u304B\u306B\u306F\
    \u3001\u30B0\u30EB\u30FC\u30D7\u306E\u6607\u9806\u3067\u30BD\u30FC\u30C8\u3002\
    \n     * @remark \u539F\u70B9\u306E\u6271\u3044\u306B\u6CE8\u610F\u3002\u3069\u3053\
    \u306B\u6301\u3063\u3066\u304F\u308B\u304B\u306B\u3088\u3063\u3066\u30B0\u30EB\
    \u30FC\u30D4\u30F3\u30B0\u3092\u8A2D\u5B9A\u3059\u308B\u3002\n     */\n    int\
    \ grouping(const Point& p) const {\n        /**\n         * \u504F\u89D2\u306E\
    \u7BC4\u56F2\uFF1A[0, 2\u03C0)\n         * \u5206\u5272\uFF1A[0, \u03C0/2], (\u03C0\
    /2, \u03C0], (\u03C0, 2\u03C0)\n         * @remark \u539F\u70B9\u306F\u3001\u5148\
    \u982D\u306B\u6301\u3063\u3066\u304F\u308B\u3088\u3046\u306B\u3057\u3066\u3044\
    \u308B\uFF08\u3064\u307E\u308A\u3001\u504F\u89D2\u30920\u3068\u307F\u306A\u3057\
    \u3066\u3044\u308B\uFF09\u3002\n         */\n        if(p.x == 0 && p.y == 0){\n\
    \            return 0;\n        } else if(p.y < 0){ // (\u03C0, 2\u03C0)\n   \
    \         return 3;\n        } else if(p.x < 0){ // (\u03C0/2, \u03C0]\n     \
    \       return 2;\n        } else{ // [0, \u03C0/2]\n            return 1;\n \
    \       }\n\n        /*\n        * \u504F\u89D2\u306E\u7BC4\u56F2\uFF1A(-\u03C0\
    /2, \u03C0/2]\n        * \u5206\u5272 (-\u03C0/2, 0], (0, \u03C0/2]\n        *\
    \ @remark \u539F\u70B9\u306E\u504F\u89D2\u306F\u30010\u3068\u307F\u306A\u3057\u3066\
    \u3044\u308B\u3002\n        */\n        /* if(p.x == 0 && p.y == 0){ // \u539F\
    \u70B9\n            return 0;\n        } else if(p.y < 0 || (p.y == 0 && p.x >\
    \ 0)){ // (-\u03C0/2, 0]\n            return -1;\n        } else{ // (0, \u03C0\
    /2]\n            return 1;\n        } */\n    }\n\npublic:\n    long long x, y;\n\
    \    Point() : x(0LL), y(0LL)  {}\n    Point(long long x, long long y) : x(x),\
    \ y(y) {}\n\n    bool operator!=(const Point& q) const {\n        return x !=\
    \ q.x || y != q.y;\n    }\n    bool operator==(const Point& q) const {\n     \
    \   return !(*this == q);\n    }\n    /**\n     * \u70B9\u306E\u6BD4\u8F03\u306F\
    \u3001\u504F\u89D2\u306E\u5927\u304D\u3055\u306B\u3088\u308B\n     */\n    bool\
    \ operator<(const Point& q) const {\n        int group_p = grouping(*this);\n\
    \        int group_q = grouping(q);\n\n        if(group_p != group_q){\n     \
    \       return group_p < group_q;\n        }\n\n        return y * q.x < x * q.y;\
    \ // p.y / p.x < q.y / q.x\n    }\n    bool operator<=(const Point& q) const {\n\
    \        return *this < q || *this == q;\n    }\n    bool operator>(const Point&\
    \ q) const {\n        return !(*this <= q);\n    }\n    bool operator>=(const\
    \ Point& q) const {\n        return !(*this < q);\n    }\n\n    /**\n     * \u6F14\
    \u7B97\u306E\u5B9A\u7FA9\n     */\n    Point operator+(const Point& p) const {\n\
    \        return Point(x + p.x, y + p.y);\n    }\n    Point operator-(const Point&\
    \ p) const {\n        return Point(x - p.x, y - p.y);\n    }\n    Point operator*(ll\
    \ k) const {\n        return Point(k * x, k * y);\n    }\n    long long length2()\
    \ const {\n        return x * x + y * y;\n    }\n    long long dist2(const Point&\
    \ p) const {\n        return (x - p.x) * (x - p.x) + (y - p.y) + (y - p.y);\n\
    \    }\n    long long dot(const Point& p) const { // \u5185\u7A4D\uFF08dot product\uFF09\
    \n        return x * p.x + y * p.y;\n    }\n    long long cross(const Point& p)\
    \ const { // \u5916\u7A4D\uFF08cross product\uFF09\n        return x * p.y - y\
    \ * p.x;\n    }\n};\n\n#endif // H_Point"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Point.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Point.hpp
layout: document
redirect_from:
- /library/Geometry/Point.hpp
- /library/Geometry/Point.hpp.html
title: Geometry/Point.hpp
---
