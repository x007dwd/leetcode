cmake_minimum_required(VERSION 2.8)
project(leetcode)
add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(String src/String.cpp)
add_executable(BinTree src/BinTree.cpp)
add_executable(LinkList src/LinkList.cpp)
add_executable(sort src/sort.cpp)
add_executable(sparse_matrix src/sparse_matrix_mul.cpp)
add_executable(top_k src/top_k_words.cpp)
add_executable(transStatus src/TransStatus.cpp)
