cmake_minimum_required(VERSION 3.22)

project(sm64ds_android C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SM64DS_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../src/*.cpp"
)

file(GLOB_RECURSE PORT_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../port/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../port/*.cpp"
)

add_library(sm64ds SHARED
    ${SM64DS_SOURCES}
    ${PORT_SOURCES}
)

target_compile_definitions(sm64ds PRIVATE
    PLATFORM_ANDROID=1
)

target_compile_options(sm64ds PRIVATE
    -fno-strict-aliasing
)

target_link_libraries(sm64ds
    android
    log
)
