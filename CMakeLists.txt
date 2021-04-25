cmake_minimum_required(VERSION 3.16)
project(practice)

set(CMAKE_CXX_STANDARD 17)

# Utils Directory
include_directories("src/utils")

# Leetcode
file (GLOB files src/leetcode/leetcode-*/*.cpp src/cpp-primer/*/*.cpp src/leetcode-weekly-contest/*/*.cpp)

foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} src/leetcode-weekly-contest/contest-238/contest-238-1.cpp src/leetcode-weekly-contest/contest-238/contest-238-2.cpp src/leetcode-weekly-contest/contest-238/contest-238-3.cpp src/leetcode-weekly-contest/contest-238/contest-238-4.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()