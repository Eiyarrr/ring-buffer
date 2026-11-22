cmake_minimum_required(VERSION 3.13)

project(ring_buffer C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(ring_buffer
    src/ring_buffer.c
)

target_include_directories(ring_buffer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test_ring_buffer
    tests/test_ring_buffer.c
)

target_link_libraries(test_ring_buffer PRIVATE
    ring_buffer
)
