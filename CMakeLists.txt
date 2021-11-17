cmake_minimum_required (VERSION 3.1)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)
project (Sudou)
include_directories("${PROJECT_SOURCE_DIR}/Engine/Source")

if (WIN32)
    message(STATUS "Is windows")
elseif (UNIX AND NOT APPLE)
    message(STATUS "Is Unix")
elseif (APPLE)
    message(STATUS "Is Apple")
endif (WIN32)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})
set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})

add_subdirectory(Engine/Source)