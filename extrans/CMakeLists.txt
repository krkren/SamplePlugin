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
        res.rc
    DEFINITIONS
        TVP_CPU_HAS_SSE2=0x00800000
        TVP_CPU_HAS_MMX=1
        TVP_CPU_HAS_EMMX=2
)
