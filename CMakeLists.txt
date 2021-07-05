cmake_minimum_required(VERSION 3.17)
project(AVL_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AVL_Tree
        AVL_ADT.h
        TestAVL.cpp data.h invertedIndex.h AvlTreeExt.h index.h node.h)
