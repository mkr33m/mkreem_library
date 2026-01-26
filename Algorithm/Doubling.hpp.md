---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all_includes.hpp
    title: all_includes.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "start \u304B\u3089\uFF08start \u3092\u542B\u3081\u3066\uFF09\
      K \u9802\u70B9\u8E0F\u3093\u3060\u3068\u304D\u3001\u8E0F\u3093\u3060\u9802\u70B9\
      \u306E\u5024\u306E\u5408\u8A08\u5024\u3092\u8FD4\u3059"
    links: []
  bundledCode: "#line 1 \"Algorithm/Doubling.hpp\"\n\n\n\n#include <vector>\n\ntemplate<class\
    \ S = void, auto op = nullptr, auto e = nullptr>\nstruct Doubling;\n\ntemplate\
    \ <auto op, auto e>\nstruct Doubling<void, op, e> {\n    int N;\n    std::vector<std::vector<int>>\
    \ next;\n\n    Doubling(const std::vector<int>& P) : N((int)P.size()) {\n    \
    \    next.assign(60, std::vector<int>(N));\n        for (int i = 0; i < N; i++)\
    \ {\n            next[0][i] = P[i];\n        }\n        for (int b = 1; b < 60;\
    \ b++) {\n            for (int i = 0; i < N; i++) {\n                next[b][i]\
    \ = next[b - 1][ next[b - 1][i] ];\n            }\n        }\n    }\n\n    int\
    \ to(int start, long long K) {\n        int pos = start;\n        for (int b =\
    \ 0; b < 60; b++) {\n            if (K & (1LL << b)) {\n                pos =\
    \ next[b][pos];\n            }\n        }\n        return pos;\n    }\n};\n\n\
    template <typename S, auto op, auto e>\nstruct Doubling {\n    int N;\n    std::vector<std::vector<int>>\
    \ next;\n    std::vector<std::vector<S>> db;\n\n    Doubling(const std::vector<int>&\
    \ P, const std::vector<S>& V) : N((int)P.size()) {\n        next.assign(60, std::vector<int>(N));\n\
    \        db.assign(60, std::vector<S>(N)); // db[i][j] := j \u304B\u3089 2^i \u624B\
    \u9032\u3093\u3060\u3068\u304D\u306E\u7A4D\n        for (int i = 0; i < N; i++)\
    \ {\n            next[0][i] = P[i];\n            db[0][i] = V[i];\n        }\n\
    \        for (int i = 1; i < 60; i++) {\n            for (int j = 0; j < N; j++)\
    \ {\n                next[i][j] = next[i - 1][next[i - 1][j]];\n             \
    \   // j \u304B\u3089 2^{i-1} \u624B\uFF08\u524D\u534A\u533A\u9593\uFF09\n   \
    \             // j \u304B\u3089 2^{i-1} \u884C\u3063\u305F\u5148\uFF08next[i -\
    \ 1][j]\uFF09\u304B\u3089 2^{i-1} \u624B\uFF08\u5F8C\u534A\u533A\u9593\uFF09\n\
    \                db[i][j] = op(db[i - 1][j], db[i - 1][next[i - 1][j]]);\n   \
    \         }\n        }\n    }\n\n    /**\n     * @brief start \u304B\u3089\uFF08\
    start \u3092\u542B\u3081\u3066\uFF09K \u9802\u70B9\u8E0F\u3093\u3060\u3068\u304D\
    \u3001\u8E0F\u3093\u3060\u9802\u70B9\u306E\u5024\u306E\u5408\u8A08\u5024\u3092\
    \u8FD4\u3059\n     */\n    S prod(int start, long long K) {\n        S ret = e();\n\
    \        int pos = start;\n        for (int b = 0; b < 60; b++) {\n          \
    \  if (K & (1LL << b)) {\n                ret = op(ret, db[b][pos]);\n       \
    \         pos = next[b][pos];\n            }\n        }\n        return ret;\n\
    \    }\n\n    /**\n     * @brief start \u304B\u3089 K \u624B\u9032\u3093\u3060\
    \u5148\u306E\u9802\u70B9\u756A\u53F7\u3092\u8FD4\u3059\n     */\n    int to(int\
    \ start, long long K) {\n        int pos = start;\n        for (int b = 0; b <\
    \ 60; b++) {\n            if (K & (1LL << b)) {\n                pos = next[b][pos];\n\
    \            }\n        }\n        return pos;\n    }\n};\n\n\n\n"
  code: "#ifndef Doubling_HPP\n#define Doubling_HPP\n\n#include <vector>\n\ntemplate<class\
    \ S = void, auto op = nullptr, auto e = nullptr>\nstruct Doubling;\n\ntemplate\
    \ <auto op, auto e>\nstruct Doubling<void, op, e> {\n    int N;\n    std::vector<std::vector<int>>\
    \ next;\n\n    Doubling(const std::vector<int>& P) : N((int)P.size()) {\n    \
    \    next.assign(60, std::vector<int>(N));\n        for (int i = 0; i < N; i++)\
    \ {\n            next[0][i] = P[i];\n        }\n        for (int b = 1; b < 60;\
    \ b++) {\n            for (int i = 0; i < N; i++) {\n                next[b][i]\
    \ = next[b - 1][ next[b - 1][i] ];\n            }\n        }\n    }\n\n    int\
    \ to(int start, long long K) {\n        int pos = start;\n        for (int b =\
    \ 0; b < 60; b++) {\n            if (K & (1LL << b)) {\n                pos =\
    \ next[b][pos];\n            }\n        }\n        return pos;\n    }\n};\n\n\
    template <typename S, auto op, auto e>\nstruct Doubling {\n    int N;\n    std::vector<std::vector<int>>\
    \ next;\n    std::vector<std::vector<S>> db;\n\n    Doubling(const std::vector<int>&\
    \ P, const std::vector<S>& V) : N((int)P.size()) {\n        next.assign(60, std::vector<int>(N));\n\
    \        db.assign(60, std::vector<S>(N)); // db[i][j] := j \u304B\u3089 2^i \u624B\
    \u9032\u3093\u3060\u3068\u304D\u306E\u7A4D\n        for (int i = 0; i < N; i++)\
    \ {\n            next[0][i] = P[i];\n            db[0][i] = V[i];\n        }\n\
    \        for (int i = 1; i < 60; i++) {\n            for (int j = 0; j < N; j++)\
    \ {\n                next[i][j] = next[i - 1][next[i - 1][j]];\n             \
    \   // j \u304B\u3089 2^{i-1} \u624B\uFF08\u524D\u534A\u533A\u9593\uFF09\n   \
    \             // j \u304B\u3089 2^{i-1} \u884C\u3063\u305F\u5148\uFF08next[i -\
    \ 1][j]\uFF09\u304B\u3089 2^{i-1} \u624B\uFF08\u5F8C\u534A\u533A\u9593\uFF09\n\
    \                db[i][j] = op(db[i - 1][j], db[i - 1][next[i - 1][j]]);\n   \
    \         }\n        }\n    }\n\n    /**\n     * @brief start \u304B\u3089\uFF08\
    start \u3092\u542B\u3081\u3066\uFF09K \u9802\u70B9\u8E0F\u3093\u3060\u3068\u304D\
    \u3001\u8E0F\u3093\u3060\u9802\u70B9\u306E\u5024\u306E\u5408\u8A08\u5024\u3092\
    \u8FD4\u3059\n     */\n    S prod(int start, long long K) {\n        S ret = e();\n\
    \        int pos = start;\n        for (int b = 0; b < 60; b++) {\n          \
    \  if (K & (1LL << b)) {\n                ret = op(ret, db[b][pos]);\n       \
    \         pos = next[b][pos];\n            }\n        }\n        return ret;\n\
    \    }\n\n    /**\n     * @brief start \u304B\u3089 K \u624B\u9032\u3093\u3060\
    \u5148\u306E\u9802\u70B9\u756A\u53F7\u3092\u8FD4\u3059\n     */\n    int to(int\
    \ start, long long K) {\n        int pos = start;\n        for (int b = 0; b <\
    \ 60; b++) {\n            if (K & (1LL << b)) {\n                pos = next[b][pos];\n\
    \            }\n        }\n        return pos;\n    }\n};\n\n\n#endif // Doubling_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Doubling.hpp
  requiredBy:
  - all_includes.hpp
  timestamp: '2026-01-26 21:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Doubling.hpp
layout: document
redirect_from:
- /library/Algorithm/Doubling.hpp
- /library/Algorithm/Doubling.hpp.html
title: "start \u304B\u3089\uFF08start \u3092\u542B\u3081\u3066\uFF09K \u9802\u70B9\
  \u8E0F\u3093\u3060\u3068\u304D\u3001\u8E0F\u3093\u3060\u9802\u70B9\u306E\u5024\u306E\
  \u5408\u8A08\u5024\u3092\u8FD4\u3059"
---
