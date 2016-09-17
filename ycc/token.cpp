#include "token.h"

namespace ycc
{
    
    TokenLocation::TokenLocation(const std::string &fileName, int line, int column)
        : fileName_(fileName), line_(line), column_(column)
    {}

    TokenLocation::TokenLocation() : fileName_(""), line_(1), column_(0)
    {}

    std::string TokenLocation::toString() const
    {
        return fileName_ + ":" + std::to_string(line_) + ":" + std::to_string(column_) + ":";
    }

    // End TokenLocation

    
    Token::Token() : type_(TokenType::UNKNOWN), value_(TokenValue::UNRESERVED),
        location_(std::string(""), 0, 0), name_("")
    {}

    Token::Token(TokenType type, TokenValue value, const TokenLocation &location,
                std::string name)
        : type_(type), value_(value), location_(location), name_(name)
    {}

    Token::Token(TokenType type, TokenValue value, const TokenLocation &location,
                const std::string &strValue, std::string name)
        : type_(type), value_(value), location_(location), name_(name),
          strValue_(strValue)
    {}

    Token::Token(TokenType type, TokenValue value, const TokenLocation &location,
                long intValue, std::string name)
        : type_(type), value_(value), location_(location), name_(name),
          intValue_(intValue)
    {}

    Token::Token(TokenType type, TokenValue value, const TokenLocation &location,
                double realValue, std::string name)
        : type_(type), value_(value), location_(location), name_(name),
          realValue_(realValue)
    {}

    std::string Token::tokenTypeDescription() const
    {
        std::string buffer;

        switch(type_)
        {
            // return the description of the type
            default:
                break;
        }

        return buffer;
    }

    std::string Token::toString() const
    {
        return std::string("Token Type: " + tokenTypeDescription() + "Token Name: " + name_);
    }

    void Token::dump(std::ostream out /* = std::cout */) const
    {
        out << location_.toString() << "\t" << tokenTypeDescription()
            << "\t" << name_ << "\t\t" << std::endl;
    }

    // End Token
}
