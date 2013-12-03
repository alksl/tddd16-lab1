//
// parser.hh
//
// Skeleton header file for your parser class. You will probably need more
// methods and instance variables in the parser class.
//


#ifndef KOMP_LABONE_H
#define KOMP_LABONE_H

#include <iostream>
#include <stdexcept>
#include <lex.hh>

class Parser
{
public:
    void Recover(void);         // Error recovery routine
    double Parse(void);         // Main entry point
private:
    void ParseStatement();
    void ParseExpression();
    void ParseExpressionCont();
    void ParseTerm();
    void ParseTermCont();
    void ParseFactor();
    void ParseBase();
    void ParseIdentifier(std::string identifier);

    double LookupIdentifier(std::string identifier);
    double DoFunctionCall(std::string identifier, double arg);

    void AssertRightParen();

    Token ScanToken();
    void PutBack(Token token);

    Scanner scanner;
    double value;
    bool have_bufferd_token = false;
    Token bufferd_token;
};

class Trace
{
    static int indent;
    char *name;

public:
    Trace(char *s)
    {
        name = s;
        std::cerr.width(indent);
        std::cerr << " ";
        std::cerr << "--> " << name << '\n' << std::flush;
        indent += 4;
    };

    ~Trace()
    {
        indent -= 4;
        std::cerr.width(indent);
        std::cerr << "";
        std::cerr << "<-- " << name << '\n' << std::flush;
    };
};

//
// Two error classes that you may find useful. You can thrown
// ParserError to signal an error in parsing and ParserEndOfFile to
// signal an end of file. There are other alternatives to error
// reporting that may be more convenient.
//

class ParserError : public std::runtime_error{
public:
  ParserError(const std::string what) : std::runtime_error(what) { }
};

class ParserEndOfFile {};

#endif
