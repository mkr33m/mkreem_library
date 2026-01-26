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
    links: []
  bundledCode: "#line 1 \"Algorithm/Mo.hpp\"\n\n\n\n#include <vector>\n#include <cmath>\n\
    #include <algorithm>\n#include <numeric>\n#include <functional>\n\ntemplate <typename\
    \ Add, typename Del> // \u3053\u3053\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u4EEE\u5F15\u6570\u306F\u3001\u5B9F\u969B\u306E\u547C\u3073\u51FA\u3057\u5F0F\
    \u304B\u3089\u63A8\u8AD6\nstruct Mo {\n    Mo(int N, const Add& add, const Del&\
    \ del) : N(N), add(add), del(del) {}\n\n    void add_query(int l, int r) {\n \
    \       int id = (int)queries.size();\n        queries.push_back({l, r, id});\n\
    \    };\n\n    template <typename Out>\n    void solve(Out&& output) {\n     \
    \   if (queries.empty()) {\n            return;\n        }\n        const int\
    \ Q = (int)queries.size();\n        // sqrt(N) \u3067\u5206\u5272\u3059\u308B\u3088\
    \u308A sqrt(Q) \u3067\u5206\u5272\u3057\u305F\u65B9\u304C\u9AD8\u901F\u3089\u3057\
    \u3044\n        const int block = std::max(1, int(N / std::sqrt(Q)));\n\n    \
    \    std::sort(queries.begin(), queries.end(), [block](const query& x, const query&\
    \ y) {\n            if (x.l / block != y.l / block) {\n                return\
    \ x.l < y.l;\n            }\n            int x_block = x.l / block;\n        \
    \    // \u5076\u6570\u533A\u9593\u306F\u6607\u9806\u3001\u5947\u6570\u533A\u9593\
    \u306F\u964D\u9806\n            return (x_block & 1) ? (x.r > y.r) :(x.r < y.r);\n\
    \        });\n\n        int cur_l = 0, cur_r = 0;\n        for (const query& q\
    \ : queries) {\n            while (cur_l > q.l) {\n                cur_l--; add(cur_l);\n\
    \            }\n            while (cur_l < q.l) {\n                del(cur_l);\
    \ cur_l++;\n            }\n            while (cur_r > q.r) {\n               \
    \ cur_r--; del(cur_r);\n            }\n            while (cur_r < q.r) {\n   \
    \             add(cur_r); cur_r++;\n            }\n\n            output(q.id);\n\
    \        }\n    }\n\nprivate:\n    int N;\n    Add add;\n    Del del;\n    struct\
    \ query {\n        int l, r, id;\n    };\n    std::vector<query> queries;\n};\n\
    \n\n"
  code: "#ifndef Mo_HPP\n#define Mo_HPP\n\n#include <vector>\n#include <cmath>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <functional>\n\ntemplate <typename\
    \ Add, typename Del> // \u3053\u3053\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u4EEE\u5F15\u6570\u306F\u3001\u5B9F\u969B\u306E\u547C\u3073\u51FA\u3057\u5F0F\
    \u304B\u3089\u63A8\u8AD6\nstruct Mo {\n    Mo(int N, const Add& add, const Del&\
    \ del) : N(N), add(add), del(del) {}\n\n    void add_query(int l, int r) {\n \
    \       int id = (int)queries.size();\n        queries.push_back({l, r, id});\n\
    \    };\n\n    template <typename Out>\n    void solve(Out&& output) {\n     \
    \   if (queries.empty()) {\n            return;\n        }\n        const int\
    \ Q = (int)queries.size();\n        // sqrt(N) \u3067\u5206\u5272\u3059\u308B\u3088\
    \u308A sqrt(Q) \u3067\u5206\u5272\u3057\u305F\u65B9\u304C\u9AD8\u901F\u3089\u3057\
    \u3044\n        const int block = std::max(1, int(N / std::sqrt(Q)));\n\n    \
    \    std::sort(queries.begin(), queries.end(), [block](const query& x, const query&\
    \ y) {\n            if (x.l / block != y.l / block) {\n                return\
    \ x.l < y.l;\n            }\n            int x_block = x.l / block;\n        \
    \    // \u5076\u6570\u533A\u9593\u306F\u6607\u9806\u3001\u5947\u6570\u533A\u9593\
    \u306F\u964D\u9806\n            return (x_block & 1) ? (x.r > y.r) :(x.r < y.r);\n\
    \        });\n\n        int cur_l = 0, cur_r = 0;\n        for (const query& q\
    \ : queries) {\n            while (cur_l > q.l) {\n                cur_l--; add(cur_l);\n\
    \            }\n            while (cur_l < q.l) {\n                del(cur_l);\
    \ cur_l++;\n            }\n            while (cur_r > q.r) {\n               \
    \ cur_r--; del(cur_r);\n            }\n            while (cur_r < q.r) {\n   \
    \             add(cur_r); cur_r++;\n            }\n\n            output(q.id);\n\
    \        }\n    }\n\nprivate:\n    int N;\n    Add add;\n    Del del;\n    struct\
    \ query {\n        int l, r, id;\n    };\n    std::vector<query> queries;\n};\n\
    \n#endif // Mo_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Mo.hpp
  requiredBy:
  - all_includes.hpp
  timestamp: '2026-01-26 21:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Mo.hpp
layout: document
redirect_from:
- /library/Algorithm/Mo.hpp
- /library/Algorithm/Mo.hpp.html
title: Algorithm/Mo.hpp
---
