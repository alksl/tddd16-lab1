#include <math.h>
#include <parser.hh>

double Parser::Parse(void)
{
    value = 0.0;
    ParseStatement();

    return value;
}

void Parser::ParseStatement() {
  Token token = ScanToken();
  if(token.type == kEndMark) {
    throw ParserEndOfFile();
    return;
  }

  PutBack(token);
  ParseExpression();
  double expr_val = value;
  token = ScanToken();
  if(token.type == kEndOfLine) {
    value = expr_val;
    return;
  }

  throw ParserError("Expected end of line after expression");
}

void Parser::ParseExpression() {
  ParseTerm();
  ParseExpressionCont();
}

void Parser::ParseExpressionCont() {
  Token token = ScanToken();
  double saved_value = value;

  if(token.type == kPlus) {
    ParseTerm();
    value = saved_value + value;
    ParseExpressionCont();
    return;
  } else if(token.type == kMinus) {
    ParseTerm();
    value = saved_value - value;
    ParseExpressionCont();
    return;
  }

  // Matched epsilon
  PutBack(token);
}

void Parser::ParseTerm() {
  ParseFactor();
  ParseTermCont();
}

void Parser::ParseTermCont() {
  Token token = ScanToken();
  double saved_value = value;

  if(token.type == kTimes) {
    ParseFactor();
    value = saved_value * value;
    ParseTermCont();
    return;
  } else if(token.type == kDivide) {
    ParseFactor();
    value = saved_value / value;
    ParseTermCont();
    return;
  }

  // Matched epsilon
  PutBack(token);
}

void Parser::ParseFactor() {
  ParseBase();

  Token token = ScanToken();
  if(token.type == kPower) {
    double base = value;
    ParseExpression();
    value = pow(base, value);
    return;
  }

  // Only Base was matched
  PutBack(token);
}

void Parser::ParseBase() {
  Token token = ScanToken();
  if(token.type == kMinus) {
    ParseExpression();
    value = -1*value;
    return;
  } else if(token.type == kLeftParen) {
    ParseExpression();
    AssertRightParen();
    return;
  } else if(token.type == kIdentifier) {
    ParseIdentifier(token.symbolValue);
    return;
  }else if(token.type == kNumber) {
    value =  token.numberValue;
    return;
  }

  throw ParserError("Expected number");
}

void Parser::ParseIdentifier(std::string identifier) {
  Token token = ScanToken();

  if(token.type == kLeftParen) {
    ParseExpression();
    AssertRightParen();
    value = DoFunctionCall(identifier, value);
    return;
  }

  // Match epsilon
  value = LookupIdentifier(identifier);
  PutBack(token);
}

double Parser::LookupIdentifier(std::string identifier) {
  if(identifier == "pi") {
    return 3.14159265;
  } else if(identifier == "e") {
    return 2.71828183;
  }

  throw ParserError("LookupIdentifier could not match identifier");
}

double Parser::DoFunctionCall(std::string identifier, double arg) {
  if(identifier == "log") {
    return log10(arg);
  }

  if(identifier == "ln") {
    return log(arg);
  }

  if(identifier == "exp") {
    return exp(arg);
  }

  if(identifier == "sin") {
    return sin(arg);
  }

  if(identifier == "cos") {
    return cos(arg);
  }

  if(identifier == "tan") {
    return tan(arg);
  }

  if(identifier == "arcsin") {
    return asin(arg);
  }

  if(identifier == "arccos") {
    return acos(arg);
  }

  if(identifier == "arctan") {
    return atan(arg);
  }

  throw ParserError("DoFunctionCall could not match identfier");
}

void Parser::AssertRightParen() {
  Token r_paren = ScanToken();
  if(r_paren.type != kRightParen) {
    throw ParserError("Expectet RightParen");
  }
}


Token Parser::ScanToken() {
  if(have_bufferd_token) {
    have_bufferd_token = false;
    return bufferd_token;
  }

  Token token = scanner.Scan();
  return token;
}

void Parser::PutBack(Token token) {
  if(have_bufferd_token) {
    throw ParserError("Trying to buffer multiple tokens");
  }

  bufferd_token = token;
  have_bufferd_token = true;
}


void Parser::Recover(void)
{
  Token token;
  do {
    token = ScanToken();
  } while( token.type != kEndOfLine);
}

