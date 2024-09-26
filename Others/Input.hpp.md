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
  bundledCode: "#line 1 \"Others/Input.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n\nnamespace input {\n\n    template <typename T>\n    void read(T&\
    \ t){\n        std::cin >> t;\n    }\n\n    template <typename T, typename...\
    \ Args>\n    void read(T& t, Args&... args){\n        std::cin >> t;\n       \
    \ read(args...);\n    }\n\n} // namespace input\n\n#define READ(type, ...) \\\n\
    \    type __VA_ARGS__; \\\n    input::read(__VA_ARGS__)\n#define INT(...) READ(int,\
    \ __VA_ARGS__)\n#define LL(...) READ(long long, __VA_ARGS__)\n#define DBL(...)\
    \ READ(double, __VA_ARGS__)\n#define LD(...) READ(long double, __VA_ARGS__)\n\
    #define STR(...) READ(std::string, __VA_ARGS__)\n#define CHA(...) READ(char, __VA_ARGS__)\n\
    #define VI(vec, type, a) std::vector<type> vec(a); for(int i = 0; i < a; i++)\
    \ std::cin >> vec[i]\n#define VI2(vec1, vec2, type, a, b) std::vector<type> vec1(a),\
    \ vec2(b); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int i = 0; i <\
    \ b; i++) std::cin >> vec2[i]\n#define VI3(vec1, vec2, vec3, type, a, b, c) std::vector<type>\
    \ vec1(a), vec2(b), vec3(c); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int\
    \ i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin\
    \ >> vec3[i]\n#define VI4(vec1, vec2, vec3, vec4, type, a, b, c, d) std::vector<type>\
    \ vec1(a), vec2(b), vec3(c), vec4(d); for(int i = 0; i < a; i++) std::cin >> vec1[i];\
    \ for(int i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin\
    \ >> vec3[i]; for(int i = 0; i < d; i++) std::cin >> vec4[i]\n#define VI5(vec1,\
    \ vec2, vec3, vec4, vec5, type, a, b, c, d, e) std::vector<type> vec1(a), vec2(b),\
    \ vec3(c), vec4(d), vec5(e); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int\
    \ i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin\
    \ >> vec3[i]; for(int i = 0; i < d; i++) std::cin >> vec4[i]; for(int i = 0; i\
    \ < e; i++) std::cin >> vec5[i]\n#define VI2_(vec1, vec2, type, a) std::vector<type>\
    \ vec1(a), vec2(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i]\n\
    #define VI3_(vec1, vec2, vec3, type, a) std::vector<type> vec1(a), vec2(a), vec3(a);\
    \ for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i]\n#define\
    \ VI4_(vec1, vec2, vec3, vec4, type, a) std::vector<type> vec1(a), vec2(a), vec3(a),\
    \ vec4(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i]\
    \ >> vec4[i]\n#define VI5_(vec1, vec2, vec3, vec4, vec5, type, a) std::vector<type>\
    \ vec1(a), vec2(a), vec3(a), vec4(a), vec5(a); for(int i = 0; i < a; i++) std::cin\
    \ >> vec1[i] >> vec2[i] >> vec3[i] >> vec4[i] >> vec5[i]\n#define VVI(vec, type,\
    \ a, b) std::vector<std::vector<type>> vec(a, std::vector<type>(b)); for(int i\
    \ = 0; i < a; i++) for(int j = 0; j < b; j++) std::cin >> vec[i][j]\n\n\n"
  code: "#ifndef Input_HPP\n#define Input_HPP\n\n#include <iostream>\n#include <vector>\n\
    \nnamespace input {\n\n    template <typename T>\n    void read(T& t){\n     \
    \   std::cin >> t;\n    }\n\n    template <typename T, typename... Args>\n   \
    \ void read(T& t, Args&... args){\n        std::cin >> t;\n        read(args...);\n\
    \    }\n\n} // namespace input\n\n#define READ(type, ...) \\\n    type __VA_ARGS__;\
    \ \\\n    input::read(__VA_ARGS__)\n#define INT(...) READ(int, __VA_ARGS__)\n\
    #define LL(...) READ(long long, __VA_ARGS__)\n#define DBL(...) READ(double, __VA_ARGS__)\n\
    #define LD(...) READ(long double, __VA_ARGS__)\n#define STR(...) READ(std::string,\
    \ __VA_ARGS__)\n#define CHA(...) READ(char, __VA_ARGS__)\n#define VI(vec, type,\
    \ a) std::vector<type> vec(a); for(int i = 0; i < a; i++) std::cin >> vec[i]\n\
    #define VI2(vec1, vec2, type, a, b) std::vector<type> vec1(a), vec2(b); for(int\
    \ i = 0; i < a; i++) std::cin >> vec1[i]; for(int i = 0; i < b; i++) std::cin\
    \ >> vec2[i]\n#define VI3(vec1, vec2, vec3, type, a, b, c) std::vector<type> vec1(a),\
    \ vec2(b), vec3(c); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int i\
    \ = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin >>\
    \ vec3[i]\n#define VI4(vec1, vec2, vec3, vec4, type, a, b, c, d) std::vector<type>\
    \ vec1(a), vec2(b), vec3(c), vec4(d); for(int i = 0; i < a; i++) std::cin >> vec1[i];\
    \ for(int i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin\
    \ >> vec3[i]; for(int i = 0; i < d; i++) std::cin >> vec4[i]\n#define VI5(vec1,\
    \ vec2, vec3, vec4, vec5, type, a, b, c, d, e) std::vector<type> vec1(a), vec2(b),\
    \ vec3(c), vec4(d), vec5(e); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int\
    \ i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin\
    \ >> vec3[i]; for(int i = 0; i < d; i++) std::cin >> vec4[i]; for(int i = 0; i\
    \ < e; i++) std::cin >> vec5[i]\n#define VI2_(vec1, vec2, type, a) std::vector<type>\
    \ vec1(a), vec2(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i]\n\
    #define VI3_(vec1, vec2, vec3, type, a) std::vector<type> vec1(a), vec2(a), vec3(a);\
    \ for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i]\n#define\
    \ VI4_(vec1, vec2, vec3, vec4, type, a) std::vector<type> vec1(a), vec2(a), vec3(a),\
    \ vec4(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i]\
    \ >> vec4[i]\n#define VI5_(vec1, vec2, vec3, vec4, vec5, type, a) std::vector<type>\
    \ vec1(a), vec2(a), vec3(a), vec4(a), vec5(a); for(int i = 0; i < a; i++) std::cin\
    \ >> vec1[i] >> vec2[i] >> vec3[i] >> vec4[i] >> vec5[i]\n#define VVI(vec, type,\
    \ a, b) std::vector<std::vector<type>> vec(a, std::vector<type>(b)); for(int i\
    \ = 0; i < a; i++) for(int j = 0; j < b; j++) std::cin >> vec[i][j]\n\n#endif\
    \ // Input_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/Input.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Input.hpp
layout: document
redirect_from:
- /library/Others/Input.hpp
- /library/Others/Input.hpp.html
title: Others/Input.hpp
---
