cmake_minimum_required(VERSION 3.8)

project(imgui VERSION 1.91.3)

if(APPLE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../../cmake")
endif()

set(IMGUI_HEADER_FILES
    imconfig.h
    imgui_internal.h
    imgui.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    backends/imgui_impl_sdl3.h
    misc/ab/imgui_fixedstring.h
    misc/cpp/imgui_stdlib.h
)

set(IMGUI_SOURCE_FILES
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp
    backends/imgui_impl_sdl3.cpp
    misc/cpp/imgui_stdlib.cpp
)

add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCE_FILES} ${IMGUI_HEADER_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PUBLIC
    ../cereal/include
    ../glm
    ../sdl/include
    ../../inc
    .
)

target_link_libraries(${PROJECT_NAME}
    ${LINK_LIBS}
)
