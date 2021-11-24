cmake_minimum_required (VERSION 3.1)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)
project (Sudou)

include_directories(
    "${PROJECT_SOURCE_DIR}/Engine/Source"
    "${PROJECT_SOURCE_DIR}/Engine/Source/ThirdParty"
    "${PROJECT_SOURCE_DIR}/Engine/Source/ThirdParty/spdlog/include"
)

if (WIN32)
    add_definitions(-DSUDOU_PLATFORM_WINDOWS)
elseif (UNIX AND NOT APPLE)
    message(STATUS "Is Unix")
elseif (APPLE)
    message(STATUS "Is Apple")
endif (WIN32)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})
set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/Engine/Binaries/${CMAKE_VS_PLATFORM_NAME})

file(GLOB SOURCE_RUNTIME
    "Engine/Source/Runtime/*.cpp"
    "Engine/Source/Runtime/*.h"
    "Engine/Source/Runtime/Events/*.h"
    "Engine/Source/Runtime/Events/*.cpp"
)

file(GLOB SOURCE_EDITOR
    "Engine/Source/Editor/*.cpp"
    "Engine/Source/Editor/*.h"
)

add_library(Engine SHARED  ${SOURCE_RUNTIME})
target_compile_definitions(Engine PRIVATE -DSUDOU_BUILD_DLL)

add_executable(Editor ${SOURCE_EDITOR})

target_link_libraries(Editor Engine)