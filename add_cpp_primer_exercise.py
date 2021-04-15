import os
import sys


def main():
    chapter = int(sys.argv[1])
    exercise_count = int(sys.argv[2])

    folder_path = "./src/cpp-primer/Chapter-%03d" % chapter
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)

    # 练习文件
    file_name = "primer-%02d-%02d.cpp"
    for num in range(1, exercise_count + 1):
        file_path = folder_path + "/" + file_name % (chapter, num)
        if not os.path.exists(file_path):
            with open(file_path, "w") as f:
                f.write(
                    """
#include "common.h"
"""
                )
        else:
            print("文件 %s 已存在" % (file_name % (chapter, num)))

    # 测试用 Main 文件
    file_name = "primer-%02d-main.cpp" % chapter
    file_path = folder_path + "/" + file_name
    if not os.path.exists(file_path):
        with open(file_path, "w") as f:
            f.write(
                """
#include "common.h"
"""
            )
    else:
        print("文件 %s 已存在" % file_name)


if __name__ == '__main__':
    main()
