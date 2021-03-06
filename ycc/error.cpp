#include <iostream>
#include "error.h"
#include "parser.h"

namespace ycc
{
    void errorToken(const std::string &msg)
    {
        std::cerr << "Token Error: " << msg << std::endl;
        Scanner::setErrorFlag(true);
    }

    void errorSyntax(const std::string &msg)
    {
        std::cerr << "Syntax Error: " << msg << std::endl;
        Parser::setErrorFlag(true);
    }

}

