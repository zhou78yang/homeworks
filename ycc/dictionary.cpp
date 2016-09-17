#include "dictionary.h"

namespace ycc
{
    Dictionary::Dictionary()
    {
        // see C standard
    }

    void Dictionary::addToken(std::string name,
                              std::tuple<TokenValue, TokenType> tokenMeta)
    {
        dictionary_.insert(std::pair<decltype(name), decltype(tokenMeta)>(name, tokenMeta));
    }

    // if we can find it in the dictionary, we change the token type and token value
    std::tuple<TokenType, TokenValue> Dictionary::lookup(const std::string &name) const
    {
        TokenValue tokenValue = TokenValue::UNRESERVED;
        TokenType  tokenType  = TokenType::IDENTIFIER;
        auto       iter       = dictionary_.find(name);

        if(iter != dictionary_.end())
        {
            tokenValue = std::get<0>(iter->second);
            tokenType  = std::get<1>(iter->second);
        }

        return std::make_tuple(tokenType, tokenValue);
    }

    bool Dictionary::haveToken(const std::string &name) const
    {
        auto iter = dictionary_.find(name);

        if(iter != dictionary_.end())
        {
            return true;
        }

        return false;
    }
}
