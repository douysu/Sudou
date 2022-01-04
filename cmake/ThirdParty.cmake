# Platform
if (WIN32)
     # Add lib
    set(LIBS glfw3 opengl32)
    # Glad
    add_library(GLAD 
    "${SRC_ROOT_PATH}/ThirdParty/glad/include/glad/glad.c"
    )
    set(LIBS ${LIBS} GLAD)
    # Imgui
    include_directories("${THIRD_PARTY}/imgui")
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
    include(${CMAKE_SOURCE_DIR}/Cmake/Windows.cmake)
    assign_source_group(${SOURCE_LIST})
elseif (UNIX AND NOT APPLE)
    message(STATUS "Is Unix")
elseif (APPLE)
    message(STATUS "Is Apple")
endif (WIN32)