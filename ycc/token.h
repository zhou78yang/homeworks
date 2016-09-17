#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <iostream>
#include <tuple>
#include <map>
#include <cassert>

namespace ycc
{
    enum class TokenType
    {
        // see C standard

        // separate the type constant to
        // 5 parts to make it clearer
        INTEGER,            // such as 1, 2 and so on
        REAL,               // such as 3.14
        BOOLEAN,            // true or false
        CHAR,               // such as 'a', 'b'
        STRING,             // such as "hello world"

        IDENTIFIER,         // such as x
        KEYWORDS,           // such as if
        OPERATOR,           // such as + - * /
        DELIMITER,          // such as ,
        END_OF_FILE,        // end of file

        UNKNOWN
    };

    enum class TokenValue
    {
        // see C standard
        UNRESERVED
    };


    class TokenLocation
    {
      public:
        TokenLocation();
        TokenLocation(const std::string &fileName, int line, int column);

        std::string toString() const;
      private:
        std::string fileName_;
        int line_;
        int column_;
    };

    class Token
    {
      public:
        Token();
        Token(TokenType type, TokenValue value, const TokenLocation &location,
                    std::string name);
        Token(TokenType type, TokenValue value, const TokenLocation &location,
                    std::string &strValue, std::string name);
        Token(TokenType type, TokenValue value, const TokenLocation &location,
                    long intValue, std::string name);
        Token(TokenType type, TokenValue value, const TokenLocation &location,
                    double realValue, std::string name);

        // get token information
        TokenType getTokenType() const;
        TokenValue getTokenValue() const;
        const TokenLocation& getTokenLocation() const;
        std::string getTokenName() const;

        // get constant values of token
        long getIntValue() const;
        double getRealValue() const;
        std::string getStringValue() const;

        // output debug information
        void dump(std::ostream &out = std::cout) const;

        // more exact function for getting identifier name.
        // Its essential heart is just getTokenName.
        std::string getIdentifierName() const;
        std::string tokenTypeDescription() const;
        std::string toString() const;

      private:
        TokenType       type_;
        TokenValue      value_;
        TokenLocation   location_;
        std::string     name_;

        // const values of token
        long            intValue_;
        double          realValue_;
        std::string     strValue_;

    };

    inline TokenType Token::getTokenType() const
    {
        return type_;
    }

    inline TokenValue Token::getTokenValue() const
    {
        return value_;
    }

    inline std::string Token::getTokenName() const
    {
        return name_;
    }

    inline const TokenLocation& Token::getTokenLocation() const
    {
        return location_;
    }

    inline long Token::getIntValue() const
    {
        return intValue_;
    }

    inline double Token::getRealValue() const
    {
        return realValue_;
    }

    inline std::string Token::getStringValue() const
    {
        return strValue_;
    }

    inline std::string Token::getIdntifierName() const
    {
        assert(type_ == TokenType::IDENTIFIER && "Token type should be identifier.");
        return name_;
    }
}

#endif  // token.h
