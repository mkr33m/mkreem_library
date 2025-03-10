---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "N\u306E\u7D20\u56E0\u6570\u306E\u7D50\u679C\u304B\u3089\u3001\
      N\u306E\u7D04\u6570\u3092\u5217\u6319\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"Math/osa_k.hpp\"\n\n\n\n#include <vector>\n#include <map>\n\
    #include <tuple>\n\nstruct osa_k {\nprivate:\n    using ll = long long;\n    ll\
    \ N;\n    std::vector<int> min_factor;\n    std::vector<int> primes;\n\npublic:\n\
    \    /**\n     * @rem O(Nlog(N))\n     */\n    osa_k(ll N) : N(N) {\n        min_factor.assign(N\
    \ + 1, 0);\n        for (int i = 2; i <= N; i++) {\n            if (min_factor[i]\
    \ == 0) {\n                min_factor[i] = i;\n                primes.push_back(i);\n\
    \            }\n            for (int p : primes) {\n                if (p > min_factor[i]\
    \ || (ll)i * p > N) {\n                    break;\n                }\n       \
    \         min_factor[i * p] = p;\n            }\n        }\n        if (N >= 0)\
    \ {\n            min_factor[0] = -1;\n        }\n        if (N >= 1) {\n     \
    \       min_factor[1] = -1;\n        }\n    }\n\n    /**\n     * @rem O(log(N))\n\
    \     */\n    std::vector<std::pair<ll, ll>> prime_factorize(ll N) {\n       \
    \ std::vector<std::pair<ll, ll>> ret;\n        while (N != 1) {\n            int\
    \ factor = min_factor[N];\n            if (ret.empty() || ret.back().first !=\
    \ factor) {\n                ret.push_back({factor, 1});\n            } else {\n\
    \                ret.back().second++;\n            }\n            N /= factor;\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief N\u306E\u7D20\
    \u56E0\u6570\u306E\u7D50\u679C\u304B\u3089\u3001N\u306E\u7D04\u6570\u3092\u5217\
    \u6319\u3059\u308B\n     * @param idx \u4F55\u756A\u76EE\u306E\u7D20\u56E0\u6570\
    \u3092\u898B\u3066\u3044\u308B\u304B\n     * @remark O(log(N))\n     */\n    void\
    \ dfs(std::vector<std::pair<ll, ll>>& pf_N, std::vector<ll>& divs_N, ll div =\
    \ 1, int idx = 0) {\n        if (idx == (int)pf_N.size()) {\n            divs_N.emplace_back(div);\n\
    \            return;\n        }\n\n        ll mult = 1;\n        for (int i =\
    \ 0; i <= pf_N[idx].second; i++) {// idx\u756A\u76EE\u306E\u7D20\u56E0\u6570\u3092\
    \u4F55\u500B\u542B\u3080\u7D04\u6570\u304B\n            dfs(pf_N, divs_N, div\
    \ * mult, idx + 1);\n            mult *= pf_N[idx].first;\n        }\n    }\n\n\
    \    std::vector<ll> enum_divisors(ll N) {\n        std::vector<std::pair<ll,\
    \ ll>> pf_N = prime_factorize(N);\n        ll total = 1;\n        for (const auto&\
    \ p : pf_N) {\n            total *= (p.second + 1);\n        }\n        std::vector<ll>\
    \ divs_N;\n        divs_N.reserve(total);\n        dfs(pf_N, divs_N);\n      \
    \  return divs_N; // \u672A\u30BD\u30FC\u30C8\n    }\n};\n\n\n"
  code: "#ifndef osa_k_HPP\n#define osa_k_HPP\n\n#include <vector>\n#include <map>\n\
    #include <tuple>\n\nstruct osa_k {\nprivate:\n    using ll = long long;\n    ll\
    \ N;\n    std::vector<int> min_factor;\n    std::vector<int> primes;\n\npublic:\n\
    \    /**\n     * @rem O(Nlog(N))\n     */\n    osa_k(ll N) : N(N) {\n        min_factor.assign(N\
    \ + 1, 0);\n        for (int i = 2; i <= N; i++) {\n            if (min_factor[i]\
    \ == 0) {\n                min_factor[i] = i;\n                primes.push_back(i);\n\
    \            }\n            for (int p : primes) {\n                if (p > min_factor[i]\
    \ || (ll)i * p > N) {\n                    break;\n                }\n       \
    \         min_factor[i * p] = p;\n            }\n        }\n        if (N >= 0)\
    \ {\n            min_factor[0] = -1;\n        }\n        if (N >= 1) {\n     \
    \       min_factor[1] = -1;\n        }\n    }\n\n    /**\n     * @rem O(log(N))\n\
    \     */\n    std::vector<std::pair<ll, ll>> prime_factorize(ll N) {\n       \
    \ std::vector<std::pair<ll, ll>> ret;\n        while (N != 1) {\n            int\
    \ factor = min_factor[N];\n            if (ret.empty() || ret.back().first !=\
    \ factor) {\n                ret.push_back({factor, 1});\n            } else {\n\
    \                ret.back().second++;\n            }\n            N /= factor;\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief N\u306E\u7D20\
    \u56E0\u6570\u306E\u7D50\u679C\u304B\u3089\u3001N\u306E\u7D04\u6570\u3092\u5217\
    \u6319\u3059\u308B\n     * @param idx \u4F55\u756A\u76EE\u306E\u7D20\u56E0\u6570\
    \u3092\u898B\u3066\u3044\u308B\u304B\n     * @remark O(log(N))\n     */\n    void\
    \ dfs(std::vector<std::pair<ll, ll>>& pf_N, std::vector<ll>& divs_N, ll div =\
    \ 1, int idx = 0) {\n        if (idx == (int)pf_N.size()) {\n            divs_N.emplace_back(div);\n\
    \            return;\n        }\n\n        ll mult = 1;\n        for (int i =\
    \ 0; i <= pf_N[idx].second; i++) {// idx\u756A\u76EE\u306E\u7D20\u56E0\u6570\u3092\
    \u4F55\u500B\u542B\u3080\u7D04\u6570\u304B\n            dfs(pf_N, divs_N, div\
    \ * mult, idx + 1);\n            mult *= pf_N[idx].first;\n        }\n    }\n\n\
    \    std::vector<ll> enum_divisors(ll N) {\n        std::vector<std::pair<ll,\
    \ ll>> pf_N = prime_factorize(N);\n        ll total = 1;\n        for (const auto&\
    \ p : pf_N) {\n            total *= (p.second + 1);\n        }\n        std::vector<ll>\
    \ divs_N;\n        divs_N.reserve(total);\n        dfs(pf_N, divs_N);\n      \
    \  return divs_N; // \u672A\u30BD\u30FC\u30C8\n    }\n};\n\n#endif // osa_k_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Math/osa_k.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/osa_k.hpp
layout: document
redirect_from:
- /library/Math/osa_k.hpp
- /library/Math/osa_k.hpp.html
title: "N\u306E\u7D20\u56E0\u6570\u306E\u7D50\u679C\u304B\u3089\u3001N\u306E\u7D04\
  \u6570\u3092\u5217\u6319\u3059\u308B"
---
