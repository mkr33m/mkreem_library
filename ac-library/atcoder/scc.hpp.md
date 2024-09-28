---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ac-library/atcoder/internal_csr.hpp
    title: ac-library/atcoder/internal_csr.hpp
  - icon: ':warning:'
    path: ac-library/atcoder/internal_scc.hpp
    title: ac-library/atcoder/internal_scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/mkreem_library/mkreem_library/main',\
    \ '-fpreprocessed', '-dD', '-E', '/home/runner/work/mkreem_library/mkreem_library/main/ac-library/atcoder/internal_scc.hpp']'\
    \ returned non-zero exit status 1.\n"
  code: "#ifndef ATCODER_SCC_HPP\n#define ATCODER_SCC_HPP 1\n\n#include <algorithm>\n\
    #include \"internal_scc.hpp\"\n#ifndef ATCODER_INTERNAL_SCC_HPP\n#define ATCODER_INTERNAL_SCC_HPP\n\
    #endif\n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\nstruct\
    \ scc_graph {\n  public:\n    scc_graph() : internal(0) {}\n    explicit scc_graph(int\
    \ n) : internal(n) {}\n\n    void add_edge(int from, int to) {\n        int n\
    \ = internal.num_vertices();\n        assert(0 <= from && from < n);\n       \
    \ assert(0 <= to && to < n);\n        internal.add_edge(from, to);\n    }\n\n\
    \    std::vector<std::vector<int>> scc() { return internal.scc(); }\n\n  private:\n\
    \    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\n#endif  //\
    \ ATCODER_SCC_HPP"
  dependsOn:
  - ac-library/atcoder/internal_scc.hpp
  - ac-library/atcoder/internal_csr.hpp
  isVerificationFile: false
  path: ac-library/atcoder/scc.hpp
  requiredBy: []
  timestamp: '2024-09-28 19:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ac-library/atcoder/scc.hpp
layout: document
redirect_from:
- /library/ac-library/atcoder/scc.hpp
- /library/ac-library/atcoder/scc.hpp.html
title: ac-library/atcoder/scc.hpp
---
