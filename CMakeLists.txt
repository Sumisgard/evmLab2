cmake_minimum_required(VERSION 3.10)

project(lab2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

set(MY_SOURCES 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/matrix.cpp
)

add_executable(${PROJECT_NAME}
    ${MY_SOURCES}
)

# include_directories(${OpenCV_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src/include)
