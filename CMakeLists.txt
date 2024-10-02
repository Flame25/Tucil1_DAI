# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project name and version
project(MyProject VERSION 1.0)

# Find OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Threads REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)


# Add source files
add_executable(cube src/main.cpp src/open_gl_utils.cpp src/steep_ascent.cpp src/cube.cpp src/side_ways.cpp src/random_restart.cpp)
#target_include_directories(cube PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cube ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} Threads::Threads)
# Optionally, link any necessary libraries (if needed)
# target_link_libraries(MyProject <library_name>)

