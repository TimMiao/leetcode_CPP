cmake_minimum_required(VERSION 3.30)
project(leetcode_CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode_CPP main.cpp
        "Pascal Triangle/pascal_triangle.h"
        "Pascal Triangle/pascal_triangle.cpp"
        "Pascal Triangle/main.cpp"
        "Palindrome Linked List/main.cpp"
        "Climbing Stairs/ClimbingStairs.cpp")
