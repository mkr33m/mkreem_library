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
  bundledCode: "#line 1 \"Algorithm/Mo.hpp\"\n\n\n\n#include <vector>\n#include <cmath>\n\
    #include <algorithm>\n#include <numeric>\n#include <functional>\n\n/**\n * \u30BD\
    \u30FC\u30C8 -> \u30BD\u30FC\u30C8\u9806\u306B\u8A2A\u554F\u3057\u3066\u7B54\u3048\
    \u3092\u6C42\u3081\u3066\u3044\u304F\u306E\u6D41\u308C\u3002\u3053\u308C\u3089\
    \u3092\u5168\u3066 solve \u306B\u62C5\u308F\u305B\u308B\u3002\n * \u7B54\u3048\
    \u306E\u51FA\u529B\u306E\u4ED5\u65B9\u3068\u3057\u3066\u306F\u3001output \u95A2\
    \u6570\u306B\u4EFB\u305B\u308B\u3053\u3068\u306B\u3059\u308B\u3002\n * \u7B54\u3048\
    \u3092\u6C42\u3081\u3066\u3044\u304F\u3068\u304D\u306E add, del \u95A2\u6570\u306B\
    \u95A2\u3057\u3066\u306F\u3001\u5DEE\u5206\u66F4\u65B0\u3059\u308B\u3082\u306E\
    \u306E\u578B\u306E\u7A2E\u985E\u3084\u6570\u3092\u554F\u984C\u306B\u5FDC\u3058\
    \u3066\u5BFE\u5FDC\u3067\u304D\u308B\u3088\u3046\u306B\u3001\u30E9\u30E0\u30C0\
    \u95A2\u6570\u3092\u4F7F\u3046\u3002\n * \u30E9\u30E0\u30C0\u95A2\u6570\u306E\
    \ & \u306B\u3088\u308B\u30AD\u30E3\u30D7\u30C1\u30E3\u53C2\u7167\u3092\u5229\u7528\
    \u3059\u308B\u3002\n * main \u95A2\u6570\u5185\u3067\u751F\u6210\u3055\u308C\u305F\
    \ add, del \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306F\u3001\u30AD\u30E3\u30D7\u30C1\
    \u30E3\u3055\u308C\u305F\u5909\u6570\u3078\u306E\u53C2\u7167\u3092\u4FDD\u6301\
    \u3057\u3066\u3044\u308B\u3002\u3053\u308C\u3092 Mo \u69CB\u9020\u4F53\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u4F5C\u6210\u6642\u306B\u5F15\u6570\u3068\u3057\
    \u3066\u6E21\u3057\u3066\uFF08add, del \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304C\
    \u30B3\u30D4\u30FC\u3055\u308C\u3066\uFF09\u3082\u3001\uFF08\u30B3\u30D4\u30FC\
    \u5148\u3067\uFF09\u3053\u306E\u53C2\u7167\u304C\u5931\u308F\u308C\u308B\u3053\
    \u3068\u306F\u306A\u3044\u3002\n */\ntemplate <typename Add, typename Del> //\
    \ \u3053\u3053\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u4EEE\u5F15\u6570\u306F\
    \u3001\u5B9F\u969B\u306E\u547C\u3073\u51FA\u3057\u5F0F\u304B\u3089\u63A8\u8AD6\
    \u3055\u308C\u308B\u3002\u67D4\u8EDF\u6027\u306B\u5BCC\u3093\u3067\u5B09\u3057\
    \u3044\uFF01\nstruct Mo {\n\n    Mo(int N, const Add& add, const Del& del) : N(N),\
    \ add(add), del(del) {}\n\n    void add_query(int l, int r) {\n        int id\
    \ = (int)queries.size();\n        queries.push_back({l, r, id});\n    };\n\n \
    \   /**\n     * \u3069\u3046\u3057\u3066 Out&& \u306A\u306E\u304B\uFF1F\n    \
    \ * \n     * T&\uFF08\u304C\u675F\u7E1B\u3067\u304D\u308B\u5024\uFF09\uFF1A\u5DE6\
    \u8FBA\u5024\u306E\u307F -> \u3053\u308C\u306B\u53F3\u8FBA\u5024\u3067\u3042\u308B\
    \u30E9\u30E0\u30C0\u95A2\u6570\u3092\u675F\u7E1B\u3055\u305B\u308B\u3053\u3068\
    \u306F\u4E0D\u53EF\u80FD\n     * const T&\uFF1A\u5DE6\u8FBA\u5024 + const \u53F3\
    \u8FBA\u5024\n     * T&&\uFF1A\u53F3\u8FBA\u5024\u306E\u307F\n     * \uFF08\u53F3\
    \u8FBA\u5024 == \u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\uFF09\n     *\
    \ \n     * \u30E9\u30E0\u30C0\u95A2\u6570\u306F\u53F3\u8FBA\u5024\u3067\u3042\u308B\
    \u304B\u3089\u3001const T& or T&& \u304C\u9078\u629E\u80A2\u3068\u306A\u308B\u3002\
    \n     * \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30E9\u30E0\u30C0\u95A2\u6570\u306F\
    \u30AD\u30E3\u30D7\u30C1\u30E3\u3057\u305F\u5909\u6570\u306B\u3064\u3044\u3066\
    \u3001operator() \u3092 const \u6271\u3044\u3059\u308B\u3002mutable \u3092\u4ED8\
    \u3051\u308B\u3053\u3068\u3067 operator() \u306F const \u3067\u306F\u306A\u304F\
    \u306A\u308B\u304C\u3001\u305D\u306E\u305F\u3081 const T& \u306B\u306F\u6E21\u305B\
    \u306A\u3044\u3002\n     * T&& \u306F\u3001\u53F3\u8FBA\u5024\u306A\u3089\u30E0\
    \u30FC\u30D6\uFF08\u5B8C\u5168\u306B\u6240\u6709\u6A29\u3092\u79FB\u3059\u3068\
    \u8003\u3048\u3066\u3088\u3044\u3002\u6240\u6709\u5143\u306F\u7834\u68C4\u3057\
    \u3066\u3082 OK\uFF09\u3001\u5DE6\u8FBA\u5024\u306A\u3089\u53C2\u7167\u3068\u3057\
    \u3066\u53D7\u3051\u53D6\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\u3055\
    \u3089\u306B\u3001mutable \u30E9\u30E0\u30C0\u3082\u6E21\u3059\u3053\u3068\u304C\
    \u3067\u304D\u308B\u3002\n     */\n    template <typename Out>\n    void solve(Out&&\
    \ output) {\n        if (queries.empty()) {\n            return;\n        }\n\
    \        const int Q = (int)queries.size();\n        // sqrt(N) \u3067\u5206\u5272\
    \u3059\u308B\u3088\u308A sqrt(Q) \u3067\u5206\u5272\u3057\u305F\u65B9\u304C\u9AD8\
    \u901F\u3089\u3057\u3044\n        const int block = std::max(1, int(N / std::sqrt(Q)));\n\
    \n        std::sort(queries.begin(), queries.end(), [block](const query& x, const\
    \ query& y) {\n            if (x.l / block != y.l / block) {\n               \
    \ return x.l < y.l;\n            }\n            int x_block = x.l / block;\n \
    \           // \u5076\u6570\u533A\u9593\u306F\u6607\u9806\u3001\u5947\u6570\u533A\
    \u9593\u306F\u964D\u9806\n            return (x_block & 1) ? (x.r > y.r) :(x.r\
    \ < y.r);\n        });\n\n        int cur_l = 0, cur_r = 0;\n        for (const\
    \ query& q : queries) {\n            while (cur_l > q.l) {\n                cur_l--;\
    \ add(cur_l);\n            }\n            while (cur_l < q.l) {\n            \
    \    del(cur_l); cur_l++;\n            }\n            while (cur_r > q.r) {\n\
    \                cur_r--; del(cur_r);\n            }\n            while (cur_r\
    \ < q.r) {\n                add(cur_r); cur_r++;\n            }\n\n          \
    \  output(q.id);\n        }\n    }\n\nprivate:\n    int N;\n    Add add;\n   \
    \ Del del;\n    struct query {\n        int l, r, id;\n    };\n    std::vector<query>\
    \ queries;\n};\n\n\n"
  code: "#ifndef Mo_HPP\n#define Mo_HPP\n\n#include <vector>\n#include <cmath>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <functional>\n\n/**\n * \u30BD\u30FC\
    \u30C8 -> \u30BD\u30FC\u30C8\u9806\u306B\u8A2A\u554F\u3057\u3066\u7B54\u3048\u3092\
    \u6C42\u3081\u3066\u3044\u304F\u306E\u6D41\u308C\u3002\u3053\u308C\u3089\u3092\
    \u5168\u3066 solve \u306B\u62C5\u308F\u305B\u308B\u3002\n * \u7B54\u3048\u306E\
    \u51FA\u529B\u306E\u4ED5\u65B9\u3068\u3057\u3066\u306F\u3001output \u95A2\u6570\
    \u306B\u4EFB\u305B\u308B\u3053\u3068\u306B\u3059\u308B\u3002\n * \u7B54\u3048\u3092\
    \u6C42\u3081\u3066\u3044\u304F\u3068\u304D\u306E add, del \u95A2\u6570\u306B\u95A2\
    \u3057\u3066\u306F\u3001\u5DEE\u5206\u66F4\u65B0\u3059\u308B\u3082\u306E\u306E\
    \u578B\u306E\u7A2E\u985E\u3084\u6570\u3092\u554F\u984C\u306B\u5FDC\u3058\u3066\
    \u5BFE\u5FDC\u3067\u304D\u308B\u3088\u3046\u306B\u3001\u30E9\u30E0\u30C0\u95A2\
    \u6570\u3092\u4F7F\u3046\u3002\n * \u30E9\u30E0\u30C0\u95A2\u6570\u306E & \u306B\
    \u3088\u308B\u30AD\u30E3\u30D7\u30C1\u30E3\u53C2\u7167\u3092\u5229\u7528\u3059\
    \u308B\u3002\n * main \u95A2\u6570\u5185\u3067\u751F\u6210\u3055\u308C\u305F add,\
    \ del \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306F\u3001\u30AD\u30E3\u30D7\u30C1\
    \u30E3\u3055\u308C\u305F\u5909\u6570\u3078\u306E\u53C2\u7167\u3092\u4FDD\u6301\
    \u3057\u3066\u3044\u308B\u3002\u3053\u308C\u3092 Mo \u69CB\u9020\u4F53\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u4F5C\u6210\u6642\u306B\u5F15\u6570\u3068\u3057\
    \u3066\u6E21\u3057\u3066\uFF08add, del \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304C\
    \u30B3\u30D4\u30FC\u3055\u308C\u3066\uFF09\u3082\u3001\uFF08\u30B3\u30D4\u30FC\
    \u5148\u3067\uFF09\u3053\u306E\u53C2\u7167\u304C\u5931\u308F\u308C\u308B\u3053\
    \u3068\u306F\u306A\u3044\u3002\n */\ntemplate <typename Add, typename Del> //\
    \ \u3053\u3053\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u4EEE\u5F15\u6570\u306F\
    \u3001\u5B9F\u969B\u306E\u547C\u3073\u51FA\u3057\u5F0F\u304B\u3089\u63A8\u8AD6\
    \u3055\u308C\u308B\u3002\u67D4\u8EDF\u6027\u306B\u5BCC\u3093\u3067\u5B09\u3057\
    \u3044\uFF01\nstruct Mo {\n\n    Mo(int N, const Add& add, const Del& del) : N(N),\
    \ add(add), del(del) {}\n\n    void add_query(int l, int r) {\n        int id\
    \ = (int)queries.size();\n        queries.push_back({l, r, id});\n    };\n\n \
    \   /**\n     * \u3069\u3046\u3057\u3066 Out&& \u306A\u306E\u304B\uFF1F\n    \
    \ * \n     * T&\uFF08\u304C\u675F\u7E1B\u3067\u304D\u308B\u5024\uFF09\uFF1A\u5DE6\
    \u8FBA\u5024\u306E\u307F -> \u3053\u308C\u306B\u53F3\u8FBA\u5024\u3067\u3042\u308B\
    \u30E9\u30E0\u30C0\u95A2\u6570\u3092\u675F\u7E1B\u3055\u305B\u308B\u3053\u3068\
    \u306F\u4E0D\u53EF\u80FD\n     * const T&\uFF1A\u5DE6\u8FBA\u5024 + const \u53F3\
    \u8FBA\u5024\n     * T&&\uFF1A\u53F3\u8FBA\u5024\u306E\u307F\n     * \uFF08\u53F3\
    \u8FBA\u5024 == \u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\uFF09\n     *\
    \ \n     * \u30E9\u30E0\u30C0\u95A2\u6570\u306F\u53F3\u8FBA\u5024\u3067\u3042\u308B\
    \u304B\u3089\u3001const T& or T&& \u304C\u9078\u629E\u80A2\u3068\u306A\u308B\u3002\
    \n     * \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30E9\u30E0\u30C0\u95A2\u6570\u306F\
    \u30AD\u30E3\u30D7\u30C1\u30E3\u3057\u305F\u5909\u6570\u306B\u3064\u3044\u3066\
    \u3001operator() \u3092 const \u6271\u3044\u3059\u308B\u3002mutable \u3092\u4ED8\
    \u3051\u308B\u3053\u3068\u3067 operator() \u306F const \u3067\u306F\u306A\u304F\
    \u306A\u308B\u304C\u3001\u305D\u306E\u305F\u3081 const T& \u306B\u306F\u6E21\u305B\
    \u306A\u3044\u3002\n     * T&& \u306F\u3001\u53F3\u8FBA\u5024\u306A\u3089\u30E0\
    \u30FC\u30D6\uFF08\u5B8C\u5168\u306B\u6240\u6709\u6A29\u3092\u79FB\u3059\u3068\
    \u8003\u3048\u3066\u3088\u3044\u3002\u6240\u6709\u5143\u306F\u7834\u68C4\u3057\
    \u3066\u3082 OK\uFF09\u3001\u5DE6\u8FBA\u5024\u306A\u3089\u53C2\u7167\u3068\u3057\
    \u3066\u53D7\u3051\u53D6\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\u3055\
    \u3089\u306B\u3001mutable \u30E9\u30E0\u30C0\u3082\u6E21\u3059\u3053\u3068\u304C\
    \u3067\u304D\u308B\u3002\n     */\n    template <typename Out>\n    void solve(Out&&\
    \ output) {\n        if (queries.empty()) {\n            return;\n        }\n\
    \        const int Q = (int)queries.size();\n        // sqrt(N) \u3067\u5206\u5272\
    \u3059\u308B\u3088\u308A sqrt(Q) \u3067\u5206\u5272\u3057\u305F\u65B9\u304C\u9AD8\
    \u901F\u3089\u3057\u3044\n        const int block = std::max(1, int(N / std::sqrt(Q)));\n\
    \n        std::sort(queries.begin(), queries.end(), [block](const query& x, const\
    \ query& y) {\n            if (x.l / block != y.l / block) {\n               \
    \ return x.l < y.l;\n            }\n            int x_block = x.l / block;\n \
    \           // \u5076\u6570\u533A\u9593\u306F\u6607\u9806\u3001\u5947\u6570\u533A\
    \u9593\u306F\u964D\u9806\n            return (x_block & 1) ? (x.r > y.r) :(x.r\
    \ < y.r);\n        });\n\n        int cur_l = 0, cur_r = 0;\n        for (const\
    \ query& q : queries) {\n            while (cur_l > q.l) {\n                cur_l--;\
    \ add(cur_l);\n            }\n            while (cur_l < q.l) {\n            \
    \    del(cur_l); cur_l++;\n            }\n            while (cur_r > q.r) {\n\
    \                cur_r--; del(cur_r);\n            }\n            while (cur_r\
    \ < q.r) {\n                add(cur_r); cur_r++;\n            }\n\n          \
    \  output(q.id);\n        }\n    }\n\nprivate:\n    int N;\n    Add add;\n   \
    \ Del del;\n    struct query {\n        int l, r, id;\n    };\n    std::vector<query>\
    \ queries;\n};\n\n#endif // Mo_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2025-05-14 09:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Mo.hpp
layout: document
redirect_from:
- /library/Algorithm/Mo.hpp
- /library/Algorithm/Mo.hpp.html
title: Algorithm/Mo.hpp
---
