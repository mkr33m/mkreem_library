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
  bundledCode: "#line 1 \"Others/bisect.hpp\"\n\n\n\n#include <cmath>\n\ntemplate\
    \ <typename T, typename F>\nT bisect(T& ok, T& ng, const F& f) {\n    while (std::abs(ok\
    \ - ng) > 1) {\n        T mid = (ok - ng) / 2 + ng;\n        (f(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ok;\n}\n\ntemplate <typename T, typename F>\nT bisect_real(T&\
    \ ok, T& ng, const F& f, int itr = 100) {\n    while (itr--) {\n        T mid\
    \ = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n\
    }\n\n\n"
  code: "#ifndef bin_search_HPP\n#define bin_search_HPP\n\n#include <cmath>\n\ntemplate\
    \ <typename T, typename F>\nT bisect(T& ok, T& ng, const F& f) {\n    while (std::abs(ok\
    \ - ng) > 1) {\n        T mid = (ok - ng) / 2 + ng;\n        (f(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ok;\n}\n\ntemplate <typename T, typename F>\nT bisect_real(T&\
    \ ok, T& ng, const F& f, int itr = 100) {\n    while (itr--) {\n        T mid\
    \ = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n\
    }\n\n#endif // bisect_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/bisect.hpp
  requiredBy: []
  timestamp: '2025-03-11 07:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/bisect.hpp
layout: document
redirect_from:
- /library/Others/bisect.hpp
- /library/Others/bisect.hpp.html
title: Others/bisect.hpp
---
