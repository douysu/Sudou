cmake_minimum_required (VERSION 3.1)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)
project (Sudou)

# set output dir
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})
set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})

# include
include_directories(
    "${CMAKE_SOURCE_DIR}/Engine/Source"
    "${CMAKE_SOURCE_DIR}/Engine/Source/ThirdParty"
    "${CMAKE_SOURCE_DIR}/Engine/Source/ThirdParty/spdlog/include"
)

# file
set(SRC_ROOT_PATH "${CMAKE_SOURCE_DIR}/Engine/Source")
file(
    GLOB_RECURSE SOURCE_LIST 
    LIST_DIRECTORIES false
    "${SRC_ROOT_PATH}/Runtime/*.c*"
    "${SRC_ROOT_PATH}/Runtime/*.h*"
)
file(GLOB SOURCE_EDITOR
    "Engine/Source/Editor/*.cpp"
    "Engine/Source/Editor/*.h"
)

# platform
if (WIN32)
    add_definitions(-DSUDOU_PLATFORM_WINDOWS)
    include(${CMAKE_SOURCE_DIR}/cmake/windows.cmake)
    assign_source_group(${SOURCE_LIST})
elseif (UNIX AND NOT APPLE)
    message(STATUS "Is Unix")
elseif (APPLE)
    message(STATUS "Is Apple")
endif (WIN32)

# lib and link
add_library(Engine SHARED ${SOURCE_LIST})
target_compile_definitions(Engine PRIVATE -DSUDOU_BUILD_DLL)
target_precompile_headers(Engine PRIVATE "Engine/Source/Runtime/Core/stdafx.h")
add_executable(Editor ${SOURCE_EDITOR})
target_link_libraries(Editor Engine)