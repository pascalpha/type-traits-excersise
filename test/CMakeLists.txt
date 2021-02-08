cmake_minimum_required(VERSION 3.10)
enable_testing()

find_package(GTest REQUIRED)

add_executable(test-fundamental test-fundamental.cc)
target_link_libraries(test-fundamental moscow GTest::GTest GTest::Main)
add_test(test-fundamental test-fundamental)

