cmake_minimum_required(VERSION 3.0)
project(world)

set(WORLD_SRC
        src/cheaptrick.cpp
        src/codec.cpp
        src/common.cpp
        src/d4c.cpp
        src/dio.cpp
        src/harvest.cpp
        src/matlabfunctions.cpp
        src/stonemask.cpp
        src/synthesis.cpp
        src/synthesisrealtime.cpp)

include_directories(include)

add_library(world STATIC ${WORLD_SRC})
target_link_libraries(world lib/${ANDROID_ABI}/libfftw3f.a)

install(TARGETS world ARCHIVE DESTINATION lib/${ANDROID_ABI})
