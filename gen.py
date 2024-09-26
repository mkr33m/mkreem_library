import os
from pathlib import Path

# gen.py のディレクトリの相対パス
gen_dir = Path(__file__).resolve().parent

header_dir = Path('.')
master_header = header_dir / 'all_includes.hpp'

header_files = []
for filepath in header_dir.rglob('*.hpp'):
    if filepath.name == 'all_includes.hpp':
        continue
    # if 'ac-library' in filepath.parts:
    #    continue
    include_path = f'/home/pomelo/github.com/mkreem_library/{filepath.relative_to(header_dir).as_posix()}'
    header_files.append(include_path)

with master_header.open('w') as f:
    f.write('#ifndef all_includes_HPP\n')
    f.write('#define all_includes_HPP\n\n')

    for header in sorted(header_files):
        f.write(f'#include "{header}"\n')

    f.write('\n#endif // all_includes_HPP\n')
