cmake_minimum_required( VERSION 3.28 )
project( banksystem-src LANGUAGES CXX )

include_directories( ../headers )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file( GLOB_RECURSE srcs ./**.cpp )
add_executable( main ${srcs} )