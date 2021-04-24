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

        def __init__(self, cpps: List[str], mds: List[str]):
            self.cpp_files = cpps
            self.md_files = mds

    # 问题标号 到 ProblemFiles 对象
    problems: Dict[int, ProblemFiles] = dict()

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
        print(os.path.abspath(self.folder_path))
        for folder in os.listdir(self.folder_path):
            if not os.path.isdir("%s/%s" % (self.folder_path, folder)):
                continue
            m = p.match(folder)
            if m.lastindex < 1:
                continue
            problem_index = int(m.group(1))
            problem_folder_path = "%s/%s" % (self.folder_path, folder)
            cpp_files, md_files, = self._fetch_cpp_md_files(problem_folder_path)
            self.problems[problem_index] = self.ProblemFiles(cpp_files, md_files)

    def _fetch_cpp_md_files(self, problem_folder_path: str) -> Tuple[List[str], List[str]]:
        """
        获取文件夹下的 cpp 文件路径列表 和 md 文件路径列表 ,绝对路径保存
        :param problem_folder_path: Leetcode 问题文件夹
        :return: 0. cpps, 1. mds
        """
        if not os.path.exists(problem_folder_path):
            return [], []
        elif not os.path.isdir(problem_folder_path):
            return [], []

        cpp_file_list = []
        md_file_list = []

        for file_name in os.listdir(problem_folder_path):
            file_path = "%s/%s" % (problem_folder_path, file_name)
            if os.path.isdir(file_path):
                continue

            if file_path.endswith(".cpp"):
                cpp_file_list.append(file_path)
            elif file_path.endswith(".md"):
                md_file_list.append(file_path)

        return cpp_file_list, md_file_list



if __name__ == '__main__':
    p = LeetcodeFileParser("./src/leetcode")
