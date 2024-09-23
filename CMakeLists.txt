cmake_minimum_required(VERSION 3.10...3.28)
project(LibBoostExamples)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_DEBUG ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost 1.86 REQUIRED
    COMPONENTS
        system
        filesystem
        random
        program_options
)

function(compile_executables target_name file_path)
    add_executable(${target_name} ${file_path})

    target_include_directories(${target_name}
        PRIVATE
            ${Boost_INCLUDE_DIRS}
    )

    target_link_libraries(${target_name}
        PRIVATE
            ${Boost_LIBRARIES}
    )
endfunction()

file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*/*.cpp")

foreach(file_path ${CPP_FILES})
    get_filename_component(target_name ${file_path} NAME_WE)
    compile_executables(${target_name} ${CMAKE_CURRENT_SOURCE_DIR}/${file_path})
endforeach()
