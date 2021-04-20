import sys
import os
import datetime

def write_leetcode_file(file_path: str) -> bool:
    if not os.path.exists(file_path):
        with open(file_path, "w") as f:
            f.write(
"""
#include "common.h"



int main() {
    Solution s;
}
"""
            )
        return True
    else:
        return False


def create_readme(fold_file: str):
    readme_path = "%s/README.md" % fold_file
    if not os.path.exists(readme_path):
        with open(readme_path, "w") as f:
            pass


def main():
    problem_number = int(sys.argv[1])

    fold_path = "./src/leetcode/leetcode-%04d" % problem_number
    if not os.path.exists(fold_path):
        os.makedirs(fold_path)

    create_readme(fold_path)

    file_name = "%04d"%(problem_number) + "-" + datetime.datetime.now().strftime("%y%m%d")
    file_path = "%s/%s.cpp" % (fold_path, file_name)

    if not write_leetcode_file(file_path):
        count = 1
        while True:
            new_file_path = "%s/%s-%03d.cpp" % (fold_path, file_name, count)
            if write_leetcode_file(new_file_path):
                print("新建 Leetcode 重试文件: %s" % new_file_path)
                break
            else:
                count += 1
    else:
        print("新建 Leetcode 文件: %s" % file_path)


if __name__ == '__main__':
    main()