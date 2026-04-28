set(TPSTUB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../tp_stub CACHE PATH "Path to tp_stub directory")
include(${TPSTUB_DIR}/krkrz.cmake)

# Build the main extrans plugin
krkrz_plugin(extrans
    SOURCES
        Main.cpp
        mosaic.cpp
        ripple.cpp
        rotatebase.cpp
        rotatetrans.cpp
        turn.cpp
        turntrans_table.cpp
        wave.cpp
        $<$<CXX_COMPILER_ID:MSVC>:res.rc>
    DEFINITIONS
        TVP_CPU_HAS_SSE2=0x00800000
        TVP_CPU_HAS_MMX=1
        TVP_CPU_HAS_EMMX=2
)

# Output DLL to build/presetname/Release/ instead of build/presetname/extrans/Release/
if(CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
    target_compile_options(extrans PRIVATE /utf-8)
endif()
# Define __GENERIC__ for non-Windows builds (required by tp_stub.h to skip IStream blocks)
if(NOT CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
    target_compile_definitions(extrans PRIVATE __GENERIC__)
endif()
set_target_properties(extrans PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
)


