cmake_minimum_required(VERSION 3.21)
project(Module_8)

set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Wall -Wextra -Werror)

add_executable(Module_8_ex00 ex00/main.cpp ex00/easyfind.hpp)
add_executable(Module_8_ex01 ex01/main.cpp ex01/Span.cpp ex01/Span.hpp)
add_executable(Module_8_ex02 ex02/main.cpp ex02/MutantStack.hpp)
