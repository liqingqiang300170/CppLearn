cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(HonorOfKingsSimulator VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 获取所有源文件
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)