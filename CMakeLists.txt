cmake_minimum_required(VERSION 3.5)

# Use pico-sdk in vendor
set(PICO_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/vendor/pico-sdk)
set(PICO_BOARD pico_w)

# Use pimoroni-pico in vendor
set(PIMORONI_PICO_PATH ${CMAKE_CURRENT_LIST_DIR}/vendor/pimoroni-pico)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Pull in pimoroni-pico (must be before project)
include(pimoroni_pico_import.cmake)

project(rave_toy C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()

add_executable(rave_toy
        src/rave_toy.cpp
        vendor/dhcpserver/dhcpserver.c
        vendor/dnsserver/dnsserver.c
        src/config.hpp
        src/lib/dhcpserver.hpp
        src/lib/dnsserver.hpp
        src/util/http.hpp
)
target_include_directories(rave_toy PRIVATE
        .
        vendor/dhcpserver
        vendor/dnsserver
)
target_link_libraries(rave_toy
        pico_cyw43_arch_lwip_poll
        pico_stdlib
)

# Generate UF2
pico_add_extra_outputs(rave_toy)
