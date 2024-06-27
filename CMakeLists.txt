cmake_minimum_required(VERSION 3.5)


project(Cayley)

set(CMAKE_CXX_STANDARD 23)

add_executable(test tests/Run.cpp)

add_compile_options(-g -std=gnu++23)
add_compile_options(-Wall -fconcepts -lstdc++exp)
