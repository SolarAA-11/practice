cmake_minimum_required(VERSION 3.16)
project(practice)

set(CMAKE_CXX_STANDARD 17)

# Utils Directory
include_directories("src/utils")

# Leetcode
file (GLOB files src/leetcode/leetcode-*/*.cpp src/cpp-primer/*/*.cpp)

foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()