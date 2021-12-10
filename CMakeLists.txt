cmake_minimum_required(VERSION 3.17)
project(Dimas)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dimas main.cpp LinkedList.h DynamicArray.h ArraySequence.h LinkedListSequence.h Functions.h ISorter.h Node.h Sequences.h)