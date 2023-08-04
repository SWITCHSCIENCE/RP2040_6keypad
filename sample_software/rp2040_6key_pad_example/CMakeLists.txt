cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(rp2040_6key_pad_example_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(rp2040_6key_pad_example
  main.c
)
pico_enable_stdio_usb(rp2040_6key_pad_example 1)
pico_enable_stdio_uart(rp2040_6key_pad_example 0)
pico_add_extra_outputs(rp2040_6key_pad_example)
target_link_libraries(rp2040_6key_pad_example pico_stdlib)