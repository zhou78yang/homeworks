#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <cassert>

namespace ycc
{
    extern void errorToken(const std::string &msg);
    extern void errorSyntax(const std::string &msg);
}

#endif // error.h
