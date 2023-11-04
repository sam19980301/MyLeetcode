#!/usr/bin/env python3

import os

dir_path = '.'
for file in os.listdir(dir_path):
    if (not file.endswith('.cpp')):
        continue
    
    with open(os.path.join(dir_path, file), 'r') as f:
        content = f.readlines()

    for line_no, line_words in list(enumerate(content))[::-1]:
        if (line_words.startswith('class ')):
            break
    
    if (content[line_no-2] != "#include <bits/stdc++.h>\n") or (content[line_no-1] != "using namespace std;\n"):
        print(f"add headers for file {file}")
        content.insert(line_no + 0, "#include <bits/stdc++.h>\n")
        content.insert(line_no + 1, "using namespace std;\n")
        with open(os.path.join(dir_path, file), 'w') as f:
            f.writelines(content)