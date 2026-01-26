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
  bundledCode: "#line 1 \"Geometry/ArgSort.hpp\"\n\n\n\n#include <array>\n#include\
    \ <cassert>\n#include <cmath>\n#include <tuple>\n\ntemplate <int dx = 1, int dy\
    \ = 0, bool cw = false, typename T = long long>\nbool argcmp(const std::pair<T,\
    \ T> a, const std::pair<T, T> b) {\n    static_assert((dx == 0 or dy == 0) and\
    \ (std::abs(dx) + std::abs(dy) == 1),\n            \"basis must be one of (1,0),(0,1),(-1,0),(0,-1)\"\
    );\n    \n    std::array<int, 4> mp{};\n    if (dx == 1 and dy == 0) {\n     \
    \   if (cw) {\n            mp = {3, 2, 1, 0};\n        } else {\n            mp\
    \ = {0, 1, 2, 3};\n        }\n    } else if (dx == 0 and dy == 1) {\n        if\
    \ (cw) {\n            mp = {0, 3, 2, 1};\n        } else {\n            mp = {3,\
    \ 0, 1, 2};\n        }\n    } else if (dx == -1 and dy == 0) {\n        if (cw)\
    \ {\n            mp = {1, 0, 3, 2};\n        } else {\n            mp = {2, 3,\
    \ 0, 1};\n        }\n    } else if (dx == 0 and dy == -1) {\n        if (cw) {\n\
    \            mp = {2, 1, 0, 3};\n        } else {\n            mp = {1, 2, 3,\
    \ 0};\n        }\n    }\n\n    auto shogen = [&](const T& x, const T& y) {\n \
    \       bool xp = (x >= 0), yp = (y >= 0);\n        if ( xp and  yp) return mp[0];\n\
    \        if (!xp and  yp) return mp[1];\n        if (!xp and !yp) return mp[2];\n\
    \        return mp[3]; // (xp and !yp)\n    };\n\n    const T x1 = a.first, y1\
    \ = a.second, x2 = b.first, y2 = b.second;\n    const int s1 = shogen(x1, y1),\
    \ s2 = shogen(x2, y2);\n    if (s1 != s2) {\n        return s1 < s2;\n    }\n\n\
    \    auto cross = [](__int128 x1, __int128 y1, __int128 x2, __int128 y2) -> __int128\
    \ {\n        return x1 * y2 - y1 * x2;\n    };\n\n    __int128 c = cross(x1, y1,\
    \ x2, y2);\n    if (cw) {\n        return c < 0;\n    }\n    return c > 0;\n}\n\
    \n\n"
  code: "#ifndef ArgSort_HPP\n#define ArgSort_HPP\n\n#include <array>\n#include <cassert>\n\
    #include <cmath>\n#include <tuple>\n\ntemplate <int dx = 1, int dy = 0, bool cw\
    \ = false, typename T = long long>\nbool argcmp(const std::pair<T, T> a, const\
    \ std::pair<T, T> b) {\n    static_assert((dx == 0 or dy == 0) and (std::abs(dx)\
    \ + std::abs(dy) == 1),\n            \"basis must be one of (1,0),(0,1),(-1,0),(0,-1)\"\
    );\n    \n    std::array<int, 4> mp{};\n    if (dx == 1 and dy == 0) {\n     \
    \   if (cw) {\n            mp = {3, 2, 1, 0};\n        } else {\n            mp\
    \ = {0, 1, 2, 3};\n        }\n    } else if (dx == 0 and dy == 1) {\n        if\
    \ (cw) {\n            mp = {0, 3, 2, 1};\n        } else {\n            mp = {3,\
    \ 0, 1, 2};\n        }\n    } else if (dx == -1 and dy == 0) {\n        if (cw)\
    \ {\n            mp = {1, 0, 3, 2};\n        } else {\n            mp = {2, 3,\
    \ 0, 1};\n        }\n    } else if (dx == 0 and dy == -1) {\n        if (cw) {\n\
    \            mp = {2, 1, 0, 3};\n        } else {\n            mp = {1, 2, 3,\
    \ 0};\n        }\n    }\n\n    auto shogen = [&](const T& x, const T& y) {\n \
    \       bool xp = (x >= 0), yp = (y >= 0);\n        if ( xp and  yp) return mp[0];\n\
    \        if (!xp and  yp) return mp[1];\n        if (!xp and !yp) return mp[2];\n\
    \        return mp[3]; // (xp and !yp)\n    };\n\n    const T x1 = a.first, y1\
    \ = a.second, x2 = b.first, y2 = b.second;\n    const int s1 = shogen(x1, y1),\
    \ s2 = shogen(x2, y2);\n    if (s1 != s2) {\n        return s1 < s2;\n    }\n\n\
    \    auto cross = [](__int128 x1, __int128 y1, __int128 x2, __int128 y2) -> __int128\
    \ {\n        return x1 * y2 - y1 * x2;\n    };\n\n    __int128 c = cross(x1, y1,\
    \ x2, y2);\n    if (cw) {\n        return c < 0;\n    }\n    return c > 0;\n}\n\
    \n#endif // ArgSort_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/ArgSort.hpp
  requiredBy:
  - all_includes.hpp
  timestamp: '2026-01-26 21:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/ArgSort.hpp
layout: document
redirect_from:
- /library/Geometry/ArgSort.hpp
- /library/Geometry/ArgSort.hpp.html
title: Geometry/ArgSort.hpp
---
