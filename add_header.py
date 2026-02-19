#!/usr/bin/env python3

import os


def add_header_batched(dir_path: str) -> None:
    assert os.path.exists(dir_path)

    for file in os.listdir(dir_path):
        if not file.endswith(".cpp"):
            continue

        with open(os.path.join(dir_path, file), "r") as f:
            content = f.readlines()

        line_no: int = 0
        for line_no, line in enumerate(content):
            if line.startswith("class "):
                break

        # identify header template
        template_line_0 = "#include <bits/stdc++.h>\n"
        template_line_1 = "using namespace std;\n"
        if content[line_no - 1] != template_line_1:
            print(f"add headers for file {file}")
            content.insert(line_no + 0, template_line_0)
            content.insert(line_no + 1, template_line_1)

        with open(os.path.join(dir_path, file), "w") as f:
            f.writelines(content)


def main() -> None:
    dir_path = "."
    add_header_batched(dir_path)


if __name__ == "__main__":
    main()
