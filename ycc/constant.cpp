#include "constant.h"

namespace ycc
{

    Constant::Constant(ConstantKind kind, const TokenLocation &loc)
        : constantKind_(kind), tokenLocaiton_(loc)
    {}

    IntConstant::IntConstant(long l, const TokenLocation &loc)
        : constant(ConstantKind::INTEGER, TokenValue::UNRESERVED, loc),
          value_(l)
    {}

    Token IntConstant::makeToken() const
    {
        return Token(TokenType::INTEGER, TokenValue::UNRESERVED, tokenLocation_, 
                     value_, std::to_string(value_));
    }

    RealConstant::RealConstant(double d, const TokenLocation &loc)
        : constant(ConstantKind::REAL, TokenValue::UNRESERVED, loc),
          value_(d)
    {}

    Token RealCosntant::makeToken() const
    {
        return Token(TokenType::REAL, TokenValue::UNRESERVED, tokenLocation_,
                     value_, std::to_string(value_));
    }

    CharConstant::CharConstant(char c, const TokenLocation &loc)
        : constant(ConstantKind::CHAR, TokenValue::UNRESERVED, loc),
          value_(c)
    {}

    Token CharConstant::makeToken() const
    {
        return Token(TokenType::CHAR, TokenValue::UNRESERVED, tokenLocation_,
                     static_cast<long>(value_), std::to_string(value_));
    }

    BoolConstant::BoolConstant(bool b, const TokenLocation &loc)
        : constant(ConstantKind::BOOL, TokenValue::UNRESERVED, loc),
          value_(b)
    {}

    Token BooleanConstant::makeToken() const
    {
        std::string boolLiteral = value_ ? "true" : "false";
        return Token(TokenType::IDENTIFIER, TokenValue::UNRESERVED, tokenLocation_,
                     boolLiteral, std::to_string(value_));
    }

    StringConstant::StringConstant(std::string s, const TokenLocation &loc)
        : constant(ConstantKind::STRING, TokenValue::UNRESERVED, loc),
          value_(s)
    {}

    Token StringConstant::makeToken() const
    {
        return Token(TokenType::IDENTIFIER, TokenValue::UNRESERVED, tokenLocation_,
                     value_, value_);
    }

    // dump information to debug
    void IntConstant::dump() const
    {
        std::cout << "Interger Constant: " << getValue() << std::endl;
    }

    void RealConstant::dump() const
    {
        std::cout << "Real Constant: " << getValue() << std::endl;
    }

    void CharConstant::dump() const
    {
        std::cout << "Char Constant: " << getValue() << std::endl;
    }

    void BoolConstant::dump() const
    {
        std::cout << "Bool Constant: " << getValue() << std::endl;
    }

    void StringConstant::dump() const
    {
        std::cout << "String Constant: " << getValue() << std::endl;
    }

}

