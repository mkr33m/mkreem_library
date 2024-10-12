---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7E26\u30FB\u6A2A\u30FB\u659C\u3081\u306E\u30A4\u30F3\u30C7\u30C3\
      \u30AF\u30B9\u3092\u751F\u6210"
    links: []
  bundledCode: "#line 1 \"Others/Grid.hpp\"\n\n\n\n#include <vector>\n#include <string>\n\
    #include <iostream>\n\nconst int di4[4] = {-1, 0, 1, 0};\nconst int dj4[4] = {0,\
    \ 1, 0, -1};\nconst int di8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};\nconst int dj8[8]\
    \ = {0, 1, 1, 1, 0, -1, -1, -1};\n/**\n * @brief \u7E26\u30FB\u6A2A\u30FB\u659C\
    \u3081\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u751F\u6210\n */\nstd::vector<std::vector<int>>\
    \ lines(const int& N){\n    std::vector<std::vector<int>> lines;\n\n    for(int\
    \ i = 0; i < N; i++){\n        std::vector<int> line;\n        for(int j = 0;\
    \ j < N; j++){\n            line.push_back(i * N + j);\n        }\n        lines.push_back(line);\n\
    \    }\n\n    for(int j = 0; j < N; j++){\n        std::vector<int> line;\n  \
    \      for(int i = 0; i < N; i++){\n            line.push_back(i * N + j);\n \
    \       }\n        lines.push_back(line);\n    }\n\n    std::vector<int> diag1;\n\
    \    for(int i = 0; i < N; i++){\n        diag1.push_back(i * N + i);\n    }\n\
    \    lines.push_back(diag1);\n\n    std::vector<int> diag2;\n    for(int i = 0;\
    \ i < N; i++){\n        diag2.push_back(i * N + (N - i - 1));\n    }\n    lines.push_back(diag2);\n\
    \n    return lines;\n}\n\nbool OutOfGrid(const int& i, const int& j, const int&\
    \ h, const int& w){\n    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n\
    \    return false;\n}\n\n/**\n * @brief \u5168\u3066\u306E\u884C\u306E\u6587\u5B57\
    \u5217\u306E\u9577\u3055\u3092\u7D71\u4E00\u3059\u308B\u305F\u3081\u306B\u3001\
    \u7A7A\u767D\u6587\u5B57\u3067\u57CB\u3081\u308B\n */\nvoid pad_strings(std::vector<std::string>&\
    \ grid){\n    size_t maxlen = 0;\n    for(const auto& row : grid){\n        maxlen\
    \ = std::max(maxlen, row.size());\n    }\n    for(auto& row : grid){\n       \
    \ row.resize(maxlen, ' ');\n    }\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ convert_to_matrix(std::vector<std::string>& grid){\n    int H = (int)grid.size();\n\
    \    int W = (int)grid[0].size();\n\n    pad_strings(grid);\n    std::vector<std::vector<T>>\
    \ after_grid(H, std::vector<T>(W));\n    for(int i = 0; i < H; i++){\n       \
    \ for(int j = 0; j < W; j++){\n            after_grid[i][j] = grid[i][j];\n  \
    \      }\n    }\n    return after_grid;\n}\n\n// \u53CD\u6642\u8A08\u56DE\u308A\
    \u306B 90 \u5EA6\u56DE\u8EE2\ntemplate<typename T>\nvoid rotate90(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));\n    for(int\
    \ i = 0; i < W; i++){\n        for(int j = 0; j < H; j++){\n            after_grid[i][j]\
    \ = grid[j][(W - 1) - i];\n        }\n    }\n    std::swap(grid, after_grid);\n\
    }\n\n// 180 \u5EA6\u56DE\u8EE2\ntemplate<typename T>\nvoid rotate180(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(H, std::vector<T>(W));\n    for(int\
    \ i = 0; i < H; i++){\n        for(int j = 0; j < W; j++){\n            after_grid[i][j]\
    \ = grid[(H - 1) - i][(W - 1) - j];\n        }\n    }\n    std::swap(grid, after_grid);\n\
    }\n\n// \u6642\u8A08\u56DE\u308A\u306B 90 \u5EA6\u56DE\u8EE2\uFF08270 \u5EA6\u56DE\
    \u8EE2\uFF09\ntemplate<typename T>\nvoid rotate270(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));\n    for(int\
    \ i = 0; i < W; i++){\n        for(int j = 0; j < H; j++){\n            after_grid[i][j]\
    \ = grid[(H - 1) - j][i];\n        }\n    }\n    std::swap(grid, after_grid);\n\
    }\n\n// \u8EE2\u7F6E\ntemplate<typename T>\nvoid transpose(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));\n    for(int\
    \ i = 0; i < W; i++){\n        for(int j = 0; j < H; j++){\n            after_grid[i][j]\
    \ = grid[j][i];\n        }\n    }\n    std::swap(grid, after_grid);\n}\n\ntemplate<typename\
    \ T>\nvoid print(const std::vector<std::vector<T>>& grid, bool space = true){\n\
    \    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n    for(int\
    \ i = 0; i < H; i++){\n        for(int j = 0; j < W; j++){\n            std::cout\
    \ << grid[i][j];\n            if(space && j < W - 1) std::cout << \" \";\n   \
    \     }\n        std::cout << '\\n';\n    }\n}\n\n\n"
  code: "#ifndef Grid_HPP\n#define Grid_HPP\n\n#include <vector>\n#include <string>\n\
    #include <iostream>\n\nconst int di4[4] = {-1, 0, 1, 0};\nconst int dj4[4] = {0,\
    \ 1, 0, -1};\nconst int di8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};\nconst int dj8[8]\
    \ = {0, 1, 1, 1, 0, -1, -1, -1};\n/**\n * @brief \u7E26\u30FB\u6A2A\u30FB\u659C\
    \u3081\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u751F\u6210\n */\nstd::vector<std::vector<int>>\
    \ lines(const int& N){\n    std::vector<std::vector<int>> lines;\n\n    for(int\
    \ i = 0; i < N; i++){\n        std::vector<int> line;\n        for(int j = 0;\
    \ j < N; j++){\n            line.push_back(i * N + j);\n        }\n        lines.push_back(line);\n\
    \    }\n\n    for(int j = 0; j < N; j++){\n        std::vector<int> line;\n  \
    \      for(int i = 0; i < N; i++){\n            line.push_back(i * N + j);\n \
    \       }\n        lines.push_back(line);\n    }\n\n    std::vector<int> diag1;\n\
    \    for(int i = 0; i < N; i++){\n        diag1.push_back(i * N + i);\n    }\n\
    \    lines.push_back(diag1);\n\n    std::vector<int> diag2;\n    for(int i = 0;\
    \ i < N; i++){\n        diag2.push_back(i * N + (N - i - 1));\n    }\n    lines.push_back(diag2);\n\
    \n    return lines;\n}\n\nbool OutOfGrid(const int& i, const int& j, const int&\
    \ h, const int& w){\n    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n\
    \    return false;\n}\n\n/**\n * @brief \u5168\u3066\u306E\u884C\u306E\u6587\u5B57\
    \u5217\u306E\u9577\u3055\u3092\u7D71\u4E00\u3059\u308B\u305F\u3081\u306B\u3001\
    \u7A7A\u767D\u6587\u5B57\u3067\u57CB\u3081\u308B\n */\nvoid pad_strings(std::vector<std::string>&\
    \ grid){\n    size_t maxlen = 0;\n    for(const auto& row : grid){\n        maxlen\
    \ = std::max(maxlen, row.size());\n    }\n    for(auto& row : grid){\n       \
    \ row.resize(maxlen, ' ');\n    }\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ convert_to_matrix(std::vector<std::string>& grid){\n    int H = (int)grid.size();\n\
    \    int W = (int)grid[0].size();\n\n    pad_strings(grid);\n    std::vector<std::vector<T>>\
    \ after_grid(H, std::vector<T>(W));\n    for(int i = 0; i < H; i++){\n       \
    \ for(int j = 0; j < W; j++){\n            after_grid[i][j] = grid[i][j];\n  \
    \      }\n    }\n    return after_grid;\n}\n\n// \u53CD\u6642\u8A08\u56DE\u308A\
    \u306B 90 \u5EA6\u56DE\u8EE2\ntemplate<typename T>\nvoid rotate90(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));\n    for(int\
    \ i = 0; i < W; i++){\n        for(int j = 0; j < H; j++){\n            after_grid[i][j]\
    \ = grid[j][(W - 1) - i];\n        }\n    }\n    std::swap(grid, after_grid);\n\
    }\n\n// 180 \u5EA6\u56DE\u8EE2\ntemplate<typename T>\nvoid rotate180(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(H, std::vector<T>(W));\n    for(int\
    \ i = 0; i < H; i++){\n        for(int j = 0; j < W; j++){\n            after_grid[i][j]\
    \ = grid[(H - 1) - i][(W - 1) - j];\n        }\n    }\n    std::swap(grid, after_grid);\n\
    }\n\n// \u6642\u8A08\u56DE\u308A\u306B 90 \u5EA6\u56DE\u8EE2\uFF08270 \u5EA6\u56DE\
    \u8EE2\uFF09\ntemplate<typename T>\nvoid rotate270(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));\n    for(int\
    \ i = 0; i < W; i++){\n        for(int j = 0; j < H; j++){\n            after_grid[i][j]\
    \ = grid[(H - 1) - j][i];\n        }\n    }\n    std::swap(grid, after_grid);\n\
    }\n\n// \u8EE2\u7F6E\ntemplate<typename T>\nvoid transpose(std::vector<std::vector<T>>&\
    \ grid){\n    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n\
    \    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));\n    for(int\
    \ i = 0; i < W; i++){\n        for(int j = 0; j < H; j++){\n            after_grid[i][j]\
    \ = grid[j][i];\n        }\n    }\n    std::swap(grid, after_grid);\n}\n\ntemplate<typename\
    \ T>\nvoid print(const std::vector<std::vector<T>>& grid, bool space = true){\n\
    \    int H = (int)grid.size();\n    int W = (int)grid[0].size();\n\n    for(int\
    \ i = 0; i < H; i++){\n        for(int j = 0; j < W; j++){\n            std::cout\
    \ << grid[i][j];\n            if(space && j < W - 1) std::cout << \" \";\n   \
    \     }\n        std::cout << '\\n';\n    }\n}\n\n#endif // Grid_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/Grid.hpp
  requiredBy: []
  timestamp: '2024-10-12 17:28:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Grid.hpp
layout: document
redirect_from:
- /library/Others/Grid.hpp
- /library/Others/Grid.hpp.html
title: "\u7E26\u30FB\u6A2A\u30FB\u659C\u3081\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
  \u3092\u751F\u6210"
---
