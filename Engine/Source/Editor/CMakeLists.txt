if (WIN32)
    add_definitions(-DSUDOU_PLATFORM_WINDOWS)
endif (WIN32)

add_executable(Editor SandboxApp.cpp)
target_link_libraries(Editor Engine)