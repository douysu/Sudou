if (WIN32)
    add_definitions(-DSUDOU_PLATFORM_WINDOWS)
endif (WIN32)

add_executable(Sandbox src/SandboxApp.cpp)
target_link_libraries(Sandbox Sudou)