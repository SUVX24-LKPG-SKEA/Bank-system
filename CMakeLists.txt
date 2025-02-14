cmake_minimum_required( VERSION 3.28 )

project( banksystem LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

unset( CMAKE_OSX_SYSROOT  )

find_package(Catch2 QUIET)
if(NOT Catch2_FOUND)
    find_package(Git QUIET)
    if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
        # Update submodules as needed
        option(GIT_SUBMODULE "Check submodules during build" ON)
        if(GIT_SUBMODULE)
            set(SUBMODULE_UPDATE_FLAG "${CMAKE_BINARY_DIR}/submodule_update_done")
            if(NOT EXISTS ${SUBMODULE_UPDATE_FLAG})
                message(STATUS "Submodule update")
                execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
                if(NOT GIT_SUBMOD_RESULT EQUAL "0")
                    message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
                else()
                    file(WRITE ${SUBMODULE_UPDATE_FLAG} "Submodules updated")
                endif()
            endif()
        endif()
    endif()

    if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/Catch2/CMakeLists.txt")
        message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
    else()
        add_subdirectory(external/Catch2)
    endif()
else ()
    message(STATUS "Found Catch2: ${Catch2_DIR}")
endif()

add_subdirectory(src)
add_subdirectory(test)s
