cmake_minimum_required(VERSION 3.17)
project(Book_Repo)

set(CMAKE_CXX_STANDARD 11)

add_executable(Book_Repo main.cpp degree.h roster.cpp roster.h student.cpp student.h)