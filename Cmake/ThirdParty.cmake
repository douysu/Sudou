find_library(glfw_library glfw3 PATHS "${THIRD_PARTY}/GLFW")

if (WIN32)
    add_subdirectory("${THIRD_PARTY}/glad/include")
    add_subdirectory("${THIRD_PARTY}/spdlog")
    add_subdirectory("${THIRD_PARTY}/imgui")
    set(BUILD_STATIC_LIBS 1)
    add_subdirectory("${THIRD_PARTY}/glm")
    set(LIBS opengl32 GLAD ImGui glm_static spdlog ${glfw_library})
    include(${CMAKE_SOURCE_DIR}/Cmake/ConfigIDEDirectory.cmake)
elseif (UNIX AND NOT APPLE)
    message(STATUS "Is Unix")
elseif (APPLE)
    message(STATUS "Is Apple")
endif (WIN32)