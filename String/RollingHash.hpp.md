---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "(a * b) MOD 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\
      \u30ED\u30FC\u306A\u3057\u3067\u8A08\u7B97"
    links: []
  bundledCode: "#line 1 \"String/RollingHash.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <string>\n#include <random>\n#include <algorithm>\n#include <cassert>\n\nclass\
    \ RollingHash {\n    using ull = unsigned long long;\n    // static\uFF1A\u30A4\
    \u30F3\u30B9\u30BF\u30F3\u30B9\u9593\u3067\u306E\u307F\u5171\u6709\u3055\u308C\
    \u308B\n    static constexpr ull MOD = 0x1fffffffffffffff; // \u30CF\u30C3\u30B7\
    \u30E5\u5024\u304C\u3067\u304B\u304F\u306A\u308A\u3059\u304E\u308B\u304B\u3089\
    \u3001\u305D\u306E\u305F\u3081\u306E mod\uFF082^61 - 1\uFF09\n    /**\n     *\
    \ @param base \u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\u306E\u57FA\u5E95\n     * @param\
    \ hase \u90E8\u5206\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5024  hash[i]\
    \ \u3067 S[0, i) \u3092\u30CF\u30C3\u30B7\u30E5\u5316\u3057\u305F\u3082\u306E\n\
    \     * @param S \u30CF\u30C3\u30B7\u30E5\u5316\u3059\u308B\u6587\u5B57\u5217\n\
    \     * @param N \u30CF\u30C3\u30B7\u30E5\u5316\u3057\u305F\u6587\u5B57\u5217\u306E\
    \u9577\u3055\n     * @param initialized // \u57FA\u5E95 base \u3092\u5404\u30A4\
    \u30F3\u30B9\u30BF\u30F3\u30B9\u3067\u5171\u6709\u3059\u308B\u305F\u3081\u306E\
    \u30D5\u30E9\u30B0\n     **/\n    inline static ull base = 0; // \u521D\u671F\u5316\
    \n    std::vector<ull> hash, rhash, power;\n    std::string S;\n    int N;\n \
    \   inline static bool initialized = false; // \u521D\u671F\u5316\n\npublic:\n\
    \    /**\n     * @brief (a * b) MOD 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u306A\u3057\u3067\u8A08\u7B97\n     */\n    // inline : \u3079\
    \u305F\u5F35\u308A\u5C55\u958B\uFF08\u95A2\u6570\u547C\u3073\u51FA\u3057\u306E\
    \u305F\u3073\u306B\u305D\u306E\u95A2\u6570\u306E\u30E1\u30E2\u30EA\u306E\u4F4D\
    \u7F6E\u306B\u79FB\u52D5\u3057\u306A\u304F\u3066\u3088\u3044\uFF09\n    // static\uFF08\
    \u30E1\u30F3\u30D0\u95A2\u6570\uFF09: RollingHash::mul(...) \u306E\u3088\u3046\
    \u306B\u3001\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u751F\u6210\u3057\u306A\
    \u304F\u3066\u3082\u5229\u7528\u53EF\u80FD\u3002\u305F\u3060\u3057\u3001\u975E\
    \ static \u30E1\u30F3\u30D0\u306B\u89E6\u308C\u308B\u3053\u3068\u306F\u3067\u304D\
    \u306A\u3044\u3002\u7D50\u5C40\u3001\u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\u306B\
    \u7D10\u3065\u304B\u306A\u3044\u7C21\u5358\u306A\u8A08\u7B97\u30EB\u30FC\u30C1\
    \u30F3\u3067\u3042\u308B\uFF08\u3051\u3069\u3001\u30AF\u30E9\u30B9\u306E\u4EF2\
    \u9593\u3068\u3057\u3066\u7F6E\u3044\u3066\u3044\u308B\uFF09\u3053\u3068\u3092\
    \u660E\u793A\u3057\u3066\u304A\u304F\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \n    static inline ull mul(ull a, ull b) {\n        ull aq = a >> 31; // \u4E0A\
    \u4F4D 31 \u30D3\u30C3\u30C8\uFF08a \u3092 2^31 \u3067\u5272\u3063\u305F\u5546\
    \uFF09\n        ull ar = a & ((1UL << 31) - 1); // \u4E0B\u4F4D 31 \u30D3\u30C3\
    \u30C8\uFF08b \u3092 2^31 \u3067\u5272\u3063\u305F\u4F59\u308A\uFF09\n       \
    \ ull bq = b >> 31;\n        ull br = b & ((1UL << 31) - 1);\n        // -> a\
    \ * b = aq * bq * 2^62\n                    // + (aq * br + ar * bq) * 2^31\n\
    \                    // + ar * br\n        \n        ull mid = aq * br + ar *\
    \ bq; // -> 2^30 \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u8003\u3048\
    \u3066\u307F\u308B\uFF082^31 * 2^30 == 2^61 \u3060\u304B\u3089\uFF09\n       \
    \ ull midq = mid >> 30; // \u4E0A\u4F4D 30 \u30D3\u30C3\u30C8\uFF08mid \u3092\
    \ 2^30 \u3067\u5272\u3063\u305F\u5546\uFF09\n        ull midr = mid & ((1UL <<\
    \ 30) - 1); // \u4E0B\u4F4D 30 \u30D3\u30C3\u30C8\uFF08mid \u3092 2^30 \u3067\u5272\
    \u3063\u305F\u4F59\u308A\uFF09\n\n        ull ans = aq * bq * 2 + midq + (midr\
    \ << 31) + ar * br;\n\n        // ans \u306E MOD 2^61 - 1 \u3092\u6C42\u3081\u305F\
    \u3044\n        // ans = ansq * 2^61 + ansr \u3068\u3059\u308B\u3068\u3001ans\
    \ \u2261 ansq + ansr\n        // ans < 2^64 \u3088\u308A\u3001ansq < 2^3 \u3060\
    \u304B\u3089\u3001\n        // ansq + ansr < 2^3 + 2^61\n        // ansq + ansr\
    \ - 2^61 < 2^3\n        // \u5272\u308B\u306E\u3067\u306F\u306A\u304F\u3066\u3001\
    2^61 \u3092\u5F15\u304F\u3060\u3051\u3067\u3088\u3044\uFF08\u5143\u3005\u5272\u308B\
    \u5FC5\u8981\u304C\u306A\u3044\u305B\u3044\u3067\u5F15\u304D\u3059\u304E\u305F\
    \u306A\u3089\u30012^61 \u3092\u8DB3\u305B\u3070\u3088\u3044\uFF09\u3002\n    \
    \    ans = (ans >> 61) + (ans & MOD);\n        if (ans >= MOD) {\n           \
    \ ans -= MOD;\n        }\n        return ans;\n    }\n\n    RollingHash(const\
    \ std::string& S) : S(S), N((int)S.size()) {\n        if (!initialized) {\n  \
    \          std::mt19937_64 mt{ std::random_device{}() };\n            std::uniform_int_distribution<long\
    \ long> ran(0, std::numeric_limits<long long>::max());\n            base = ran(mt)\
    \ % MOD; // \u57FA\u5E95\u3092\uFF08\u30E9\u30F3\u30C0\u30E0\u306B\uFF09\u8A2D\
    \u5B9A\u3002\u3082\u3061\u308D\u3093 MOD \u672A\u6E80\u3067\u53D6\u3063\u3066\u304F\
    \u308B\u3002\n            initialized = true;\n        }\n\n        std::string\
    \ revS = S;\n        std::reverse(revS.begin(), revS.end());\n        hash.assign(N\
    \ + 1, 0);\n        rhash.assign(N + 1, 0);\n        power.assign(N + 1, 0);\n\
    \        power[0] = 1;\n        for (int i = 0; i < N; i++) {\n            power[i\
    \ + 1] = mul(power[i], base); // \u57FA\u6570\u306E\u7D2F\u4E57\u3092\u8A08\u7B97\
    \n            // hash(S[0, N+1)) = hash(S[0, N)) * base + S[N]\n            //\
    \ hash(S[l, r)) = hash(S[0, r)) - hash(S[0, l)) * base^{r-l}\n            hash[i\
    \ + 1] = mul(hash[i], base) + S[i];\n            if (hash[i + 1] >= MOD) {\n \
    \               hash[i + 1] -= MOD;\n            }\n            rhash[i + 1] =\
    \ mul(rhash[i], base) + revS[i];\n            if (rhash[i + 1] >= MOD) {\n   \
    \             rhash[i + 1] -= MOD;\n            }\n        }\n    }\n\n    /**\n\
    \     * @brief \u90E8\u5206\u6587\u5B57\u5217 S[l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u3092\u8A08\u7B97\n     */\n    // const : \u30E1\u30F3\u30D0\u3092\
    \u5909\u66F4\u3059\u308B\u3053\u3068\u3092\u8A31\u3055\u306A\u3044\u3088\u3046\
    \u306B\u3059\u308B\uFF08\u3082\u3057\u5909\u3048\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3089\u3001\u30A8\u30E9\u30FC\u3092\u5410\u3044\u3066\u304F\u308C\
    \u308B\uFF09\u3002\u3064\u307E\u308A\u3001\u8AAD\u307F\u53D6\u308A\u5C02\u7528\
    \u30C7\u30A2\u30EB\u3053\u3068\u3092\u660E\u793A\u7684\u306B\u5BA3\u8A00\u3059\
    \u308B\u3002\u53C2\u7167\u7CFB\u3001\u66F4\u65B0\u7CFB\u306E\u3069\u3061\u3089\
    \u304B\u304C\u4E00\u76EE\u3067\u308F\u304B\u3063\u3066\u5B09\u3057\u3044\u3002\
    \n    ull get(int l, int r) const {\n        assert(l <= r);\n        ull res\
    \ = hash[r] + MOD - mul(hash[l], power[r - l]);\n        if (res >= MOD) {\n \
    \           res -= MOD;\n        }\n        return res;\n    }\n\n    ull get_rev(int\
    \ l, int r) const {\n        assert(l <= r);\n        ull res = rhash[r] + MOD\
    \ - mul(rhash[l], power[r - l]);\n        if (res >= MOD) {\n            res -=\
    \ MOD;\n        }\n        return res;\n    };\n\n    /**\n     * @brief front\
    \ \u306E\u30CF\u30C3\u30B7\u30E5\u5024 h1 \u3068\u3001back \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024 h2 \u3092\u9023\u7D50\uFF08\u6587\u5B57\u5217 front + back \u306E\
    \u30CF\u30C3\u30B7\u30E5\u5024\uFF09\n     * @remark front_hash, back_hash \u306E\
    \ base \u304C\u4E00\u81F4\u3057\u3066\u3044\u306A\u3044\u3068\u7834\u7DBB\u3059\
    \u308B\u6C17\u304C\u3059\u308B\u3002\n     */\n    ull connect(ull front_hash,\
    \ ull back_hash, int back_len) const {\n        ull res = mul(front_hash, power[back_len])\
    \ + back_hash;\n        if (res >= MOD) {\n            res -= MOD;\n        }\n\
    \        return res;\n    }\n\n    /**\n     * @brief \u65E2\u5B58\u306E\u6587\
    \u5B57\u5217\u306B\u65B0\u3057\u3044\u6587\u5B57\u5217\u3092\u7D50\u5408\u3057\
    \u3001\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u518D\u69CB\u6210\
    \uFF08M \u5EF6\u9577\u3057\u3066\u3001idx \u306E N \u4EE5\u964D\u3092\u69CB\u7BC9\
    \u3059\u308B\uFF09\u3002\n     */ \n    void rebuild(const std::string& T) {\n\
    \n        int prevN = N;\n        int M = (int)T.size();\n        S += T; // S\
    \ \u306E\u66F4\u65B0\n        N += M; // N \u306E\u66F4\u65B0\n        hash.resize(N\
    \ + 1);\n        rhash.assign(N + 1, 0);\n        power.resize(N + 1);\n\n   \
    \     for (int i = prevN; i < N; i++) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hash[i + 1] = mul(hash[i], base) + T[i - prevN];\n     \
    \       if (hash[i + 1] >= MOD) {\n                hash[i + 1] -= MOD;\n     \
    \       }\n        }\n        std::string revS = S;\n        std::reverse(revS.begin(),\
    \ revS.end());\n        for (int i = 0; i < N; i++) {\n            rhash[i + 1]\
    \ = mul(rhash[i], base) + revS[i];\n            if (rhash[i + 1] >= MOD) {\n \
    \               rhash[i + 1] -= MOD;\n            }\n        }\n    }\n\n    /**\n\
    \     * @brief \u4E8C\u3064\u306E\u6587\u5B57\u5217\u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9ELCP\u3092\u8A08\u7B97\u3059\u308B\n     */\n    int LCP(const\
    \ RollingHash& T, int l1, int r1, int l2, int r2) const {\n        int len = std::min(r1\
    \ - l1, r2 - l2); // \u5171\u901A\u90E8\u5206\u306E\u9577\u3055\n        int ok\
    \ = -1, ng = len + 1;\n        while (ng - ok > 1) {\n            int mid = (ok\
    \ + ng) >> 1;\n            if (get(l1, l1 + mid) == T.get(l2, l2 + mid)) {\n \
    \               ok = mid;\n            } else {\n                ng = mid;\n \
    \           }\n        }\n        return ok;\n    }\n\n    /**\n     * @brief\
    \ S[l, r) \u304C\u56DE\u6587\u3067\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\n     */\n    bool is_palindrome(int l, int r) const {\n  \
    \      return get(l, r) == get_rev(N - r, N - l);\n    }\n};\n\n\n"
  code: "#ifndef RollingHash_HPP\n#define RollingHash_HPP\n\n#include <vector>\n#include\
    \ <string>\n#include <random>\n#include <algorithm>\n#include <cassert>\n\nclass\
    \ RollingHash {\n    using ull = unsigned long long;\n    // static\uFF1A\u30A4\
    \u30F3\u30B9\u30BF\u30F3\u30B9\u9593\u3067\u306E\u307F\u5171\u6709\u3055\u308C\
    \u308B\n    static constexpr ull MOD = 0x1fffffffffffffff; // \u30CF\u30C3\u30B7\
    \u30E5\u5024\u304C\u3067\u304B\u304F\u306A\u308A\u3059\u304E\u308B\u304B\u3089\
    \u3001\u305D\u306E\u305F\u3081\u306E mod\uFF082^61 - 1\uFF09\n    /**\n     *\
    \ @param base \u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\u306E\u57FA\u5E95\n     * @param\
    \ hase \u90E8\u5206\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5024  hash[i]\
    \ \u3067 S[0, i) \u3092\u30CF\u30C3\u30B7\u30E5\u5316\u3057\u305F\u3082\u306E\n\
    \     * @param S \u30CF\u30C3\u30B7\u30E5\u5316\u3059\u308B\u6587\u5B57\u5217\n\
    \     * @param N \u30CF\u30C3\u30B7\u30E5\u5316\u3057\u305F\u6587\u5B57\u5217\u306E\
    \u9577\u3055\n     * @param initialized // \u57FA\u5E95 base \u3092\u5404\u30A4\
    \u30F3\u30B9\u30BF\u30F3\u30B9\u3067\u5171\u6709\u3059\u308B\u305F\u3081\u306E\
    \u30D5\u30E9\u30B0\n     **/\n    inline static ull base = 0; // \u521D\u671F\u5316\
    \n    std::vector<ull> hash, rhash, power;\n    std::string S;\n    int N;\n \
    \   inline static bool initialized = false; // \u521D\u671F\u5316\n\npublic:\n\
    \    /**\n     * @brief (a * b) MOD 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u306A\u3057\u3067\u8A08\u7B97\n     */\n    // inline : \u3079\
    \u305F\u5F35\u308A\u5C55\u958B\uFF08\u95A2\u6570\u547C\u3073\u51FA\u3057\u306E\
    \u305F\u3073\u306B\u305D\u306E\u95A2\u6570\u306E\u30E1\u30E2\u30EA\u306E\u4F4D\
    \u7F6E\u306B\u79FB\u52D5\u3057\u306A\u304F\u3066\u3088\u3044\uFF09\n    // static\uFF08\
    \u30E1\u30F3\u30D0\u95A2\u6570\uFF09: RollingHash::mul(...) \u306E\u3088\u3046\
    \u306B\u3001\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u751F\u6210\u3057\u306A\
    \u304F\u3066\u3082\u5229\u7528\u53EF\u80FD\u3002\u305F\u3060\u3057\u3001\u975E\
    \ static \u30E1\u30F3\u30D0\u306B\u89E6\u308C\u308B\u3053\u3068\u306F\u3067\u304D\
    \u306A\u3044\u3002\u7D50\u5C40\u3001\u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\u306B\
    \u7D10\u3065\u304B\u306A\u3044\u7C21\u5358\u306A\u8A08\u7B97\u30EB\u30FC\u30C1\
    \u30F3\u3067\u3042\u308B\uFF08\u3051\u3069\u3001\u30AF\u30E9\u30B9\u306E\u4EF2\
    \u9593\u3068\u3057\u3066\u7F6E\u3044\u3066\u3044\u308B\uFF09\u3053\u3068\u3092\
    \u660E\u793A\u3057\u3066\u304A\u304F\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \n    static inline ull mul(ull a, ull b) {\n        ull aq = a >> 31; // \u4E0A\
    \u4F4D 31 \u30D3\u30C3\u30C8\uFF08a \u3092 2^31 \u3067\u5272\u3063\u305F\u5546\
    \uFF09\n        ull ar = a & ((1UL << 31) - 1); // \u4E0B\u4F4D 31 \u30D3\u30C3\
    \u30C8\uFF08b \u3092 2^31 \u3067\u5272\u3063\u305F\u4F59\u308A\uFF09\n       \
    \ ull bq = b >> 31;\n        ull br = b & ((1UL << 31) - 1);\n        // -> a\
    \ * b = aq * bq * 2^62\n                    // + (aq * br + ar * bq) * 2^31\n\
    \                    // + ar * br\n        \n        ull mid = aq * br + ar *\
    \ bq; // -> 2^30 \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u8003\u3048\
    \u3066\u307F\u308B\uFF082^31 * 2^30 == 2^61 \u3060\u304B\u3089\uFF09\n       \
    \ ull midq = mid >> 30; // \u4E0A\u4F4D 30 \u30D3\u30C3\u30C8\uFF08mid \u3092\
    \ 2^30 \u3067\u5272\u3063\u305F\u5546\uFF09\n        ull midr = mid & ((1UL <<\
    \ 30) - 1); // \u4E0B\u4F4D 30 \u30D3\u30C3\u30C8\uFF08mid \u3092 2^30 \u3067\u5272\
    \u3063\u305F\u4F59\u308A\uFF09\n\n        ull ans = aq * bq * 2 + midq + (midr\
    \ << 31) + ar * br;\n\n        // ans \u306E MOD 2^61 - 1 \u3092\u6C42\u3081\u305F\
    \u3044\n        // ans = ansq * 2^61 + ansr \u3068\u3059\u308B\u3068\u3001ans\
    \ \u2261 ansq + ansr\n        // ans < 2^64 \u3088\u308A\u3001ansq < 2^3 \u3060\
    \u304B\u3089\u3001\n        // ansq + ansr < 2^3 + 2^61\n        // ansq + ansr\
    \ - 2^61 < 2^3\n        // \u5272\u308B\u306E\u3067\u306F\u306A\u304F\u3066\u3001\
    2^61 \u3092\u5F15\u304F\u3060\u3051\u3067\u3088\u3044\uFF08\u5143\u3005\u5272\u308B\
    \u5FC5\u8981\u304C\u306A\u3044\u305B\u3044\u3067\u5F15\u304D\u3059\u304E\u305F\
    \u306A\u3089\u30012^61 \u3092\u8DB3\u305B\u3070\u3088\u3044\uFF09\u3002\n    \
    \    ans = (ans >> 61) + (ans & MOD);\n        if (ans >= MOD) {\n           \
    \ ans -= MOD;\n        }\n        return ans;\n    }\n\n    RollingHash(const\
    \ std::string& S) : S(S), N((int)S.size()) {\n        if (!initialized) {\n  \
    \          std::mt19937_64 mt{ std::random_device{}() };\n            std::uniform_int_distribution<long\
    \ long> ran(0, std::numeric_limits<long long>::max());\n            base = ran(mt)\
    \ % MOD; // \u57FA\u5E95\u3092\uFF08\u30E9\u30F3\u30C0\u30E0\u306B\uFF09\u8A2D\
    \u5B9A\u3002\u3082\u3061\u308D\u3093 MOD \u672A\u6E80\u3067\u53D6\u3063\u3066\u304F\
    \u308B\u3002\n            initialized = true;\n        }\n\n        std::string\
    \ revS = S;\n        std::reverse(revS.begin(), revS.end());\n        hash.assign(N\
    \ + 1, 0);\n        rhash.assign(N + 1, 0);\n        power.assign(N + 1, 0);\n\
    \        power[0] = 1;\n        for (int i = 0; i < N; i++) {\n            power[i\
    \ + 1] = mul(power[i], base); // \u57FA\u6570\u306E\u7D2F\u4E57\u3092\u8A08\u7B97\
    \n            // hash(S[0, N+1)) = hash(S[0, N)) * base + S[N]\n            //\
    \ hash(S[l, r)) = hash(S[0, r)) - hash(S[0, l)) * base^{r-l}\n            hash[i\
    \ + 1] = mul(hash[i], base) + S[i];\n            if (hash[i + 1] >= MOD) {\n \
    \               hash[i + 1] -= MOD;\n            }\n            rhash[i + 1] =\
    \ mul(rhash[i], base) + revS[i];\n            if (rhash[i + 1] >= MOD) {\n   \
    \             rhash[i + 1] -= MOD;\n            }\n        }\n    }\n\n    /**\n\
    \     * @brief \u90E8\u5206\u6587\u5B57\u5217 S[l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u3092\u8A08\u7B97\n     */\n    // const : \u30E1\u30F3\u30D0\u3092\
    \u5909\u66F4\u3059\u308B\u3053\u3068\u3092\u8A31\u3055\u306A\u3044\u3088\u3046\
    \u306B\u3059\u308B\uFF08\u3082\u3057\u5909\u3048\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3089\u3001\u30A8\u30E9\u30FC\u3092\u5410\u3044\u3066\u304F\u308C\
    \u308B\uFF09\u3002\u3064\u307E\u308A\u3001\u8AAD\u307F\u53D6\u308A\u5C02\u7528\
    \u30C7\u30A2\u30EB\u3053\u3068\u3092\u660E\u793A\u7684\u306B\u5BA3\u8A00\u3059\
    \u308B\u3002\u53C2\u7167\u7CFB\u3001\u66F4\u65B0\u7CFB\u306E\u3069\u3061\u3089\
    \u304B\u304C\u4E00\u76EE\u3067\u308F\u304B\u3063\u3066\u5B09\u3057\u3044\u3002\
    \n    ull get(int l, int r) const {\n        assert(l <= r);\n        ull res\
    \ = hash[r] + MOD - mul(hash[l], power[r - l]);\n        if (res >= MOD) {\n \
    \           res -= MOD;\n        }\n        return res;\n    }\n\n    ull get_rev(int\
    \ l, int r) const {\n        assert(l <= r);\n        ull res = rhash[r] + MOD\
    \ - mul(rhash[l], power[r - l]);\n        if (res >= MOD) {\n            res -=\
    \ MOD;\n        }\n        return res;\n    };\n\n    /**\n     * @brief front\
    \ \u306E\u30CF\u30C3\u30B7\u30E5\u5024 h1 \u3068\u3001back \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024 h2 \u3092\u9023\u7D50\uFF08\u6587\u5B57\u5217 front + back \u306E\
    \u30CF\u30C3\u30B7\u30E5\u5024\uFF09\n     * @remark front_hash, back_hash \u306E\
    \ base \u304C\u4E00\u81F4\u3057\u3066\u3044\u306A\u3044\u3068\u7834\u7DBB\u3059\
    \u308B\u6C17\u304C\u3059\u308B\u3002\n     */\n    ull connect(ull front_hash,\
    \ ull back_hash, int back_len) const {\n        ull res = mul(front_hash, power[back_len])\
    \ + back_hash;\n        if (res >= MOD) {\n            res -= MOD;\n        }\n\
    \        return res;\n    }\n\n    /**\n     * @brief \u65E2\u5B58\u306E\u6587\
    \u5B57\u5217\u306B\u65B0\u3057\u3044\u6587\u5B57\u5217\u3092\u7D50\u5408\u3057\
    \u3001\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u518D\u69CB\u6210\
    \uFF08M \u5EF6\u9577\u3057\u3066\u3001idx \u306E N \u4EE5\u964D\u3092\u69CB\u7BC9\
    \u3059\u308B\uFF09\u3002\n     */ \n    void rebuild(const std::string& T) {\n\
    \n        int prevN = N;\n        int M = (int)T.size();\n        S += T; // S\
    \ \u306E\u66F4\u65B0\n        N += M; // N \u306E\u66F4\u65B0\n        hash.resize(N\
    \ + 1);\n        rhash.assign(N + 1, 0);\n        power.resize(N + 1);\n\n   \
    \     for (int i = prevN; i < N; i++) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hash[i + 1] = mul(hash[i], base) + T[i - prevN];\n     \
    \       if (hash[i + 1] >= MOD) {\n                hash[i + 1] -= MOD;\n     \
    \       }\n        }\n        std::string revS = S;\n        std::reverse(revS.begin(),\
    \ revS.end());\n        for (int i = 0; i < N; i++) {\n            rhash[i + 1]\
    \ = mul(rhash[i], base) + revS[i];\n            if (rhash[i + 1] >= MOD) {\n \
    \               rhash[i + 1] -= MOD;\n            }\n        }\n    }\n\n    /**\n\
    \     * @brief \u4E8C\u3064\u306E\u6587\u5B57\u5217\u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9ELCP\u3092\u8A08\u7B97\u3059\u308B\n     */\n    int LCP(const\
    \ RollingHash& T, int l1, int r1, int l2, int r2) const {\n        int len = std::min(r1\
    \ - l1, r2 - l2); // \u5171\u901A\u90E8\u5206\u306E\u9577\u3055\n        int ok\
    \ = -1, ng = len + 1;\n        while (ng - ok > 1) {\n            int mid = (ok\
    \ + ng) >> 1;\n            if (get(l1, l1 + mid) == T.get(l2, l2 + mid)) {\n \
    \               ok = mid;\n            } else {\n                ng = mid;\n \
    \           }\n        }\n        return ok;\n    }\n\n    /**\n     * @brief\
    \ S[l, r) \u304C\u56DE\u6587\u3067\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\n     */\n    bool is_palindrome(int l, int r) const {\n  \
    \      return get(l, r) == get_rev(N - r, N - l);\n    }\n};\n\n#endif // RollingHash_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.hpp
  requiredBy: []
  timestamp: '2025-05-14 10:11:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.hpp
layout: document
redirect_from:
- /library/String/RollingHash.hpp
- /library/String/RollingHash.hpp.html
title: "(a * b) MOD 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
  \u306A\u3057\u3067\u8A08\u7B97"
---
