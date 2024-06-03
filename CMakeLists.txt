CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(ShellTest)
set(CMAKE_VERBOSE_MAKEFILEON ON)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# 包含子目录
# add_subdirectory(./)

# 添加可执行文件
add_executable(ShellTest shell_test.cpp)
target_include_directories(ShellTest PRIVATE shell_test)
# target_link_libraries(ShellTest PRIVATE shell_test)
