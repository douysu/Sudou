#
# Copyright(c) 2021 Yin Dou.
#
cmake_minimum_required (VERSION 3.1)
set (CMAKE_C_STANDARD 17)
set (CMAKE_CXX_STANDARD 17)
project (Sudou)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})
set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})

set(SRC_ROOT_PATH "${CMAKE_SOURCE_DIR}/Engine/Source")
set(THIRD_PARTY "${SRC_ROOT_PATH}/ThirdParty")

include_directories("${SRC_ROOT_PATH}")
include_directories("${THIRD_PARTY}")
include_directories("${THIRD_PARTY}/spdlog/include")
include_directories("${THIRD_PARTY}/glad/include")
include_directories("${THIRD_PARTY}/imgui")

include(${CMAKE_SOURCE_DIR}/Cmake/ThirdParty.cmake)

add_library(Engine ${SOURCE_LIST})
target_link_libraries(Engine ${LIBS})
target_compile_definitions(Engine PRIVATE -DSUDOU_BUILD_DLL)
target_precompile_headers(Engine PRIVATE "${SRC_ROOT_PATH}/Runtime/Core/stdafx.h")

add_executable(Editor ${SOURCE_EDITOR})
target_link_libraries(Editor Engine)