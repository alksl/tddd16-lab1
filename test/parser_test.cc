#include <stdio.h>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include <parser.hh>

#define ABS_ERROR 0.005

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
  ASSERT_THROW(parser.Parse(), ParserEndOfFile);
}

TEST(Parser, parse_incorrect_line_and_recover) {
  load_expr_to_stdin("incorrect_program");
  Parser parser;
  ASSERT_THROW(parser.Parse(), ParserError);

  parser.Recover();
  ASSERT_EQ(2.0, parser.Parse());
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

TEST(Parser, subtraction_left_associativity) {
  load_expr_to_stdin("subtraction_left_associativity");
  Parser parser;
  ASSERT_EQ(-4.0, parser.Parse());
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

TEST(Parser, division_left_associativity) {
  load_expr_to_stdin("division_left_associativity");
  Parser parser;
  ASSERT_NEAR(0.666, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_exponentiation) {
  load_expr_to_stdin("exponentiation");
  Parser parser;
  ASSERT_EQ(8.0, parser.Parse());
}

TEST(Parser, exponetiation_right_associativity) {
  load_expr_to_stdin("exponentiation_right_associativity");
  Parser parser;
  ASSERT_EQ(32.0, parser.Parse());
}

TEST(Parser, parse_negation) {
  load_expr_to_stdin("negation");
  Parser parser;
  ASSERT_EQ(-2.0, parser.Parse());
}

TEST(Parser, parse_parenthesised_expression) {
  load_expr_to_stdin("parenthesised_expression");
  Parser parser;
  ASSERT_EQ(4.0, parser.Parse());
}

TEST(Parser, parse_pi) {
  load_expr_to_stdin("pi");
  Parser parser;
  ASSERT_EQ(3.14159265,parser.Parse());
}

TEST(Parser, parse_e) {
  load_expr_to_stdin("e");
  Parser parser;
  ASSERT_EQ(2.71828183, parser.Parse());
}

TEST(Parser, parse_ln) {
  load_expr_to_stdin("ln");
  Parser parser;
  ASSERT_NEAR(1.0, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_log) {
  load_expr_to_stdin("log");
  Parser parser;
  ASSERT_NEAR(1.0, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_exp) {
  load_expr_to_stdin("exp");
  Parser parser;
  ASSERT_NEAR(7.389, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_sin) {
  load_expr_to_stdin("sin");
  Parser parser;
  ASSERT_NEAR(1.0, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_cos) {
  load_expr_to_stdin("cos");
  Parser parser;
  ASSERT_NEAR(1.0, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_tan) {
  load_expr_to_stdin("tan");
  Parser parser;
  ASSERT_NEAR(1.0, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_arcsin) {
  load_expr_to_stdin("arcsin");
  Parser parser;
  ASSERT_NEAR(0.523599, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_arcos) {
  load_expr_to_stdin("arccos");
  Parser parser;
  ASSERT_NEAR(1.04720, parser.Parse(), ABS_ERROR);
}

TEST(Parser, parse_arctan) {
  load_expr_to_stdin("arctan");
  Parser parser;
  ASSERT_NEAR(0.785398, parser.Parse(), ABS_ERROR);
}
