cmake_minimum_required(VERSION 3.5)

set(WORLD_SRC src/cheaptrick.cpp
              src/codec.cpp
              src/common.cpp
              src/d4c.cpp
              src/dio.cpp
              src/fft.cpp
              src/harvest.cpp
              src/matlabfunctions.cpp
              src/stonemask.cpp
              src/synthesis.cpp
              src/synthesisrealtime.cpp
              )

# Target for libworld
# add_library(fftw3 STATIC IMPORTED lib/native/libfftw3.a)
add_library(world STATIC ${WORLD_SRC})
target_include_directories(world PUBLIC ${PROJECT_SOURCE_DIR}/include)
if(ANDROID)
message(STATUS "ARCH: ${CMAKE_ANDROID_ARCH_ABI}")
target_link_libraries(world ${PROJECT_SOURCE_DIR}/lib/${CMAKE_ANDROID_ARCH_ABI}/libfftw3.a)
else()
target_link_libraries(world ${PROJECT_SOURCE_DIR}/lib/native/libfftw3.a)
endif()

set(TOOLS_SRC tools/audioio.cpp
              tools/parameterio.cpp)
add_library(world_tools STATIC ${TOOLS_SRC})

# Target for analysis/synthesis

add_executable(synthesis examples/analysis_synthesis/synthesis.cpp)
target_include_directories(synthesis PUBLIC ${PROJECT_SOURCE_DIR}/tools
                                     PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(synthesis world world_tools)

add_executable(analysis examples/analysis_synthesis/analysis.cpp)
target_include_directories(analysis PUBLIC ${PROJECT_SOURCE_DIR}/tools
                                    PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(analysis world world_tools)
