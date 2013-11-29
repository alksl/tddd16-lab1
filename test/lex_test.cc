#include <stdio.h>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include <lex.hh>

void load_token_to_stdin(std::string token_name) {
  std::stringstream file_path;
  file_path << SOURCE_DIR;
  file_path << "/test/tokens/";
  file_path << token_name;
  file_path << ".sym";
  freopen(file_path.str().c_str(), "r", stdin);
}

TEST(Scanner, scan_integer) {
  load_token_to_stdin("integer");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(42.0, token.numberValue);
}

TEST(Scanner, scan_integer_with_exponent_downcased) {
  load_token_to_stdin("integer_with_exponent_downcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(10.0, token.numberValue);
}

TEST(Scanner, scan_integer_with_negative_exponent_downcased) {
  load_token_to_stdin("integer_with_negative_exponent_downcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(0.1, token.numberValue);
}


TEST(Scanner, scan_integer_with_exponent_upcased) {
  load_token_to_stdin("integer_with_exponent_upcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(10.0, token.numberValue);
}

TEST(Scanner, scan_integer_with_negative_exponent_upcased) {
  load_token_to_stdin("integer_with_negative_exponent_upcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(0.1, token.numberValue);
}


TEST(Scanner, scan_float) {
  load_token_to_stdin("float");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(42.5, token.numberValue);
}

TEST(Scanner, scan_float_with_exponent_downcased) {
  load_token_to_stdin("float_with_exponent_downcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(11.0, token.numberValue);
}

TEST(Scanner, scan_float_with_negative_exponent_downcased) {
  load_token_to_stdin("float_with_negative_exponent_downcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(0.2, token.numberValue);
}


TEST(Scanner, scan_float_with_exponent_upcased) {
  load_token_to_stdin("float_with_exponent_upcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(11.0, token.numberValue);
}

TEST(Scanner, scan_float_with_negative_exponent_upcased) {
  load_token_to_stdin("float_with_negative_exponent_upcased");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kNumber, token.type);
  ASSERT_EQ(0.2, token.numberValue);
}

TEST(Scanner, scan_identifier) {
  load_token_to_stdin("identifier");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kIdentifier, token.type);
  ASSERT_STREQ("identifier", token.symbolValue);
}

TEST(Scanner, scan_plus) {
  load_token_to_stdin("plus");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kPlus, token.type);
}

TEST(Scanner, scan_minus) {
  load_token_to_stdin("minus");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kMinus, token.type);
}

TEST(Scanner, scan_times) {
  load_token_to_stdin("times");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kTimes, token.type);
}

TEST(Scanner, scan_divide) {
  load_token_to_stdin("divide");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kDivide, token.type);
}

TEST(Scanner, scan_assign) {
  load_token_to_stdin("assign");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kAssign, token.type);
}

TEST(Scanner, scan_power) {
  load_token_to_stdin("power");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kPower, token.type);
}

TEST(Scanner, scan_left_paren) {
  load_token_to_stdin("left_paren");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kLeftParen, token.type);
}

TEST(Scanner, scan_right_paren) {
  load_token_to_stdin("right_paren");
  Scanner scanner;
  Token token;

  token = scanner.Scan();
  ASSERT_EQ(kRightParen, token.type);
}

