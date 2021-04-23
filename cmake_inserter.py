import os
import re
from typing import Dict, Tuple, List


class CMakeInserter:
    def __init__(self, block_start_tag: str, block_end_tag: str):
        with open("./CMakeLists.txt", "r") as fp:
            self.cmake_file_lines = fp.readlines()
        within_block = False
        for line in self.cmake_file_lines:
            if not within_block and line is block_start_tag:
                within_block = True
                continue
            elif within_block and line is block_end_tag:
                within_block = False
                continue

            if within_block:
                pass


class LeetcodeFileParser:
    folder_path: str = ""

    # 某 Leetcode 问题对应的 Cpp 以及 Md 文件
    class ProblemFiles:
        cpp_files: List[str] = list()
        md_files: List[str] = list()

    # 问题标号 到 ProblemFiles 对象
    problems: Dict[int, ProblemFiles]

    def __init__(self, folder_path: str):
        if not os.path.exists(folder_path):
            raise ValueError("目录不存在: " + folder_path)
        elif not os.path.isdir(folder_path):
            raise ValueError("非目录: " + folder_path)

        self.folder_path = folder_path
        self._load_all_cpp_md_files()

    # 读取文件夹 self.folder_path 里所有 cpp 以及 md 文件
    # 保存到 self.problems
    def _load_all_cpp_md_files(self):
        p = re.compile("leetcode-(\d+)", re.I)
        for folder in os.listdir(self.folder_path):
            if not os.path.isdir(folder):
                continue

            m = p.match(folder)
            problem_index = int(m.group(1))



