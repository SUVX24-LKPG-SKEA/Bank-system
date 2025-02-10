cmake_minimum_required( VERSION 3.28 )
project( banksystem-test LANGUAGES CXX )

enable_testing()

set( CMAKE_CXX_STANDARD_REQUIRED 23 )
set( CMAKE_CXX_STANDARD 23 )
set( CXX_STANDARD_REQUIRED 23 )

# find_package( Catch2 REQUIRED )
include_directories( ../headers ${Catch2_DIRS} )

file( GLOB_RECURSE srcs ../src/**.cpp )
list( FILTER srcs EXCLUDE REGEX .+/main\.cpp )

add_executable( tests ${srcs} ./test.cpp )

target_link_libraries( tests PRIVATE Catch2::Catch2WithMain )

include( CTest )
include( Catch )

catch_discover_tests( tests )