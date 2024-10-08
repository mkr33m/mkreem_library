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
  bundledCode: "#line 1 \"Others/Debug.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <fstream>\n#include <vector>\n#include <set>\n#include <map>\n\nstd::ofstream\
    \ debug_outfile;\nstd::ostream* debug_out = &std::cout;\n\nvoid Initialize_DebugOutput(){\n\
    \    debug_outfile.open(\"debug.txt\");\n    debug_out = &debug_outfile;\n}\n\n\
    #ifdef LOCAL\n\nnamespace debug {\n\n    template <typename T>\n    void debug_print(const\
    \ T& t){\n        *debug_out << t;\n    }\n\n    template <typename T, typename...\
    \ Args>\n    void debug_print(const T& t, const Args&... args){\n        *debug_out\
    \ << t << \", \";\n        debug_print(args...);\n    }\n\n    // pair\n    template\
    \ <typename T1, typename T2>\n    void debug_print(const std::pair<T1, T2>& p){\n\
    \        *debug_out << \"{\" << p.first << \", \" << p.second << \"}\";\n    }\n\
    \n    // tuple\n    template <typename Tuple, std::size_t... Is>\n    void print_tuple(const\
    \ Tuple& t, std::index_sequence<Is...>){\n        ((*debug_out << (Is == 0 ? \"\
    \" : \", \") << std::get<Is>(t)), ...);\n    }\n\n    template <typename... Args>\n\
    \    void debug_print(const std::tuple<Args...>& t){\n        *debug_out << \"\
    {\";\n        print_tuple(t, std::index_sequence_for<Args...>{});\n        *debug_out\
    \ << \"}\";\n    }\n\n    // map\n    template <typename Key, typename Value>\n\
    \    void debug_print(const std::map<Key, Value>& m){\n        *debug_out << \"\
    {\\n\";\n        for(auto it = m.begin(); it != m.end(); it++){\n            if(it\
    \ != m.begin()) *debug_out << \",\\n\";\n            debug_print(*it);\n     \
    \   }\n        *debug_out << \"\\n}\";\n    }\n\n    // set\n    template <typename\
    \ T>\n    void debug_print(const std::set<T>& s){\n        *debug_out << \"{\"\
    ;\n        for(auto it = s.begin(); it != s.end(); it++){\n            if(it !=\
    \ s.begin()) *debug_out << \", \";\n            *debug_out << *it;\n        }\n\
    \        *debug_out << \"}\";\n    }\n\n    // 1D vector\n    template <typename\
    \ T>\n    void debug_print(const std::vector<T>& vec){\n        *debug_out <<\
    \ \"[\";\n        bool f = std::is_integral<T>::value || std::is_floating_point<T>::value\
    \ || std::is_same<T, char>::value;\n        for(size_t i = 0; i < vec.size();\
    \ i++){\n            if(!f){\n                *debug_out << '\\n';\n         \
    \   }\n            debug_print(vec[i]);\n            if(i != vec.size() - 1) *debug_out\
    \ << \", \";\n        }\n        if(!f){\n            *debug_out << '\\n';\n \
    \       }\n        *debug_out << \"]\";\n    }\n\n    // 2D vector\n    template\
    \ <typename T>\n    void debug_print(const std::vector<std::vector<T>>& vec){\n\
    \        *debug_out << \"[\\n\";\n        for(const auto& row : vec){\n      \
    \      *debug_out << \"  \";\n            debug_print(row);\n            *debug_out\
    \ << \"\\n\";\n        }\n        *debug_out << \"]\";\n    }\n\n} // namespace\
    \ debug\n\n#define debug(...) do{ \\\n    *debug_out << #__VA_ARGS__ << \" = \"\
    ; \\\n    debug::debug_print(__VA_ARGS__); \\\n    *debug_out << '\\n'; \\\n}\
    \ while(0)\n#else\n#define debug(...) do {} while(0)\n#endif\n\n\n"
  code: "#ifndef Debug_HPP\n#define Debug_HPP\n\n#include <iostream>\n#include <fstream>\n\
    #include <vector>\n#include <set>\n#include <map>\n\nstd::ofstream debug_outfile;\n\
    std::ostream* debug_out = &std::cout;\n\nvoid Initialize_DebugOutput(){\n    debug_outfile.open(\"\
    debug.txt\");\n    debug_out = &debug_outfile;\n}\n\n#ifdef LOCAL\n\nnamespace\
    \ debug {\n\n    template <typename T>\n    void debug_print(const T& t){\n  \
    \      *debug_out << t;\n    }\n\n    template <typename T, typename... Args>\n\
    \    void debug_print(const T& t, const Args&... args){\n        *debug_out <<\
    \ t << \", \";\n        debug_print(args...);\n    }\n\n    // pair\n    template\
    \ <typename T1, typename T2>\n    void debug_print(const std::pair<T1, T2>& p){\n\
    \        *debug_out << \"{\" << p.first << \", \" << p.second << \"}\";\n    }\n\
    \n    // tuple\n    template <typename Tuple, std::size_t... Is>\n    void print_tuple(const\
    \ Tuple& t, std::index_sequence<Is...>){\n        ((*debug_out << (Is == 0 ? \"\
    \" : \", \") << std::get<Is>(t)), ...);\n    }\n\n    template <typename... Args>\n\
    \    void debug_print(const std::tuple<Args...>& t){\n        *debug_out << \"\
    {\";\n        print_tuple(t, std::index_sequence_for<Args...>{});\n        *debug_out\
    \ << \"}\";\n    }\n\n    // map\n    template <typename Key, typename Value>\n\
    \    void debug_print(const std::map<Key, Value>& m){\n        *debug_out << \"\
    {\\n\";\n        for(auto it = m.begin(); it != m.end(); it++){\n            if(it\
    \ != m.begin()) *debug_out << \",\\n\";\n            debug_print(*it);\n     \
    \   }\n        *debug_out << \"\\n}\";\n    }\n\n    // set\n    template <typename\
    \ T>\n    void debug_print(const std::set<T>& s){\n        *debug_out << \"{\"\
    ;\n        for(auto it = s.begin(); it != s.end(); it++){\n            if(it !=\
    \ s.begin()) *debug_out << \", \";\n            *debug_out << *it;\n        }\n\
    \        *debug_out << \"}\";\n    }\n\n    // 1D vector\n    template <typename\
    \ T>\n    void debug_print(const std::vector<T>& vec){\n        *debug_out <<\
    \ \"[\";\n        bool f = std::is_integral<T>::value || std::is_floating_point<T>::value\
    \ || std::is_same<T, char>::value;\n        for(size_t i = 0; i < vec.size();\
    \ i++){\n            if(!f){\n                *debug_out << '\\n';\n         \
    \   }\n            debug_print(vec[i]);\n            if(i != vec.size() - 1) *debug_out\
    \ << \", \";\n        }\n        if(!f){\n            *debug_out << '\\n';\n \
    \       }\n        *debug_out << \"]\";\n    }\n\n    // 2D vector\n    template\
    \ <typename T>\n    void debug_print(const std::vector<std::vector<T>>& vec){\n\
    \        *debug_out << \"[\\n\";\n        for(const auto& row : vec){\n      \
    \      *debug_out << \"  \";\n            debug_print(row);\n            *debug_out\
    \ << \"\\n\";\n        }\n        *debug_out << \"]\";\n    }\n\n} // namespace\
    \ debug\n\n#define debug(...) do{ \\\n    *debug_out << #__VA_ARGS__ << \" = \"\
    ; \\\n    debug::debug_print(__VA_ARGS__); \\\n    *debug_out << '\\n'; \\\n}\
    \ while(0)\n#else\n#define debug(...) do {} while(0)\n#endif\n\n#endif // Debug_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Others/Debug.hpp
  requiredBy: []
  timestamp: '2024-10-08 16:08:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Debug.hpp
layout: document
redirect_from:
- /library/Others/Debug.hpp
- /library/Others/Debug.hpp.html
title: Others/Debug.hpp
---
