cmake_minimum_required(VERSION 3.14)
project(PR2_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../PR2_1/lib/googletest)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(PR2_1
        Source.cpp
        classes/IntRange.cpp
)

target_link_libraries(PR2_1)

add_executable(PR2_1_tests
        classes/IntRange.cpp
        tests/tests.cpp
)

target_link_libraries(PR2_1_tests gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PR2_1_tests)
