# ExTrans Plugin

This is the extrans plugin for kirikir2 / krkrz, updated to work with modern tp_stub.

## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## Changes from Legacy Version

1. **Build System**: Migrated from Visual Studio project files (.vcxproj, .sln, .bpr) to CMake
2. **tp_stub API**: Updated to use modern tp_stub's `STDCALL` macro instead of `_stdcall`
3. **Export Macros**: Uses the same EXPORT macro pattern as other krkrz plugins
4. **tp_stub.cpp**: Now included from modern tp_stub repository instead of legacy stub

## Files

- `Main.cpp` - Plugin entry point (V2Link/V2Unlink)
- `wave.cpp/h` - Wave transition handler
- `mosaic.cpp/h` - Mosaic transition handler
- `turn.cpp/h` - Turn transition handler
- `rotatetrans.cpp/h` - Rotate transition handler
- `ripple.cpp/h` - Ripple transition handler
- `turntrans_table.cpp/h` - Turn transition lookup tables
- `common.h` - Common utility functions
- `res.rc` - Windows resource file
