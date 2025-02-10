cmake_minimum_required( VERSION 3.28 )

project( banksystem LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(external/Catch2)
add_subdirectory(test)