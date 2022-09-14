file(GLOB SOURCE_IMGUI
    "${THIRD_PARTY}/imgui/*.cpp"
    "${THIRD_PARTY}/imgui/*.h"
)
add_library(ImGui ${SOURCE_IMGUI})
