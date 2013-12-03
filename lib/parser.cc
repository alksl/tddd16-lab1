#include <parser.hh>


//
// The trace class needs a class variable. This is it
//

int Trace::indent = 0;


//
// Parse should be the entry point to your parser class. It will be
// called by the main program, which you also have to write.
//

double Parser::Parse(void)
{
    Trace       x("Parse");     // Trace execution of Parse
    double      val;            // Value of a statement

    value = -1;
    ParseStatement();

    return value;
}

void Parser::ParseStatement() {
  Token token = ScanToken();
  if(token.type == kEndMark) {
    std::cout << "End of file";
    value = 0.0;
    return;
  }

  PutBack(token);
  ParseExpression();
  double expr_val = value;
  token = ScanToken();
  if(token.type == kEndOfLine) {
    ParseStatement();
    if(value != 0.0) {
      return;
    }
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
    ParseExpressionCont();
    value = saved_value + value;
    return;
  } else if(token.type == kMinus) {
    ParseTerm();
    ParseExpressionCont();
    value = saved_value - value;
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
    ParseTermCont();
    value = saved_value * value;
    return;
  } else if(token.type == kDivide) {
    ParseFactor();
    ParseTermCont();
    value = saved_value / value;
    return;
  }

  // Matched epsilon
  PutBack(token);
}

void Parser::ParseFactor() {
  Token token = ScanToken();
  if(token.type == kNumber) {
    value =  token.numberValue;
    return;
  }

  throw ParserError("Expected number");
}

Token Parser::ScanToken() {
  if(have_bufferd_token) {
    have_bufferd_token = false;
    return bufferd_token;
  }

  Token token = scanner.Scan();
  std::cout << "Scanned token: " << token << std::endl;
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

    std::cerr << "Error recovery.\n" << std::flush;

    /* --- Your code here ---
     *
     * Error recovery routine
     *
     * Unless you come up with something better, this function should
     * scan tokens until it sees the end of line or end of file.
     * Parsing may be resumed at that point. This means that if an end
     * of line token caused the error, this routine doesn't need to do
     * anything.
     *
     * Be sure not to scan more tokens than necessary, or it won't be
     * possible to resume parsing.
     */

    /* --- End your code --- */
}

