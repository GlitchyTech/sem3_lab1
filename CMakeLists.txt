cmake_minimum_required(VERSION 3.17)
project(sem3_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(sem3_lab1 main.cpp Utils.cpp Utils.hpp SortImplementation.hpp Sort.hpp ArraySequence.hpp ArraySequenceImplementation.hpp
               DynamicArray.hpp DynamicArrayImplementation.hpp ISequence.hpp List.hpp ListImplementation.hpp ListSequence.hpp
               ListSequenceImplementation.hpp Test.cpp Test.hpp Interface.cpp Interface.hpp)