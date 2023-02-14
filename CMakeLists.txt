cmake_minimum_required(VERSION 3.8)

project(imgui VERSION 1.87)

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
    backends/imgui_impl_sdl2.h
    misc/ab/imgui_fixedstring.h
    misc/cpp/imgui_stdlib.h
)

set(IMGUI_SOURCE_FILES
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp
    backends/imgui_impl_sdl2.cpp
    misc/cpp/imgui_stdlib.cpp
)

add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCE_FILES} ${IMGUI_HEADER_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

if(CMAKE_SYSTEM_NAME MATCHES "iOS")
    list(APPEND LINK_LIBS
        "${PROJECT_SOURCE_DIR}/../sdl/lib/ios/libSDL2.a")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    list(APPEND LINK_LIBS
        "${PROJECT_SOURCE_DIR}/../sdl/lib/macos/libSDL2.a")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    list(APPEND LINK_LIBS
        "${PROJECT_SOURCE_DIR}/../sdl/lib/win64/SDL2.lib")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    list(APPEND LINK_LIBS "${PROJECT_SOURCE_DIR}/../sdl/lib/linux/libSDL2.a")
else()
    message(FATAL_ERROR "Platform ${CMAKE_SYSTEM_NAME} not supported!")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDE_DIRS}
    ../cereal/include
    ../glm
    ../sdl/include/sdl2
    ../../inc
    .
)

target_link_libraries(${PROJECT_NAME}
    ${LINK_LIBS}
)

