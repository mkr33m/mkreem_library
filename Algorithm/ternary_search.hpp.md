---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u51F8\u95A2\u6570\u306E [L, R] \u306B\u304A\u3051\u308B\u6700\
      \u5C0F\uFF08\u6700\u5927\u5024\uFF09\u3092\u8FD4\u3059"
    links: []
  bundledCode: "#line 1 \"Algorithm/ternary_search.hpp\"\n\n\n\n#include <tuple>\n\
    #include <functional>\n\n/**\n * @brief \u51F8\u95A2\u6570\u306E [L, R] \u306B\
    \u304A\u3051\u308B\u6700\u5C0F\uFF08\u6700\u5927\u5024\uFF09\u3092\u8FD4\u3059\
    \n * @param Arg \u8A55\u4FA1\u95A2\u6570 f \u306E\u5F15\u6570\u306E\u578B\n *\
    \ @param Val \u8A55\u4FA1\u95A2\u6570 f \u306E\u8FD4\u308A\u5024\u306E\u578B\n\
    \ * @param get_min true \u3067\u6700\u5C0F\u5024\u3001false \u3067\u6700\u5927\
    \u5024\u3092\u6C42\u3081\u308B\n * @return \u6700\u5C0F\uFF08\u6700\u5927\uFF09\
    \u5024\u3068\u306A\u308B\u5F15\u6570\u306E\u5024\u30FB\u6700\u5C0F\uFF08\u6700\
    \u5927\uFF09\u5024\u3092 pair \u3067\u8FD4\u3059\n */\ntemplate <typename Arg,\
    \ typename Val, bool get_min = true>\nstd::pair<Arg, Val> ternary_search(Arg L,\
    \ Arg R, const std::function<Val(Arg)>& f) {\n    int iter = 80;\n    while (iter--)\
    \ {\n        Arg l = (L * 2 + R) / 3;\n        Arg r = (L + R * 2) / 3;\n    \
    \    if ((f(l) < f(r)) ^ get_min) {\n            L = l;\n        } else {\n  \
    \          R = r;\n        }\n    }\n    return std::make_pair(L, f(L));\n}\n\n\
    \n"
  code: "#ifndef ternary_search_HPP\n#define ternary_search_HPP\n\n#include <tuple>\n\
    #include <functional>\n\n/**\n * @brief \u51F8\u95A2\u6570\u306E [L, R] \u306B\
    \u304A\u3051\u308B\u6700\u5C0F\uFF08\u6700\u5927\u5024\uFF09\u3092\u8FD4\u3059\
    \n * @param Arg \u8A55\u4FA1\u95A2\u6570 f \u306E\u5F15\u6570\u306E\u578B\n *\
    \ @param Val \u8A55\u4FA1\u95A2\u6570 f \u306E\u8FD4\u308A\u5024\u306E\u578B\n\
    \ * @param get_min true \u3067\u6700\u5C0F\u5024\u3001false \u3067\u6700\u5927\
    \u5024\u3092\u6C42\u3081\u308B\n * @return \u6700\u5C0F\uFF08\u6700\u5927\uFF09\
    \u5024\u3068\u306A\u308B\u5F15\u6570\u306E\u5024\u30FB\u6700\u5C0F\uFF08\u6700\
    \u5927\uFF09\u5024\u3092 pair \u3067\u8FD4\u3059\n */\ntemplate <typename Arg,\
    \ typename Val, bool get_min = true>\nstd::pair<Arg, Val> ternary_search(Arg L,\
    \ Arg R, const std::function<Val(Arg)>& f) {\n    int iter = 80;\n    while (iter--)\
    \ {\n        Arg l = (L * 2 + R) / 3;\n        Arg r = (L + R * 2) / 3;\n    \
    \    if ((f(l) < f(r)) ^ get_min) {\n            L = l;\n        } else {\n  \
    \          R = r;\n        }\n    }\n    return std::make_pair(L, f(L));\n}\n\n\
    #endif // ternary_search_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/ternary_search.hpp
  requiredBy: []
  timestamp: '2025-11-23 17:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/ternary_search.hpp
layout: document
redirect_from:
- /library/Algorithm/ternary_search.hpp
- /library/Algorithm/ternary_search.hpp.html
title: "\u51F8\u95A2\u6570\u306E [L, R] \u306B\u304A\u3051\u308B\u6700\u5C0F\uFF08\
  \u6700\u5927\u5024\uFF09\u3092\u8FD4\u3059"
---
