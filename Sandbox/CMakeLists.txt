add_definitions(-DSUDOU_PLATFORM_WINDOWS)
add_executable(Sandbox src/SandboxAPP.cpp)
target_link_libraries(Sandbox Sudou)