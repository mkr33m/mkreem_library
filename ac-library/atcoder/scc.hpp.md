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
  bundledCode: "#line 1 \"ac-library/atcoder/scc.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <atcoder/internal_scc>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0) {}\n\
    \    scc_graph(int n) : internal(n) {}\n\n    void add_edge(int from, int to)\
    \ {\n        int n = internal.num_vertices();\n        assert(0 <= from && from\
    \ < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from, to);\n\
    \    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc(); }\n\
    \n  private:\n    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\
    \n\n"
  code: "#ifndef ATCODER_SCC_HPP\n#define ATCODER_SCC_HPP 1\n\n#include <algorithm>\n\
    #include <atcoder/internal_scc>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0) {}\n\
    \    scc_graph(int n) : internal(n) {}\n\n    void add_edge(int from, int to)\
    \ {\n        int n = internal.num_vertices();\n        assert(0 <= from && from\
    \ < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from, to);\n\
    \    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc(); }\n\
    \n  private:\n    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_SCC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: ac-library/atcoder/scc.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ac-library/atcoder/scc.hpp
layout: document
redirect_from:
- /library/ac-library/atcoder/scc.hpp
- /library/ac-library/atcoder/scc.hpp.html
title: ac-library/atcoder/scc.hpp
---