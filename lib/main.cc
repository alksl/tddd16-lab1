#include <iostream>
#include <stdlib.h>

#include <parser.hh>

int main(void)
{
    Parser parser;
    double val;

    while (1)
    {
        try
        {
            std::cout << "Expression: " << std::flush;
            val = parser.Parse();
            std::cout << "Result:     " << val << '\n' << std::flush;
        }
        catch (ScannerError& e)
        {
            std::cerr << e << '\n' << std::flush;
            parser.Recover();
        }
        catch (ParserError)
        {
            parser.Recover();
        }
        catch (ParserEndOfFile)
        {
            std::cerr << "End of file\n" << std::flush;
            exit(0);
        }
    }
}
