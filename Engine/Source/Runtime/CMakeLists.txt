if (WIN32)
    add_definitions(-DSUDOU_PLATFORM_WINDOWS -DSUDOU_BUILD_DLL)
endif(WIN32)

add_library(Engine SHARED
Application.cpp
)