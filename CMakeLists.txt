cmake_minimum_required(VERSION 3.16)
project(closest_distance)
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})
include_directories({PYTHON_INCLUDE_DIRS} include)

include_directories(SYSTEM ${matplotlib_SOURCE_DIR})

add_executable(output src/main.cpp src/ClosestPairData/ClosestPairData.cpp src/Dot/Dot.cpp src/DotCollection/DotCollection.cpp src/Visualizer/visualizer.cpp)
target_link_libraries(output Python3::NumPy Python3::Python)