---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u3001\u30CF\u30C3\u30B7\
      \u30E5\u5024\u3092\u5272\u308A\u5F53\u3066\u308B"
    links: []
  bundledCode: "#line 1 \"Others/ZobristHash.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <set>\n#include <map>\n#include <unordered_set>\n#include <limits>\n#include\
    \ <algorithm>\n#include <random>\n\n#line 1 \"Others/macros.hpp\"\n\n\n\n#line\
    \ 5 \"Others/macros.hpp\"\n#include <queue>\n#include <cmath>\n\nusing ll = long\
    \ long;\nusing lll = __int128_t;\nusing ld = long double;\n#define newl '\\n'\n\
    #define REF const auto&\n#define INF 1000390039\n#define LLINF 1000000039000000039\n\
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
    \ 13 \"Others/ZobristHash.hpp\"\n\ntemplate <typename T>\nstruct ZobristHash {\n\
    private:\n    std::map<T, int> hash;\n\npublic:\n    /**\n     * @brief \u5404\
    \u8981\u7D20\u306B\u5BFE\u3057\u3066\u3001\u30CF\u30C3\u30B7\u30E5\u5024\u3092\
    \u5272\u308A\u5F53\u3066\u308B\n     * @remark \u8907\u6570\u306E vector \u3092\
    \u540C\u6642\u306B\u6E21\u3059\u3053\u3068\u304C\u3067\u304D\u308B\n     */\n\
    \    template <typename... Args>\n    ZobristHash(const Args&... vecs){\n    \
    \    std::vector<T> merged;\n\n        (merged.insert(merged.end(), vecs.begin(),\
    \ vecs.end()), ...);\n\n        std::sort(merged.begin(), merged.end());\n   \
    \     merged.erase(std::unique(merged.begin(), merged.end()), merged.end());\n\
    \n        std::random_device rd;\n        std::mt19937 mt(rd());\n        std::uniform_int_distribution<int>\
    \ ran(0, std::numeric_limits<int>::max());\n\n        for(const auto& e : merged){\n\
    \            hash[e] = ran(mt);\n        }\n    }\n\n    /**\n     * @brief \u5F15\
    \u6570\u306B\u5272\u308A\u5F53\u3066\u3089\u308C\u305F\u30CF\u30C3\u30B7\u30E5\
    \u5024\u3092\u8FD4\u3059\n     */\n    int val(const T& e){\n        assert(hash.find(e)\
    \ != hash.end());\n        return hash[e];\n    }\n\n    /**\n     * @brief \u5404\
    \u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u306E XOR \u3092\u53D6\u308B\
    \ ver\n     * @remark set \u3068\u3057\u3066\uFF08multiset \u3067\u306F\u306A\u3044\
    \uFF01\uFF09\u306E\u4E00\u81F4\u5224\u5B9A\u3092 O(1) \u3067\u884C\u3046\u3053\
    \u3068\u304C\u3067\u304D\u308B\n     * @return \u5F15\u6570\u3067\u6E21\u3055\u308C\
    \u305F vector<T> vec \u306E\u3001\u5404\u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024\u306E\u7D2F\u7A4DXOR\u3092\u53D6\u3063\u305F\u3082\u306E\n     */\n   \
    \ std::vector<ll> xor_hash(const std::vector<T>& vec){\n        int N = vec.size();\n\
    \        std::vector<ll> hashed_vec(N + 1);\n        std::unordered_set<T> memo;\n\
    \n        for(int i = 0; i < N; i++){\n            if(memo.find(vec[i]) == memo.end()){\n\
    \                memo.insert(vec[i]);\n                hashed_vec[i + 1] = hashed_vec[i]\
    \ ^ val(vec[i]);\n            } else{\n                hashed_vec[i + 1] = hashed_vec[i];\n\
    \            }\n        }\n\n        return hashed_vec;\n    }\n\n    /**\n  \
    \   * @brief \u5404\u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u306E\u7D2F\
    \u7A4D\u548C\u3092\u3068\u308B ver\n     * @remark multiset \u3068\u3057\u3066\
    \u306E\u4E00\u81F4\u5224\u5B9A\u3092 O(1) \u3067\u884C\u3046\u3053\u3068\u304C\
    \u3067\u304D\u308B\n     * @return \u5F15\u6570\u3067\u6E21\u3055\u308C\u305F\
    \ vector<T> vec \u306E\u3001\u5404\u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \u306E\u7D2F\u7A4D\u548C\u3092\u53D6\u3063\u305F\u3082\u306E\n     */\n    std::vector<ll>\
    \ pref_hash(const std::vector<T>& vec){\n        int N = vec.size();\n       \
    \ std::vector<ll> hashed_vec(N + 1);\n\n        for(int i = 0; i < N; i++){\n\
    \            hashed_vec[i + 1] = hashed_vec[i] + val(vec[i]);\n        }\n\n \
    \       return hashed_vec;\n    }\n};\n\n\n"
  code: "#ifndef ZobristHash_HPP\n#define ZobristHash_HPP\n\n#include <vector>\n#include\
    \ <set>\n#include <map>\n#include <unordered_set>\n#include <limits>\n#include\
    \ <algorithm>\n#include <random>\n\n#include \"macros.hpp\"\n\ntemplate <typename\
    \ T>\nstruct ZobristHash {\nprivate:\n    std::map<T, int> hash;\n\npublic:\n\
    \    /**\n     * @brief \u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u3001\u30CF\
    \u30C3\u30B7\u30E5\u5024\u3092\u5272\u308A\u5F53\u3066\u308B\n     * @remark \u8907\
    \u6570\u306E vector \u3092\u540C\u6642\u306B\u6E21\u3059\u3053\u3068\u304C\u3067\
    \u304D\u308B\n     */\n    template <typename... Args>\n    ZobristHash(const\
    \ Args&... vecs){\n        std::vector<T> merged;\n\n        (merged.insert(merged.end(),\
    \ vecs.begin(), vecs.end()), ...);\n\n        std::sort(merged.begin(), merged.end());\n\
    \        merged.erase(std::unique(merged.begin(), merged.end()), merged.end());\n\
    \n        std::random_device rd;\n        std::mt19937 mt(rd());\n        std::uniform_int_distribution<int>\
    \ ran(0, std::numeric_limits<int>::max());\n\n        for(const auto& e : merged){\n\
    \            hash[e] = ran(mt);\n        }\n    }\n\n    /**\n     * @brief \u5F15\
    \u6570\u306B\u5272\u308A\u5F53\u3066\u3089\u308C\u305F\u30CF\u30C3\u30B7\u30E5\
    \u5024\u3092\u8FD4\u3059\n     */\n    int val(const T& e){\n        assert(hash.find(e)\
    \ != hash.end());\n        return hash[e];\n    }\n\n    /**\n     * @brief \u5404\
    \u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u306E XOR \u3092\u53D6\u308B\
    \ ver\n     * @remark set \u3068\u3057\u3066\uFF08multiset \u3067\u306F\u306A\u3044\
    \uFF01\uFF09\u306E\u4E00\u81F4\u5224\u5B9A\u3092 O(1) \u3067\u884C\u3046\u3053\
    \u3068\u304C\u3067\u304D\u308B\n     * @return \u5F15\u6570\u3067\u6E21\u3055\u308C\
    \u305F vector<T> vec \u306E\u3001\u5404\u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024\u306E\u7D2F\u7A4DXOR\u3092\u53D6\u3063\u305F\u3082\u306E\n     */\n   \
    \ std::vector<ll> xor_hash(const std::vector<T>& vec){\n        int N = vec.size();\n\
    \        std::vector<ll> hashed_vec(N + 1);\n        std::unordered_set<T> memo;\n\
    \n        for(int i = 0; i < N; i++){\n            if(memo.find(vec[i]) == memo.end()){\n\
    \                memo.insert(vec[i]);\n                hashed_vec[i + 1] = hashed_vec[i]\
    \ ^ val(vec[i]);\n            } else{\n                hashed_vec[i + 1] = hashed_vec[i];\n\
    \            }\n        }\n\n        return hashed_vec;\n    }\n\n    /**\n  \
    \   * @brief \u5404\u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u306E\u7D2F\
    \u7A4D\u548C\u3092\u3068\u308B ver\n     * @remark multiset \u3068\u3057\u3066\
    \u306E\u4E00\u81F4\u5224\u5B9A\u3092 O(1) \u3067\u884C\u3046\u3053\u3068\u304C\
    \u3067\u304D\u308B\n     * @return \u5F15\u6570\u3067\u6E21\u3055\u308C\u305F\
    \ vector<T> vec \u306E\u3001\u5404\u8981\u7D20\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \u306E\u7D2F\u7A4D\u548C\u3092\u53D6\u3063\u305F\u3082\u306E\n     */\n    std::vector<ll>\
    \ pref_hash(const std::vector<T>& vec){\n        int N = vec.size();\n       \
    \ std::vector<ll> hashed_vec(N + 1);\n\n        for(int i = 0; i < N; i++){\n\
    \            hashed_vec[i + 1] = hashed_vec[i] + val(vec[i]);\n        }\n\n \
    \       return hashed_vec;\n    }\n};\n\n#endif // ZobristHash_HPP"
  dependsOn:
  - Others/macros.hpp
  isVerificationFile: false
  path: Others/ZobristHash.hpp
  requiredBy: []
  timestamp: '2024-09-26 23:38:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/ZobristHash.hpp
layout: document
redirect_from:
- /library/Others/ZobristHash.hpp
- /library/Others/ZobristHash.hpp.html
title: "\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u3001\u30CF\u30C3\u30B7\u30E5\u5024\
  \u3092\u5272\u308A\u5F53\u3066\u308B"
---
