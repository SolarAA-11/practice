import sys
import os
import datetime


def main():
    problem_number = int(sys.argv[1])

    fold_path = "./src/leetcode/leetcode-%04d" % problem_number
    if not os.path.exists(fold_path):
        os.makedirs(fold_path)

    filename = "%04d"%(problem_number) + "-" + datetime.datetime.now().strftime("%y%m%d") + ".cpp"
    file_path = fold_path + "/" + filename

    if not os.path.exists(file_path):
        fp = open(file_path, "w")
        fp.close()
    else:
        print("文件已存在, 路径: " + os.path.abspath(file_path))

if __name__ == '__main__':
    main()