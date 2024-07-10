cmake_minimum_required(VERSION 3.14)
project(clox)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Use gtest version 1.14.0
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  clox
  main.cc
)
target_link_libraries(
  clox
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(clox)
