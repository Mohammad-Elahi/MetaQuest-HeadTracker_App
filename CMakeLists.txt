cmake_minimum_required(VERSION 3.10)
project(MetaApp)

set(CMAKE_CXX_STANDARD 14)
            
# Specify the relative path to the provided LibOVR installation
set(LIBOVR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/LibOVR)

include_directories(${LIBOVR_PATH}/Include)
link_directories(${LIBOVR_PATH}/Lib/Windows/x64/Release/VS2017)

add_executable(MetaApp main.cpp)
target_link_libraries(MetaApp LibOVR)