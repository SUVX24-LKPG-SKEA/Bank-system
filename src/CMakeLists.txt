cmake_minimum_required( VERSION 3.28 )
project( banksystem-src LANGUAGES CXX )

include_directories( ../headers /opt/homebrew/opt/llvm/include /opt/homebrew/opt/llvm/include/c++/v1 )
link_directories( /opt/homebrew/opt/llvm/lib )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file( GLOB_RECURSE srcs ./**.cpp )
add_executable( main ${srcs} )