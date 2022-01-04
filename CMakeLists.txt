cmake_minimum_required (VERSION 3.1)
set (CMAKE_C_STANDARD 17)
set (CMAKE_CXX_STANDARD 17)
project (Sudou)

# Set output dir
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})
set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})

# Link lib
link_directories(${CMAKE_SOURCE_DIR}/Engine/Libs)

set(SRC_ROOT_PATH "${CMAKE_SOURCE_DIR}/Engine/Source")
set(THIRD_PARTY "${SRC_ROOT_PATH}/ThirdParty")

# Include
include_directories("${SRC_ROOT_PATH}")
include_directories("${THIRD_PARTY}")
include_directories("${THIRD_PARTY}/spdlog/include")
include_directories("${THIRD_PARTY}/glad/include")

# File
file(
    GLOB_RECURSE SOURCE_LIST 
    LIST_DIRECTORIES false
    "${SRC_ROOT_PATH}/Runtime/*.c*"
    "${SRC_ROOT_PATH}/Runtime/*.h*"
)
file(GLOB SOURCE_EDITOR
    "${SRC_ROOT_PATH}/Editor/*.cpp"
    "${SRC_ROOT_PATH}/Editor/*.h"
)

include(${CMAKE_SOURCE_DIR}/Cmake/ThirdParty.cmake)

# Generate Engine
add_library(Engine ${SOURCE_LIST})
target_link_libraries(Engine ${LIBS})
target_compile_definitions(Engine PRIVATE -DSUDOU_BUILD_DLL)
target_precompile_headers(Engine PRIVATE "${SRC_ROOT_PATH}/Runtime/Core/stdafx.h")

# Generate Editor
add_executable(Editor ${SOURCE_EDITOR})
target_link_libraries(Editor Engine)