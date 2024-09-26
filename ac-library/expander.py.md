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
  code: "#!/usr/bin/env python3\n\nimport re\nimport sys\nimport argparse\nfrom logging\
    \ import Logger, basicConfig, getLogger\nfrom os import getenv, environ\nfrom\
    \ pathlib import Path\nfrom typing import List\n\n\nlogger = getLogger(__name__)\
    \  # type: Logger\n\natcoder_include = re.compile('#include\\s*[\"<](atcoder/[a-z_]*(|.hpp))[\"\
    >]\\s*')\n\ninclude_guard = re.compile('#.*ATCODER_[A-Z_]*_HPP')\n\nlib_path =\
    \ Path.cwd()\n\ndefined = set()\n\ndef dfs(f: str) -> List[str]:\n    global defined\n\
    \    if f in defined:\n        logger.info('already included {}, skip'.format(f))\n\
    \        return []\n    defined.add(f)\n\n    logger.info('include {}'.format(f))\n\
    \n    s = open(str(lib_path / f)).read()\n    result = []\n    for line in s.splitlines():\n\
    \        if include_guard.match(line):\n            continue\n\n        m = atcoder_include.match(line)\n\
    \        if m:\n            result.extend(dfs(m.group(1)))\n            continue\n\
    \        result.append(line)\n    return result\n\n\nif __name__ == \"__main__\"\
    :\n    basicConfig(\n        format=\"%(asctime)s [%(levelname)s] %(message)s\"\
    ,\n        datefmt=\"%H:%M:%S\",\n        level=getenv('LOG_LEVEL', 'INFO'),\n\
    \    )\n    parser = argparse.ArgumentParser(description='Expander')\n    parser.add_argument('source',\
    \ help='Source File')\n    parser.add_argument('-c', '--console',\n          \
    \              action='store_true', help='Print to Console')\n    parser.add_argument('--lib',\
    \ help='Path to Atcoder Library')\n    opts = parser.parse_args()\n\n    if opts.lib:\n\
    \        lib_path = Path(opts.lib)\n    elif 'CPLUS_INCLUDE_PATH' in environ:\n\
    \        lib_path = Path(environ['CPLUS_INCLUDE_PATH'])\n    s = open(opts.source).read()\n\
    \n    result = []\n    for line in s.splitlines():\n        m = atcoder_include.match(line)\n\
    \n        if m:\n            result.extend(dfs(m.group(1)))\n            continue\n\
    \        result.append(line)\n\n    output = '\\n'.join(result) + '\\n'\n    if\
    \ opts.console:\n        print(output)\n    else:\n        with open('combined.cpp',\
    \ 'w') as f:\n            f.write(output)\n"
  dependsOn: []
  isVerificationFile: false
  path: ac-library/expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ac-library/expander.py
layout: document
redirect_from:
- /library/ac-library/expander.py
- /library/ac-library/expander.py.html
title: ac-library/expander.py
---
