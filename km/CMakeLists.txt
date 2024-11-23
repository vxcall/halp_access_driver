cmake_minimum_required(VERSION 3.8)
project(halp_access_km)

# Enable assembly language support
enable_language(ASM_MASM)

CPMAddPackage("gh:SergiusTheBest/FindWDK#master")
list(APPEND CMAKE_MODULE_PATH "${FindWDK_SOURCE_DIR}/cmake")
find_package(WDK REQUIRED)

set(SOURCES
        main.cpp
        get_kernel_base.asm
)

# Ensure MASM files are processed correctly
set_source_files_properties(get_kernel_base.asm PROPERTIES LANGUAGE ASM_MASM)

# Add compile definitions for assembly
set(CMAKE_ASM_MASM_FLAGS "${CMAKE_ASM_MASM_FLAGS} /Zi")

wdk_add_driver(halp_access_km ${SOURCES})

# Set specific properties for the driver target
set_target_properties(halp_access_km PROPERTIES LINKER_LANGUAGE CXX)