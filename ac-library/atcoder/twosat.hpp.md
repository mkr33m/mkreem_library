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
  code: "#ifndef ATCODER_TWOSAT_HPP\n#define ATCODER_TWOSAT_HPP 1\n\n#include \"internal_scc.hpp\"\
    \n#ifndef ATCODER_INTERNAL_SCC_HPP\n#define ATCODER_INTERNAL_SCC_HPP\n#endif\n\
    #include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n// Reference:\n\
    // B. Aspvall, M. Plass, and R. Tarjan,\n// A Linear-Time Algorithm for Testing\
    \ the Truth of Certain Quantified Boolean\n// Formulas\nstruct two_sat {\n  public:\n\
    \    two_sat() : _n(0), scc(0) {}\n    explicit two_sat(int n) : _n(n), _answer(n),\
    \ scc(2 * n) {}\n\n    void add_clause(int i, bool f, int j, bool g) {\n     \
    \   assert(0 <= i && i < _n);\n        assert(0 <= j && j < _n);\n        scc.add_edge(2\
    \ * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n        scc.add_edge(2 * j + (g ?\
    \ 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n    bool satisfiable() {\n        auto\
    \ id = scc.scc_ids().second;\n        for (int i = 0; i < _n; i++) {\n       \
    \     if (id[2 * i] == id[2 * i + 1]) return false;\n            _answer[i] =\
    \ id[2 * i] < id[2 * i + 1];\n        }\n        return true;\n    }\n    std::vector<bool>\
    \ answer() { return _answer; }\n\n  private:\n    int _n;\n    std::vector<bool>\
    \ _answer;\n    internal::scc_graph scc;\n};\n\n}  // namespace atcoder\n\n#endif\
    \  // ATCODER_TWOSAT_HP"
  dependsOn:
  - ac-library/atcoder/internal_scc.hpp
  - ac-library/atcoder/internal_csr.hpp
  isVerificationFile: false
  path: ac-library/atcoder/twosat.hpp
  requiredBy: []
  timestamp: '2024-09-28 19:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ac-library/atcoder/twosat.hpp
layout: document
redirect_from:
- /library/ac-library/atcoder/twosat.hpp
- /library/ac-library/atcoder/twosat.hpp.html
title: ac-library/atcoder/twosat.hpp
---
