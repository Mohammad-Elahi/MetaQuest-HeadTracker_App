cmake_minimum_required(VERSION 3.10)
project(MetaApp)

set(CMAKE_CXX_STANDARD 14)

# Specify the path to your LibOVR installation
set(LIBOVR_PATH C:/Users/mohammad.elahi/Desktop/MetaApp/LibOVR)

include_directories(${LIBOVR_PATH}/Include)
link_directories(${LIBOVR_PATH}/Lib/Windows/x64/Release/VS2017)

add_executable(MetaApp main.cpp)

target_link_libraries(MetaApp LibOVR)