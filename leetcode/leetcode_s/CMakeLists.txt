cmake_minimum_required(VERSION 3.29)
project(leetcode_s)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_s
    leetcode/editor/cn/559_maximum-depth-of-n-ary-tree.cpp)

add_executable(222_count-complete-tree-nodes leetcode/editor/cn/222_count-complete-tree-nodes.cpp)
add_executable(110_balanced-binary-tree leetcode/editor/cn/110_balanced-binary-tree.cpp)
add_executable(257_binary-tree-paths leetcode/editor/cn/257_binary-tree-paths.cpp)
add_executable(404_sum-of-left-leaves leetcode/editor/cn/404_sum-of-left-leaves.cpp)
add_executable(513_find-bottom-left-tree-value leetcode/editor/cn/513_find-bottom-left-tree-value.cpp)
add_executable(112_path-sum leetcode/editor/cn/112_path-sum.cpp)
add_executable(113_path-sum-ii leetcode/editor/cn/113_path-sum-ii.cpp)