cmake_minimum_required(VERSION 3.3)
project(PinaHW9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        HashTable.cpp HashTable.h
        LinkedList.cpp LinkedList.h
        )
add_executable(PinaHW9 ${SOURCE_FILES})