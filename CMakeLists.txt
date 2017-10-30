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
add_library(world SHARED ${WORLD_SRC})
target_include_directories(world PUBLIC ${PROJECT_SOURCE_DIR}/src)

set(TOOLS_SRC tools/audioio.cpp
              tools/parameterio.cpp)
add_library(world_tools OBJECT ${TOOLS_SRC})

# Target for synthesis
add_executable(synthesis examples/analysis_synthesis/synthesis.cpp)
target_include_directories(synthesis PUBLIC ${PROJECT_SOURCE_DIR}/tools
                                     PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(synthesis world $<TARGET_OBJECTS:world_tools>)
