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

# Include
include_directories(
    "${SRC_ROOT_PATH}"
    "${SRC_ROOT_PATH}/ThirdParty"
)

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

# Platform
if (WIN32)
    # Add lib
    set(LIBS glfw3 opengl32)
    # Glad
    add_library(GLAD 
    "${SRC_ROOT_PATH}/ThirdParty/glad/glad.c"
    )
    set(LIBS ${LIBS} GLAD)
    # Imgui
    include_directories("${SRC_ROOT_PATH}/ThirdParty/imgui")
    file(GLOB SOURCE_IMGUI
    "${SRC_ROOT_PATH}/ThirdParty/imgui/*.cpp"
    "${SRC_ROOT_PATH}/ThirdParty/imgui/*.h"
    )
    add_library(ImGui ${SOURCE_IMGUI})
    set(LIBS ${LIBS} ImGui)
    # Glm
    set(BUILD_STATIC_LIBS 1)
    add_subdirectory("${SRC_ROOT_PATH}/ThirdParty/glm")
    set(LIBS ${LIBS} glm::glm_static)
    # Add macro
    add_definitions(-DSUDOU_PLATFORM_WINDOWS -DGLFW_INCLUDE_NONE)
    # Create filters
    include(${CMAKE_SOURCE_DIR}/cmake/windows.cmake)
    assign_source_group(${SOURCE_LIST})
elseif (UNIX AND NOT APPLE)
    message(STATUS "Is Unix")
elseif (APPLE)
    message(STATUS "Is Apple")
endif (WIN32)

# Generate Engine
add_library(Engine ${SOURCE_LIST})
target_link_libraries(Engine ${LIBS})
target_compile_definitions(Engine PRIVATE -DSUDOU_BUILD_DLL)
target_precompile_headers(Engine PRIVATE "${SRC_ROOT_PATH}/Runtime/Core/stdafx.h")

# Generate Editor
add_executable(Editor ${SOURCE_EDITOR})
target_link_libraries(Editor Engine)