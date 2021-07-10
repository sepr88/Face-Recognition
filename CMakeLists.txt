cmake_minimum_required(VERSION 3.10.0)

project(Face-Recognition VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(INCLUDE_DIR include)

set(SOURCES
        ./src/main.cpp
        include/myvector.h
        include/ringbuffer.h
        include/linked_list.h
        include/binary_tree.h)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})