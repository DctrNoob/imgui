cmake_minimum_required(VERSION 3.8)

project(imgui VERSION 1.84.2)

if(NOT WIN32)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../../cmake")
endif()

set(IMGUI_HEADER_FILES
    imconfig.h
    imgui_internal.h
    imgui.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    backends/imgui_impl_opengl3_loader.h
    backends/imgui_impl_opengl3.h
    backends/imgui_impl_sdl.h
    misc/ab/imgui_ablabel.h
    misc/cpp/imgui_stdlib.h
    misc/freetype/imgui_freetype.h
)

set(IMGUI_SOURCE_FILES
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp
    backends/imgui_impl_opengl3.cpp
    backends/imgui_impl_sdl.cpp
    misc/ab/imgui_ablabel.cpp
    misc/cpp/imgui_stdlib.cpp
    misc/freetype/imgui_freetype.cpp
)

add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCE_FILES} ${IMGUI_HEADER_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

set(INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/../sdl/include/sdl2")

if(PLATFORM STREQUAL "OS64") # iOS
    list(APPEND LINK_LIBS "${PROJECT_SOURCE_DIR}/../../lib/ios/sdl2/libSDL2-ios.a")
elseif(PLATFORM STREQUAL "SIMULATOR64") # iOS Simulator
    list(APPEND LINK_LIBS "${PROJECT_SOURCE_DIR}/../../lib/ios/sdl2/libSDL2-ios-sim.a")
elseif(PLATFORM STREQUAL "MAC") # macOS
    list(APPEND INCLUDE_DIRS ${SDL2_INCLUDE_DIR} "../gl3w/include")
    list(APPEND LINK_LIBS ${SDL2_LIBRARY}
        "${PROJECT_SOURCE_DIR}/../../lib/macos/sdl2/libSDL2.a"
        "gl3w")
elseif(WIN32) # Windows
    list(APPEND INCLUDE_DIRS "../gl3w/include")
    list(APPEND LINK_LIBS
        "${PROJECT_SOURCE_DIR}/../../lib/win64/sdl2/SDL2.lib"
        "gl3w")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDE_DIRS}
    #../angle/include
    ../cereal/include
    ../freetype/include
    ../glm
    ../../inc
    .
)
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})
