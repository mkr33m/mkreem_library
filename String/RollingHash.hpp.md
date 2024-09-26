---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "a*b mod 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
      \u30FC\u306A\u3057\u3067\u8A08\u7B97"
    links: []
  bundledCode: "#line 1 \"String/RollingHash.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <string>\n#include <random>\n\nstruct RollingHash {\nprivate:\n    using ull\
    \ = unsigned long long;\n    static const ull mod = 0x1fffffffffffffff; // 2^61-1\n\
    \    /**\n     * @param base \u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\u306E\u57FA\u5E95\
    \n     * @param hased \u90E8\u5206\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024\n     */\n    static ull base;\n    std::vector<ull> hash, power;\n\n \
    \   /**\n     * @brief a*b mod 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u306A\u3057\u3067\u8A08\u7B97\n     */\n    inline ull mul(ull a,\
    \ ull b) const {\n        ull au = a >> 31; // \u4E0A\u4F4D31\u30D3\u30C3\u30C8\
    \n        ull ad = a & ((1UL << 31) - 1); // \u4E0B\u4F4D31\u30D3\u30C3\u30C8\n\
    \        ull bu = b >> 31;\n        ull bd = b & ((1UL << 31) - 1);\n\n      \
    \  // a*b = (au*2^31+ad) * (bu*2^31+bd)\n        // = au*bu*2^62 + \"(au*bd +\
    \ ad*bu)*2^31\" + ad*bd\n        ull mid = au*bd + ad*bu;\n        ull midu =\
    \ mid >> 30; // \u4E0A\u4F4D30\u30D3\u30C3\u30C8\n        ull midd = mid & ((1UL\
    \ << 30) - 1); // \u4E0B\u4F4D30\u30D3\u30C3\u30C8\n\n        ull ans = au*bu*2\
    \ + midu + (midd << 31) + ad*bd;\n\n        ans = (ans >> 61) + (ans & mod);\n\
    \        if(ans >= mod) ans -= mod;\n        return ans;\n    }\n\npublic:\n \
    \   RollingHash(const std::string& s){\n        int N = s.size();\n        hash.assign(N\
    \ + 1, 0);\n        power.assign(N + 1, 0);\n        power[0] = 1;\n        for(int\
    \ i = 0; i < N; i++){\n            power[i + 1] = mul(power[i], base); // \u57FA\
    \u6570\u306E\u7D2F\u4E57\u3092\u8A08\u7B97\n            hash[i + 1] = mul(hash[i],\
    \ base) + s[i];\n            if(hash[i + 1] >= mod){\n                hash[i +\
    \ 1] -= mod;\n            }\n        }\n    }\n\n    /**\n     * @brief \u90E8\
    \u5206\u6587\u5B57\u5217S[l, r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8A08\
    \u7B97\n     */\n    ull get(int l, int r) const {\n        ull ret = hash[r]\
    \ + mod - mul(hash[l], power[r - l]);\n        if(ret >= mod){\n            ret\
    \ -= mod;\n        }\n        return ret;\n    }\n\n    /**\n     * @brief front\u306E\
    \u30CF\u30C3\u30B7\u30E5\u5024h1\u3068\u3001back\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024h2\u3092\u9023\u7D50\uFF08\u6587\u5B57\u5217front+back\u306E\u30CF\u30C3\
    \u30B7\u30E5\u5024\uFF09\n     */\n    ull connect(ull front_hash, ull back_hash,\
    \ int back_len) const {\n        ull ret = mul(front_hash, power[back_len]) +\
    \ back_hash;\n        if(ret >= mod){\n            ret -= mod;\n        }\n  \
    \      return ret;\n    }\n\n    /**\n     * @brief \u65E2\u5B58\u306E\u6587\u5B57\
    \u5217\u306B\u65B0\u3057\u3044\u6587\u5B57\u5217\u3092\u7D50\u5408\u3057\u3001\
    \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u518D\u69CB\u6210\n   \
    \  */\n    void rebuild(const std::string& append_str){\n        int N = hash.size()\
    \ - 1, M = append_str.size();\n        hash.resize(N + M + 1);\n        power.resize(N\
    \ + M + 1);\n        for(int i = N; i < N + M; i++){\n            power[i + 1]\
    \ = mul(power[i], base);\n            hash[i + 1] = mul(hash[i], base) + append_str[i\
    \ - N];\n            if(hash[i + 1] >= mod){\n                hash[i + 1] -= mod;\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u4E8C\u3064\u306E\u6587\
    \u5B57\u5217\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9ELCP\u3092\u8A08\u7B97\
    \u3059\u308B\n     */\n    int LCP(const RollingHash& another_str, int l1, int\
    \ r1, int l2, int r2){\n        int len = std::min(r1 - l1, r2 - l2); // \u5171\
    \u901A\u90E8\u5206\u306E\u9577\u3055\n        int low = -1, high = len + 1;\n\
    \        while(high - low > 1){\n            int mid = (low - high) / 2 + high;\n\
    \            if(get(l1, l1 + mid) == another_str.get(l2, l2 + mid)){\n       \
    \         low = mid;\n            }\n            else{\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};\n\n// \u57FA\u6570\
    \u3092\u30E9\u30F3\u30C0\u30E0\u306B\u521D\u671F\u5316\nstd::mt19937_64 mt{(unsigned\
    \ int)time(NULL)};\nRollingHash::ull RollingHash::base = mt() % RollingHash::mod;\
    \ // \uFF08\u9759\u7684\u30E1\u30F3\u30D0\u5909\u6570\u306F\u306E\u521D\u671F\u5316\
    \u306F\u3001\u30AF\u30E9\u30B9\u306E\u5916\u90E8\u3067\u884C\u3046\uFF09\n\n\n"
  code: "#ifndef RollingHash_HPP\n#define RollingHash_HPP\n\n#include <vector>\n#include\
    \ <string>\n#include <random>\n\nstruct RollingHash {\nprivate:\n    using ull\
    \ = unsigned long long;\n    static const ull mod = 0x1fffffffffffffff; // 2^61-1\n\
    \    /**\n     * @param base \u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\u306E\u57FA\u5E95\
    \n     * @param hased \u90E8\u5206\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024\n     */\n    static ull base;\n    std::vector<ull> hash, power;\n\n \
    \   /**\n     * @brief a*b mod 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u306A\u3057\u3067\u8A08\u7B97\n     */\n    inline ull mul(ull a,\
    \ ull b) const {\n        ull au = a >> 31; // \u4E0A\u4F4D31\u30D3\u30C3\u30C8\
    \n        ull ad = a & ((1UL << 31) - 1); // \u4E0B\u4F4D31\u30D3\u30C3\u30C8\n\
    \        ull bu = b >> 31;\n        ull bd = b & ((1UL << 31) - 1);\n\n      \
    \  // a*b = (au*2^31+ad) * (bu*2^31+bd)\n        // = au*bu*2^62 + \"(au*bd +\
    \ ad*bu)*2^31\" + ad*bd\n        ull mid = au*bd + ad*bu;\n        ull midu =\
    \ mid >> 30; // \u4E0A\u4F4D30\u30D3\u30C3\u30C8\n        ull midd = mid & ((1UL\
    \ << 30) - 1); // \u4E0B\u4F4D30\u30D3\u30C3\u30C8\n\n        ull ans = au*bu*2\
    \ + midu + (midd << 31) + ad*bd;\n\n        ans = (ans >> 61) + (ans & mod);\n\
    \        if(ans >= mod) ans -= mod;\n        return ans;\n    }\n\npublic:\n \
    \   RollingHash(const std::string& s){\n        int N = s.size();\n        hash.assign(N\
    \ + 1, 0);\n        power.assign(N + 1, 0);\n        power[0] = 1;\n        for(int\
    \ i = 0; i < N; i++){\n            power[i + 1] = mul(power[i], base); // \u57FA\
    \u6570\u306E\u7D2F\u4E57\u3092\u8A08\u7B97\n            hash[i + 1] = mul(hash[i],\
    \ base) + s[i];\n            if(hash[i + 1] >= mod){\n                hash[i +\
    \ 1] -= mod;\n            }\n        }\n    }\n\n    /**\n     * @brief \u90E8\
    \u5206\u6587\u5B57\u5217S[l, r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8A08\
    \u7B97\n     */\n    ull get(int l, int r) const {\n        ull ret = hash[r]\
    \ + mod - mul(hash[l], power[r - l]);\n        if(ret >= mod){\n            ret\
    \ -= mod;\n        }\n        return ret;\n    }\n\n    /**\n     * @brief front\u306E\
    \u30CF\u30C3\u30B7\u30E5\u5024h1\u3068\u3001back\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024h2\u3092\u9023\u7D50\uFF08\u6587\u5B57\u5217front+back\u306E\u30CF\u30C3\
    \u30B7\u30E5\u5024\uFF09\n     */\n    ull connect(ull front_hash, ull back_hash,\
    \ int back_len) const {\n        ull ret = mul(front_hash, power[back_len]) +\
    \ back_hash;\n        if(ret >= mod){\n            ret -= mod;\n        }\n  \
    \      return ret;\n    }\n\n    /**\n     * @brief \u65E2\u5B58\u306E\u6587\u5B57\
    \u5217\u306B\u65B0\u3057\u3044\u6587\u5B57\u5217\u3092\u7D50\u5408\u3057\u3001\
    \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u518D\u69CB\u6210\n   \
    \  */\n    void rebuild(const std::string& append_str){\n        int N = hash.size()\
    \ - 1, M = append_str.size();\n        hash.resize(N + M + 1);\n        power.resize(N\
    \ + M + 1);\n        for(int i = N; i < N + M; i++){\n            power[i + 1]\
    \ = mul(power[i], base);\n            hash[i + 1] = mul(hash[i], base) + append_str[i\
    \ - N];\n            if(hash[i + 1] >= mod){\n                hash[i + 1] -= mod;\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u4E8C\u3064\u306E\u6587\
    \u5B57\u5217\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9ELCP\u3092\u8A08\u7B97\
    \u3059\u308B\n     */\n    int LCP(const RollingHash& another_str, int l1, int\
    \ r1, int l2, int r2){\n        int len = std::min(r1 - l1, r2 - l2); // \u5171\
    \u901A\u90E8\u5206\u306E\u9577\u3055\n        int low = -1, high = len + 1;\n\
    \        while(high - low > 1){\n            int mid = (low - high) / 2 + high;\n\
    \            if(get(l1, l1 + mid) == another_str.get(l2, l2 + mid)){\n       \
    \         low = mid;\n            }\n            else{\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};\n\n// \u57FA\u6570\
    \u3092\u30E9\u30F3\u30C0\u30E0\u306B\u521D\u671F\u5316\nstd::mt19937_64 mt{(unsigned\
    \ int)time(NULL)};\nRollingHash::ull RollingHash::base = mt() % RollingHash::mod;\
    \ // \uFF08\u9759\u7684\u30E1\u30F3\u30D0\u5909\u6570\u306F\u306E\u521D\u671F\u5316\
    \u306F\u3001\u30AF\u30E9\u30B9\u306E\u5916\u90E8\u3067\u884C\u3046\uFF09\n\n#endif\
    \ // RollingHash_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.hpp
layout: document
redirect_from:
- /library/String/RollingHash.hpp
- /library/String/RollingHash.hpp.html
title: "a*b mod 2^61 - 1 \u3092\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306A\
  \u3057\u3067\u8A08\u7B97"
---
