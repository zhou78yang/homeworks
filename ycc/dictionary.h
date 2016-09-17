#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <string>
#include <tuple>
#include <map>
#include "token.h"


namespace ycc
{
    class Dictionary
    {
      public:
        Dictionary();
        std::tuple<TokenType, TokenValue> lookup(const std::string &name) const;
        bool haveToken(const std::string &name) const;
      private:
        void addToken(std::string name, std::tuple<TokenValue, TokenType> tokenMeta);
      
      private:
        std::map<std::string, std::tuple<TokenValue, TokenType>> dictionary_;
    };
}


#endif  // dictionary.h
