cmake_minimum_required(VERSION 3.21)
project(projectDomwn)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#increase the size of stack
MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(projectDomwn main.cpp Pair.cpp Pair.h unorderedTable.cpp unorderedTable.h orderedTable.cpp orderedTable.h binarySearchTree.cpp binarySearchTree.h avlSearchTree.cpp avlSearchTree.h)
