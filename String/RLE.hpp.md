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
  bundledCode: "#line 1 \"String/RLE.hpp\"\n\n\n\n#include <vector>\n#include <string>\n\
    #include <tuple>\n\nstd::vector<std::pair<char, int>> encode(const std::string&\
    \ S){\n    int N = (int)S.size();\n    std::vector<std::pair<char, int>> res;\n\
    \    int l = 0, r;\n    while(r < N){\n        r = l + 1;\n        while(r < N\
    \ && S[l] == S[r]) r++;\n        res.emplace_back(S[l], r - l);\n        l = r;\n\
    \    }\n    return res;\n}\n\nstd::string decode(const std::vector<std::pair<char,\
    \ int>>& encoded){\n    std::string res = \"\";\n    for(const auto& [ch, num]\
    \ : encoded){\n        for(int i = 0; i < num; i++){\n            res += ch;\n\
    \        }\n    }\n    return res;\n}\n\n\n"
  code: "#ifndef RLE_HPP\n#define RLE_HPP\n\n#include <vector>\n#include <string>\n\
    #include <tuple>\n\nstd::vector<std::pair<char, int>> encode(const std::string&\
    \ S){\n    int N = (int)S.size();\n    std::vector<std::pair<char, int>> res;\n\
    \    int l = 0, r;\n    while(r < N){\n        r = l + 1;\n        while(r < N\
    \ && S[l] == S[r]) r++;\n        res.emplace_back(S[l], r - l);\n        l = r;\n\
    \    }\n    return res;\n}\n\nstd::string decode(const std::vector<std::pair<char,\
    \ int>>& encoded){\n    std::string res = \"\";\n    for(const auto& [ch, num]\
    \ : encoded){\n        for(int i = 0; i < num; i++){\n            res += ch;\n\
    \        }\n    }\n    return res;\n}\n\n#endif // RLE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/RLE.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RLE.hpp
layout: document
redirect_from:
- /library/String/RLE.hpp
- /library/String/RLE.hpp.html
title: String/RLE.hpp
---
