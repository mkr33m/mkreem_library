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
  bundledCode: "#line 1 \"String/Grid.hpp\"\n\n\n\n#include <iostream>\n#include <vector>\n\
    #include <string>\n#include <algorithm>\n\ntemplate<typename T> // \u5404\u8981\
    \u7D20\u306E\u578B\nclass Grid {\nprivate:\n    std::vector<std::vector<T>> grid;\n\
    \    int offset_i_, offset_j_;\n\n    static void pad_strings(std::vector<std::string>&\
    \ grid_arg) {\n        size_t maxlen = 0;\n        for (const auto& row : grid_arg)\
    \ {\n            maxlen = std::max(maxlen, row.size());\n        }\n        for\
    \ (auto& row : grid_arg) {\n            row.resize(maxlen, ' ');\n        }\n\
    \    }\n\npublic:\n    Grid() {}\n    Grid(const std::vector<std::vector<T>>&\
    \ grid_arg) : grid(grid_arg), offset_i_(0), offset_j_(0) {}\n    Grid(std::vector<std::string>\
    \ grid_arg) : offset_i_(0), offset_j_(0) {\n        pad_strings(grid_arg);\n \
    \       int H = grid_arg.size();\n        int W = grid_arg[0].size();\n      \
    \  grid.assign(H, std::vector<T>(W));\n        for (int i = 0; i < H; ++i) {\n\
    \            for (int j = 0; j < W; ++j) {\n                grid[i][j] = grid_arg[i][j];\n\
    \            }\n        }\n    }\n\n    T& get(int i, int j) {\n        assert(0\
    \ <= i && i < (int)get_H());\n        assert(0 <= j && j < (int)get_W());\n  \
    \      return grid[i][j];\n    }\n\n    void set(int i, int j, T x) const {\n\
    \        assert(0 <= i && i < (int)get_H());\n        assert(0 <= j && j < (int)get_W());\n\
    \        grid[i][j] = x;\n    }\n\n    size_t get_H() const {\n        return\
    \ grid.size();\n    }\n\n    size_t get_W() const {\n        return grid[0].size();\n\
    \    }\n\n    const std::vector<std::vector<T>>& get_data() const {\n        return\
    \ grid;\n    }\n\n    // \u30B0\u30EA\u30C3\u30C9\u3092\u51FA\u529B\uFF08space\
    \ == true \u3067\u5404\u8981\u7D20\u9593\u306B\u7A7A\u767D\u3092\u633F\u5165\uFF09\
    \n    void print(bool space = false) const {\n        int H = (int)get_H();\n\
    \        if(H == 0) return;\n        int W = (int)get_W();\n        for (int i\
    \ = 0; i < H; i++) {\n            for (int j = 0; j < W; j++) {\n            \
    \    std::cout << grid[i][j];\n                if (space && j < W - 1)\n     \
    \               std::cout << ' ';\n            }\n            std::cout << '\\\
    n';\n        }\n    }\n\n    // \u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\
    \u8EE2\n    void rotate90() {\n        int H = (int)get_H();\n        int W =\
    \ (int)get_W();\n        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));\n\
    \        for (int i = 0; i < W; i++) {\n            for (int j = 0; j < H; j++)\
    \ {\n                new_grid[i][j] = grid[j][W - 1 - i];\n            }\n   \
    \     }\n        grid.swap(new_grid);\n    }\n\n    // 180\u5EA6\u56DE\u8EE2\n\
    \    void rotate180() {\n        int H = (int)get_H();\n        int W = (int)get_W();\n\
    \        std::vector<std::vector<T>> new_grid(H, std::vector<T>(W));\n       \
    \ for (int i = 0; i < H; i++) {\n            for (int j = 0; j < W; j++) {\n \
    \               new_grid[i][j] = grid[H - 1 - i][W - 1 - j];\n            }\n\
    \        }\n        grid.swap(new_grid);\n    }\n\n    // \u6642\u8A08\u56DE\u308A\
    \u306B90\u5EA6\u56DE\u8EE2\n    void rotate270() {\n        int H = (int)get_H();\n\
    \        int W = (int)get_W();\n        std::vector<std::vector<T>> new_grid(W,\
    \ std::vector<T>(H));\n        for (int i = 0; i < W; i++) {\n            for\
    \ (int j = 0; j < H; j++) {\n                new_grid[i][j] = grid[H - 1 - j][i];\n\
    \            }\n        }\n        grid.swap(new_grid);\n    }\n\n    // \u8EE2\
    \u7F6E\n    void transpose() {\n        int H = (int)get_H();\n        int W =\
    \ (int)get_W();\n        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));\n\
    \        for (int i = 0; i < W; i++) {\n            for (int j = 0; j < H; j++)\
    \ {\n                new_grid[i][j] = grid[j][i];\n            }\n        }\n\
    \        grid.swap(new_grid);\n    }\n\n    // \u5E73\u884C\u79FB\u52D5\n    void\
    \ parallel_shift(int di, int dj) {\n        int H = (int)get_H();\n        int\
    \ W = (int)get_W();\n        offset_i_ = (offset_i_ + di % H + H) % H;\n     \
    \   offset_j_ = (offset_j_ + dj % W + W) % W;\n        std::vector<std::vector<T>>\
    \ new_grid(H, std::vector<T>(W));\n        for (int i = 0; i < H; i++) {\n   \
    \         for (int j = 0; j < W; j++) {\n                int ni = (i + di) % H;\n\
    \                int nj = (j + dj) % W;\n                if (ni < 0) {\n     \
    \               ni += H;\n                }\n                if (nj < 0) {\n \
    \                   nj += W;\n                }\n                new_grid[ni][nj]\
    \ = grid[i][j];\n            }\n        }\n        grid.swap(new_grid);\n    }\n\
    \n    int offset_i() {\n        return offset_i_;\n    }\n\n    int offset_j()\
    \ {\n        return offset_j_;\n    }\n};\n\n\n"
  code: "#ifndef Grid_HPP\n#define Grid_HPP\n\n#include <iostream>\n#include <vector>\n\
    #include <string>\n#include <algorithm>\n\ntemplate<typename T> // \u5404\u8981\
    \u7D20\u306E\u578B\nclass Grid {\nprivate:\n    std::vector<std::vector<T>> grid;\n\
    \    int offset_i_, offset_j_;\n\n    static void pad_strings(std::vector<std::string>&\
    \ grid_arg) {\n        size_t maxlen = 0;\n        for (const auto& row : grid_arg)\
    \ {\n            maxlen = std::max(maxlen, row.size());\n        }\n        for\
    \ (auto& row : grid_arg) {\n            row.resize(maxlen, ' ');\n        }\n\
    \    }\n\npublic:\n    Grid() {}\n    Grid(const std::vector<std::vector<T>>&\
    \ grid_arg) : grid(grid_arg), offset_i_(0), offset_j_(0) {}\n    Grid(std::vector<std::string>\
    \ grid_arg) : offset_i_(0), offset_j_(0) {\n        pad_strings(grid_arg);\n \
    \       int H = grid_arg.size();\n        int W = grid_arg[0].size();\n      \
    \  grid.assign(H, std::vector<T>(W));\n        for (int i = 0; i < H; ++i) {\n\
    \            for (int j = 0; j < W; ++j) {\n                grid[i][j] = grid_arg[i][j];\n\
    \            }\n        }\n    }\n\n    T& get(int i, int j) {\n        assert(0\
    \ <= i && i < (int)get_H());\n        assert(0 <= j && j < (int)get_W());\n  \
    \      return grid[i][j];\n    }\n\n    void set(int i, int j, T x) const {\n\
    \        assert(0 <= i && i < (int)get_H());\n        assert(0 <= j && j < (int)get_W());\n\
    \        grid[i][j] = x;\n    }\n\n    size_t get_H() const {\n        return\
    \ grid.size();\n    }\n\n    size_t get_W() const {\n        return grid[0].size();\n\
    \    }\n\n    const std::vector<std::vector<T>>& get_data() const {\n        return\
    \ grid;\n    }\n\n    // \u30B0\u30EA\u30C3\u30C9\u3092\u51FA\u529B\uFF08space\
    \ == true \u3067\u5404\u8981\u7D20\u9593\u306B\u7A7A\u767D\u3092\u633F\u5165\uFF09\
    \n    void print(bool space = false) const {\n        int H = (int)get_H();\n\
    \        if(H == 0) return;\n        int W = (int)get_W();\n        for (int i\
    \ = 0; i < H; i++) {\n            for (int j = 0; j < W; j++) {\n            \
    \    std::cout << grid[i][j];\n                if (space && j < W - 1)\n     \
    \               std::cout << ' ';\n            }\n            std::cout << '\\\
    n';\n        }\n    }\n\n    // \u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\
    \u8EE2\n    void rotate90() {\n        int H = (int)get_H();\n        int W =\
    \ (int)get_W();\n        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));\n\
    \        for (int i = 0; i < W; i++) {\n            for (int j = 0; j < H; j++)\
    \ {\n                new_grid[i][j] = grid[j][W - 1 - i];\n            }\n   \
    \     }\n        grid.swap(new_grid);\n    }\n\n    // 180\u5EA6\u56DE\u8EE2\n\
    \    void rotate180() {\n        int H = (int)get_H();\n        int W = (int)get_W();\n\
    \        std::vector<std::vector<T>> new_grid(H, std::vector<T>(W));\n       \
    \ for (int i = 0; i < H; i++) {\n            for (int j = 0; j < W; j++) {\n \
    \               new_grid[i][j] = grid[H - 1 - i][W - 1 - j];\n            }\n\
    \        }\n        grid.swap(new_grid);\n    }\n\n    // \u6642\u8A08\u56DE\u308A\
    \u306B90\u5EA6\u56DE\u8EE2\n    void rotate270() {\n        int H = (int)get_H();\n\
    \        int W = (int)get_W();\n        std::vector<std::vector<T>> new_grid(W,\
    \ std::vector<T>(H));\n        for (int i = 0; i < W; i++) {\n            for\
    \ (int j = 0; j < H; j++) {\n                new_grid[i][j] = grid[H - 1 - j][i];\n\
    \            }\n        }\n        grid.swap(new_grid);\n    }\n\n    // \u8EE2\
    \u7F6E\n    void transpose() {\n        int H = (int)get_H();\n        int W =\
    \ (int)get_W();\n        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));\n\
    \        for (int i = 0; i < W; i++) {\n            for (int j = 0; j < H; j++)\
    \ {\n                new_grid[i][j] = grid[j][i];\n            }\n        }\n\
    \        grid.swap(new_grid);\n    }\n\n    // \u5E73\u884C\u79FB\u52D5\n    void\
    \ parallel_shift(int di, int dj) {\n        int H = (int)get_H();\n        int\
    \ W = (int)get_W();\n        offset_i_ = (offset_i_ + di % H + H) % H;\n     \
    \   offset_j_ = (offset_j_ + dj % W + W) % W;\n        std::vector<std::vector<T>>\
    \ new_grid(H, std::vector<T>(W));\n        for (int i = 0; i < H; i++) {\n   \
    \         for (int j = 0; j < W; j++) {\n                int ni = (i + di) % H;\n\
    \                int nj = (j + dj) % W;\n                if (ni < 0) {\n     \
    \               ni += H;\n                }\n                if (nj < 0) {\n \
    \                   nj += W;\n                }\n                new_grid[ni][nj]\
    \ = grid[i][j];\n            }\n        }\n        grid.swap(new_grid);\n    }\n\
    \n    int offset_i() {\n        return offset_i_;\n    }\n\n    int offset_j()\
    \ {\n        return offset_j_;\n    }\n};\n\n#endif // Grid_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/Grid.hpp
  requiredBy: []
  timestamp: '2025-03-14 07:28:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Grid.hpp
layout: document
redirect_from:
- /library/String/Grid.hpp
- /library/String/Grid.hpp.html
title: String/Grid.hpp
---
