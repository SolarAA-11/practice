import re


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
