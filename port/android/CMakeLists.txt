cmake_minimum_required(VERSION 3.22)
project(sm64ds_smoke_android C CXX)

function(port_read_lines path outvar)
    file(STRINGS "${path}" _lines)
    set(${outvar} "${_lines}" PARENT_SCOPE)
endfunction()

# slice_gate1.txt lives in port/, one level up from here, and its own
# paths are relative to the repo root, two levels up from here.
port_read_lines("${CMAKE_CURRENT_SOURCE_DIR}/../slice_gate1.txt" SLICE_LINES)
set(SLICE_SOURCES "")
foreach(line IN LISTS SLICE_LINES)
    string(STRIP "${line}" line)
    if(line MATCHES "^#" OR line STREQUAL "")
        continue()
    endif()
    list(APPEND SLICE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../../${line}")
endforeach()

add_executable(smoke
    ../tests/smoke.cpp
    ../hal/cstd_div.c
    ../hal/os_time.cpp
    ../hal/shims.cpp
    ${SLICE_SOURCES})

target_include_directories(smoke PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    "${CMAKE_CURRENT_SOURCE_DIR}/../hal"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../..")
