function(AssignSourceGroup)
    foreach(SOURCE IN ITEMS ${ARGN})
    get_filename_component(SOURCE_PATH "${SOURCE}" PATH)
    file(RELATIVE_PATH SOURCE_PATH_REL "${SRC_ROOT_PATH}" "${SOURCE_PATH}")
    string(REPLACE "/" "\\" GROUP_PATH "${SOURCE_PATH_REL}")
    source_group("${GROUP_PATH}" FILES "${SOURCE}")
endforeach()
endfunction(AssignSourceGroup)

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

AssignSourceGroup(${SOURCE_LIST})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("debug mode")
elseif (CMAKE_BUILD_TYPE EQUAL "Release")
    message("release mode")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")