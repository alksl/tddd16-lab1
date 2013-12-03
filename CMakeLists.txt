cmake_minimum_required(VERSION 2.6)
project(tddd16-lab1)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11 -stdlib=libc++")
add_subdirectory(googletest)
enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(lex_test
  lib/lex.cc
  test/lex_test.cc
)
set_target_properties(lex_test PROPERTIES COMPILE_DEFINITIONS "SOURCE_DIR=\"${CMAKE_SOURCE_DIR}\"")
target_link_libraries(lex_test ${CORELIBS} gtest gtest_main)

add_executable(parser_test
  test/parser_test.cc
  lib/parser.cc
  lib/lex.cc
)
set_target_properties(parser_test PROPERTIES COMPILE_DEFINITIONS "SOURCE_DIR=\"${CMAKE_SOURCE_DIR}\"")
target_link_libraries(parser_test ${CORELIBS} gtest gtest_main)
