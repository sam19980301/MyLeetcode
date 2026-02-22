#!/usr/bin/env python3

import os


def add_header_batched(dir_path: str) -> None:
    assert os.path.exists(dir_path)

    line_include_wildcard_header = "#include <bits/stdc++.h>\n"
    line_using_std = "using namespace std;\n"

    for file in os.listdir(dir_path):
        if not file.endswith(".cpp"):
            continue

        with open(os.path.join(dir_path, file), "r") as f:
            content = f.readlines()

        line_no: int = 0
        add_include_header_statements: bool = False
        struct_str_list: list[str] = list()
        for line_no, line in enumerate(content):
            if line.startswith(" * Definition for "):
                struct_str_list.append(line_include_wildcard_header)
                curr_struct_line_no = line_no + 1
                finished_parsing_struct = False
                while not finished_parsing_struct:
                    if content[curr_struct_line_no] == " * };\n":
                        finished_parsing_struct = True
                    struct_str_list.append(content[curr_struct_line_no].lstrip(" *"))
                    curr_struct_line_no += 1
            if line == line_using_std:
                add_include_header_statements = True
            if line.startswith("class "):
                break

        template_lines: list[str] = [
            line_include_wildcard_header,
            line_using_std,
        ]
        if struct_str_list:
            print(f"add headers file for file {file}")
            extra_header_file = file.replace(".cpp", ".h")
            with open(os.path.join(dir_path, "include", extra_header_file), "w") as f:
                f.writelines(struct_str_list)
            template_lines.insert(0, "#ifdef LEETCODE_LOCAL_DEV\n")
            template_lines.insert(1, f'#include "{extra_header_file}"\n')
            template_lines.insert(2, "#endif\n")

        if not add_include_header_statements:
            print(f"add include headers statements for file {file}")
            for i, line in enumerate(template_lines):
                content.insert(line_no + i, line)

        with open(os.path.join(dir_path, file), "w") as f:
            f.writelines(content)


def main() -> None:
    dir_path = "."
    add_header_batched(dir_path)


if __name__ == "__main__":
    main()
