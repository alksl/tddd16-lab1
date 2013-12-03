//
// parser.hh
//
// Skeleton header file for your parser class. You will probably need more
// methods and instance variables in the parser class.
//


#ifndef KOMP_LABONE_H
#define KOMP_LABONE_H

#include <iostream>
#include <lex.hh>


class Parser
{
public:
    void Recover(void);         // Error recovery routine
    double Parse(void);         // Main entry point
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

class ParserError {};
class ParserEndOfFile {};

#endif
