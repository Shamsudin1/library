cmake_minimum_required(VERSION 3.10)
project(Libriary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(libriary
    src/main.cpp
    src/Book.cpp
    src/Reader.cpp
    src/Libriary.cpp
    src/Loan.cpp
    src/Storage.cpp
)