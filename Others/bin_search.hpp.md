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
  bundledCode: "#line 1 \"Others/bin_search.hpp\"\n\n\n\n#include <cmath>\n\ntemplate\
    \ <typename T, typename F>\n/**\n * @param ok \u89E3\u304C\u5B58\u5728\u3059\u308B\
    \u5024\n * @param ng \u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u5024\n * @remark\
    \ ok > ng \u306E\u5834\u5408\u306F\u6700\u5C0F\u5024\u3001ok < ng \u306E\u5834\
    \u5408\u306F\u6700\u5927\u5024\u3092\u8FD4\u5374\n */\nT bin_search(T& ok, T&\
    \ ng, const F& f){\n    while(std::abs(ok - ng) > 1){\n        T mid = (ok - ng)\
    \ / 2 + ng;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\ntemplate\
    \ <typename T, typename F>\nT bin_search_real(T& ok, T& ng, const F& f, int itr\
    \ = 100){\n    while(itr--){\n        T mid = (ok + ng) / 2;\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n\n"
  code: "#ifndef bin_search_HPP\n#define bin_search_HPP\n\n#include <cmath>\n\ntemplate\
    \ <typename T, typename F>\n/**\n * @param ok \u89E3\u304C\u5B58\u5728\u3059\u308B\
    \u5024\n * @param ng \u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u5024\n * @remark\
    \ ok > ng \u306E\u5834\u5408\u306F\u6700\u5C0F\u5024\u3001ok < ng \u306E\u5834\
    \u5408\u306F\u6700\u5927\u5024\u3092\u8FD4\u5374\n */\nT bin_search(T& ok, T&\
    \ ng, const F& f){\n    while(std::abs(ok - ng) > 1){\n        T mid = (ok - ng)\
    \ / 2 + ng;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\ntemplate\
    \ <typename T, typename F>\nT bin_search_real(T& ok, T& ng, const F& f, int itr\
    \ = 100){\n    while(itr--){\n        T mid = (ok + ng) / 2;\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n#endif // bin_search_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/bin_search.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/bin_search.hpp
layout: document
redirect_from:
- /library/Others/bin_search.hpp
- /library/Others/bin_search.hpp.html
title: Others/bin_search.hpp
---
