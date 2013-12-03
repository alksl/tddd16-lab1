#include <stdio.h>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include <parser.hh>

void load_expr_to_stdin(std::string expression) {
  std::stringstream file_path;
  file_path << SOURCE_DIR;
  file_path << "/test/expressions/";
  file_path << expression;
  file_path << ".expr";
  freopen(file_path.str().c_str(), "r", stdin);
}

TEST(Parser, parse_empty_program) {
  load_expr_to_stdin("empty_program");
  Parser parser;
  ASSERT_EQ(0.0, parser.Parse());
}

TEST(Parser, parse_addition) {
  load_expr_to_stdin("addition");
  Parser parser;
  ASSERT_EQ(3.0, parser.Parse());
}

TEST(Parser, parse_subtraction) {
  load_expr_to_stdin("subtraction");
  Parser parser;
  ASSERT_EQ(1.0, parser.Parse());
}

TEST(Parser, parse_multiplication) {
  load_expr_to_stdin("multiplication");
  Parser parser;
  ASSERT_EQ(6.0, parser.Parse());
}

TEST(Parser, parse_division) {
  load_expr_to_stdin("division");
  Parser parser;
  ASSERT_EQ(0.5, parser.Parse());
}

TEST(Parser, parse_exponentiation) {
  load_expr_to_stdin("exponentiation");
  Parser parser;
  ASSERT_EQ(8.0, parser.Parse());
}
