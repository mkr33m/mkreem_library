---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nfrom pathlib import Path\n\n# gen.py \u306E\u30C7\u30A3\u30EC\u30AF\
    \u30C8\u30EA\u306E\u76F8\u5BFE\u30D1\u30B9\ngen_dir = Path(__file__).resolve().parent\n\
    \nheader_dir = Path('.')\nmaster_header = header_dir / 'all_includes.hpp'\n\n\
    header_files = []\nfor filepath in header_dir.rglob('*.hpp'):\n    if filepath.name\
    \ == 'all_includes.hpp':\n        continue\n    # if 'ac-library' in filepath.parts:\n\
    \    #    continue\n    include_path = f'/home/pomelo/github.com/mkreem_library/{filepath.relative_to(header_dir).as_posix()}'\n\
    \    header_files.append(include_path)\n\nwith master_header.open('w') as f:\n\
    \    f.write('#ifndef all_includes_HPP\\n')\n    f.write('#define all_includes_HPP\\\
    n\\n')\n\n    for header in sorted(header_files):\n        f.write(f'#include\
    \ \"{header}\"\\n')\n\n    f.write('\\n#endif // all_includes_HPP\\n')\n"
  dependsOn: []
  isVerificationFile: false
  path: gen.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: gen.py
layout: document
redirect_from:
- /library/gen.py
- /library/gen.py.html
title: gen.py
---
