---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "start \u304B\u3089\uFF08start \u3092\u542B\u3081\u3066\uFF09\
      K \u9802\u70B9\u8E0F\u3093\u3060\u3068\u304D\u3001\u8E0F\u3093\u3060\u9802\u70B9\
      \u306E\u5024\u306E\u5408\u8A08\u5024\u3092\u6C42\u3081\u308B"
    links: []
  bundledCode: "#line 1 \"Algorithm/Doubling.hpp\"\n\n\n\n#include <vector>\n\ntemplate\
    \ <typename S, S (*op)(S, S), S (*e)()>\nstruct Doubling {\n    Doubling(const\
    \ std::vector<int>& P, const std::vector<S>& V) {\n        int N = P.size();\n\
    \        next = std::vector<std::vector<int>> (61, std::vector<int>(N));\n   \
    \     // data[i][j] := j \u304B\u3089 2^i \u624B\u9032\u3093\u3060\u3068\u304D\
    \u306E\u7A4D\n        dp = std::vector<std::vector<S>> (61, std::vector<S>(N));\n\
    \        for (int i = 0; i < N; i++) {\n            next[0][i] = P[i];\n     \
    \       dp[0][i] = V[i];\n        }\n        for (int i = 1; i <= 60; i++) {\n\
    \            for (int j = 0; j < N; j++) {\n                next[i][j] = next[i\
    \ - 1][next[i - 1][j]];\n                // j \u304B\u3089 2^{i-1} \u624B\uFF08\
    \u524D\u534A\u533A\u9593\uFF09\n                // j \u304B\u3089 2^{i-1} \u884C\
    \u3063\u305F\u5148\uFF08next[i - 1][j]\uFF09\u304B\u3089 2^{i-1} \u624B\uFF08\u5F8C\
    \u534A\u533A\u9593\uFF09\n                dp[i][j] = op(dp[i - 1][j], dp[i - 1][next[i\
    \ - 1][j]]);\n            }\n        }\n    }\n\n    /**\n     * @brief start\
    \ \u304B\u3089\uFF08start \u3092\u542B\u3081\u3066\uFF09K \u9802\u70B9\u8E0F\u3093\
    \u3060\u3068\u304D\u3001\u8E0F\u3093\u3060\u9802\u70B9\u306E\u5024\u306E\u5408\
    \u8A08\u5024\u3092\u6C42\u3081\u308B\n     */\n    S get(int start, long long\
    \ K) {\n        S ret = e();\n        int cur = start;\n        for (int b = 0;\
    \ b <= 60; b++) {\n            if (K & (1LL << b)) {\n                ret = op(ret,\
    \ dp[b][cur]);\n                cur = next[b][cur];\n            }\n        }\n\
    \        return ret;\n    }\n\npublic:\n    std::vector<std::vector<int>> next;\n\
    \    std::vector<std::vector<S>> dp;\n};\n\n\n\n"
  code: "#ifndef Doubling_HPP\n#define Doubling_HPP\n\n#include <vector>\n\ntemplate\
    \ <typename S, S (*op)(S, S), S (*e)()>\nstruct Doubling {\n    Doubling(const\
    \ std::vector<int>& P, const std::vector<S>& V) {\n        int N = P.size();\n\
    \        next = std::vector<std::vector<int>> (61, std::vector<int>(N));\n   \
    \     // data[i][j] := j \u304B\u3089 2^i \u624B\u9032\u3093\u3060\u3068\u304D\
    \u306E\u7A4D\n        dp = std::vector<std::vector<S>> (61, std::vector<S>(N));\n\
    \        for (int i = 0; i < N; i++) {\n            next[0][i] = P[i];\n     \
    \       dp[0][i] = V[i];\n        }\n        for (int i = 1; i <= 60; i++) {\n\
    \            for (int j = 0; j < N; j++) {\n                next[i][j] = next[i\
    \ - 1][next[i - 1][j]];\n                // j \u304B\u3089 2^{i-1} \u624B\uFF08\
    \u524D\u534A\u533A\u9593\uFF09\n                // j \u304B\u3089 2^{i-1} \u884C\
    \u3063\u305F\u5148\uFF08next[i - 1][j]\uFF09\u304B\u3089 2^{i-1} \u624B\uFF08\u5F8C\
    \u534A\u533A\u9593\uFF09\n                dp[i][j] = op(dp[i - 1][j], dp[i - 1][next[i\
    \ - 1][j]]);\n            }\n        }\n    }\n\n    /**\n     * @brief start\
    \ \u304B\u3089\uFF08start \u3092\u542B\u3081\u3066\uFF09K \u9802\u70B9\u8E0F\u3093\
    \u3060\u3068\u304D\u3001\u8E0F\u3093\u3060\u9802\u70B9\u306E\u5024\u306E\u5408\
    \u8A08\u5024\u3092\u6C42\u3081\u308B\n     */\n    S get(int start, long long\
    \ K) {\n        S ret = e();\n        int cur = start;\n        for (int b = 0;\
    \ b <= 60; b++) {\n            if (K & (1LL << b)) {\n                ret = op(ret,\
    \ dp[b][cur]);\n                cur = next[b][cur];\n            }\n        }\n\
    \        return ret;\n    }\n\npublic:\n    std::vector<std::vector<int>> next;\n\
    \    std::vector<std::vector<S>> dp;\n};\n\n\n#endif // Doubling_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Doubling.hpp
  requiredBy: []
  timestamp: '2025-11-23 17:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Doubling.hpp
layout: document
redirect_from:
- /library/Algorithm/Doubling.hpp
- /library/Algorithm/Doubling.hpp.html
title: "start \u304B\u3089\uFF08start \u3092\u542B\u3081\u3066\uFF09K \u9802\u70B9\
  \u8E0F\u3093\u3060\u3068\u304D\u3001\u8E0F\u3093\u3060\u9802\u70B9\u306E\u5024\u306E\
  \u5408\u8A08\u5024\u3092\u6C42\u3081\u308B"
---
