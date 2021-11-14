add_definitions(-DSUDOU_PLATFORM_WINDOWS)
add_executable(Sandbox src/SandboxApp.cpp)
target_link_libraries(Sandbox Sudou)