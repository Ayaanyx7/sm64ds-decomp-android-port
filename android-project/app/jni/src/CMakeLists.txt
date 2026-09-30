cmake_minimum_required(VERSION 3.22)

project(sm64ds_android C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

add_library(sm64ds SHARED)

target_sources(sm64ds PRIVATE

    # Android entry point
    android-project/app/src/main/cpp/main.cpp

    # Port layer
    # Add the actual files from port/ here

    # Game source
    # Add the game TUs that the PC port actually links

    # Third-party
    # Add stb implementation files actually required
)

target_include_directories(sm64ds PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/port
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)

target_compile_definitions(sm64ds PRIVATE
    PLATFORM_ANDROID=1
)

target_link_libraries(sm64ds
    android
    log
)
