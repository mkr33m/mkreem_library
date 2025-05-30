---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "S[0, i) \u306E\u63A5\u982D\u8F9E\u3001\u63A5\u5C3E\u8F9E\u304C\
      \u6700\u5927\u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3092\
      \u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\u3064\u307E\u308A\
      \u3001S[0, k) == S[i-k, i) \u306A\u308B\u6700\u5927\u306E k\u3002"
    links: []
  bundledCode: "#line 1 \"String/MP.hpp\"\n\n\n\n#include <string>\n#include <vector>\n\
    \n/**\n * @brief S[0, i) \u306E\u63A5\u982D\u8F9E\u3001\u63A5\u5C3E\u8F9E\u304C\
    \u6700\u5927\u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3092\
    \u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\u3064\u307E\u308A\
    \u3001S[0, k) == S[i-k, i) \u306A\u308B\u6700\u5927\u306E k\u3002\n */\nstd::vector<int>\
    \ MP(std::string S) {\n    int N = (int)S.size();\n    std::vector<int> res(N\
    \ + 1); // [0, i)\n\n    res[0] = -1;\n    for (int i = 0; i < N; i++) {\n   \
    \     int j = res[i];\n        while (j >= 0 && S[i] != S[j]) {\n            j\
    \ = res[j];\n        }\n        j++;\n        res[i + 1] = j;\n    }\n\n    return\
    \ res;\n}\n\n\n\n"
  code: "#ifndef KMP_HPP\n#define KMP_HPP\n\n#include <string>\n#include <vector>\n\
    \n/**\n * @brief S[0, i) \u306E\u63A5\u982D\u8F9E\u3001\u63A5\u5C3E\u8F9E\u304C\
    \u6700\u5927\u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3092\
    \u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\u3064\u307E\u308A\
    \u3001S[0, k) == S[i-k, i) \u306A\u308B\u6700\u5927\u306E k\u3002\n */\nstd::vector<int>\
    \ MP(std::string S) {\n    int N = (int)S.size();\n    std::vector<int> res(N\
    \ + 1); // [0, i)\n\n    res[0] = -1;\n    for (int i = 0; i < N; i++) {\n   \
    \     int j = res[i];\n        while (j >= 0 && S[i] != S[j]) {\n            j\
    \ = res[j];\n        }\n        j++;\n        res[i + 1] = j;\n    }\n\n    return\
    \ res;\n}\n\n\n#endif // KMP_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/MP.hpp
  requiredBy: []
  timestamp: '2025-05-30 14:13:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/MP.hpp
layout: document
redirect_from:
- /library/String/MP.hpp
- /library/String/MP.hpp.html
title: "S[0, i) \u306E\u63A5\u982D\u8F9E\u3001\u63A5\u5C3E\u8F9E\u304C\u6700\u5927\
  \u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3092\u8A18\u9332\u3057\
  \u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\u3064\u307E\u308A\u3001S[0, k) == S[i-k,\
  \ i) \u306A\u308B\u6700\u5927\u306E k\u3002"
---
