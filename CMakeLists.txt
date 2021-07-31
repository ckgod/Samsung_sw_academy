cmake_minimum_required(VERSION 3.17)
project(BOJproject)

set(CMAKE_CXX_STANDARD 14)

add_executable(BOJproject graph/bfs_main.cpp graph/bfs_user.cpp)