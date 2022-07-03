cmake_minimum_required(VERSION 3.23.2)
project(CppProject)

# Auto generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# Version 23 doens't work
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/Main.cpp src/Renderer.cpp src/Task.cpp src/Util.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

