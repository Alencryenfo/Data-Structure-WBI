cmake_minimum_required(VERSION 3.30)
project(Data_Structure_WBI)

set(CMAKE_CXX_STANDARD 20)

add_executable(tmp tmp.cpp)

add_executable(1-1 SeqLinkedList/1.cpp)
add_executable(1-2 SeqLinkedList/2.cpp)
add_executable(1-3 SeqLinkedList/3.cpp)
add_executable(1-4 SeqLinkedList/4.cpp)
add_executable(1-5 SeqLinkedList/5.cpp)
add_executable(1-6 SeqLinkedList/6.cpp)
add_executable(1-7 SeqLinkedList/7.cpp)
add_executable(SeqLinkedList SeqLinkedList/SeqLinkedList.cpp)
add_executable(Stack SeqLinkedList/Stack.cpp)

add_executable(2-1 GeneralizedList/1.cpp)
add_executable(2-2 GeneralizedList/2.cpp)
add_executable(2-3 GeneralizedList/3.cpp)
add_executable(2-4 GeneralizedList/4.cpp)
add_executable(2-5 GeneralizedList/5.cpp)
add_executable(2-6 GeneralizedList/6.cpp)
