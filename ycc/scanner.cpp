#include <algorithm>
#include <cctype>
#include "scanner.h"
#include "error.h"

namespace ycc
{
    bool Scanner::errorFlag_ = false;

    void Scanner::setErrorFlag(bool flag)
    {
        errorFlag_ = flag;
    }

    SCanner::Scanner(const std::string &srcFileNamem)
        : fileName_(srcFileName), line_(1), column_(0),
          currentChar_(0), state_(State::NONE)
    {
        input_.open(fileName_);

        if(input_.fail())
        {
            errorReport("When trying to open file " + fileName_ + ", occurred error.");
        }
    }

    void Scanner::getNextChar()
    {
        currentChar_ = input_.get();

        if(currentChar_ == '\n')
        {
            line_++;
            column_ = 0;
        }
        else
        {
            column_++;
        }
    }

    char Scanner::peekChar()
    {
        char c = input_.peek();
        return c;
    }

    void Scanner::addToBuffer(char c)
    {
        buffer_.push_back(c);
    }

    void Scanner::reduceBuffer()
    {
        buffer_.pop_back();
    }


    void Scanner::makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc,
                            std::string name)
    {
        token_ = Token(tt, tv, loc, name);
        buffer_.clear();
        state_ = State::NONE;
    }

    void Scanner::makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc,
                            long intValue, std::string name)
    {
        token_ = Token(tt, tv, loc, intValue, name);
        buffer_.clear();
        state_ = State::NONE;
    }

    void Scanner::makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc,
                            double realValue, std::string name)
    {
        token_ = Token(tt, tv, loc, realValue, name);
        buffer_.clear();
        state_ = State::NONE;
    }

    void Scanner::makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc,
                            const std::string strValue, std::string name)
    {
        token_ = Token(tt, tv, loc, strValue, name);
        buffer_.clear();
        state_ = State::NONE;
    }

    
    void Scanner::preprocess()
    {
        do
        {
            while(std::isspace(currentChar_))
            {
                getNextChar();
            }

            handleLineComment();
            handleBlockComment();
        }while(std::isspace(currentChar_));
    }

    void Scanner::handleLineComment()
    {
        loc_ = getTokenLocation();

        if(currentChar_ == '/' && peekChar() == '/')
        {
            // 过滤掉该行剩下的字符
            while(!(currentChar_ == '\n'))
            {
                // 跳过注释内容
                getNextChar();

                // EOF预防
                if(input_.eof())
                {
                    break;
                }
            }

            if(!input_.eof())
            {
                // 回车操作
                getNextChar();
            }
        }
    }

    void Scanner::handleBlockComment()
    {
        loc_ = getTokenLocation();
        
        if(currentChar_ == '/' && peekChar() == '*')
        {
            // 去掉"/*"
            getNextChar();
            getNextChar();

            while(!(currentChar_ == '*' && peekChar() == '/'))
            {
                // 跳过注释内容
                getNextChar();

                // EOF预防
                if(input_.eof())
                {
                    errorReport(std::string("end of file happended in comment, */ is expected, but fund ")
                                + currentChar_);
                    break;
                }
            }

            if(!input_.eof())
            {
                // 去掉"*/"
                getNextChar();
                getNextChar();
            }
        }
    }

    Token Scanner::getNextToken()
    {
        bool matched = false;

        while(!matched)
        {
            if(state_ != State::NONE)
            {
                matched = true;
            }

            switch(state_)
            {
                case State::NONE:
                    getNextChar();
                    break;

                case State::END_OF_FILE:
                    handleEOFState();
                    break;

                case State::IDENTIFIER:
                    handleIdentifierState();
                    break;

                case State::NUMBER:
                    handleNumberState();
                    break;

                case State::STRING:
                    handleStringState();
                    break;

                case State::OPERATION:
                    handleOperationState();
                    break;

                default:
                    errorReport("Match token state error!");
                    break;
            }

            if(state_ == State::NONE)
            {
                preprocess();

                if(input_.eof())
                {
                    state_ = State::END_OF_FILE;
                }
                else
                {
                    if(std::isalpha(currentChar_) || currentChar_ == '_')
                    {
                        state_ = State::IDENTIFIER;
                    }
                    else if(std::isdigit(currentChar_))
                    {
                        state_ = State::NUMBER;
                    }
                    else if(currentChar_ == '\"' || currentChar_ == '\'')
                    {
                        state_ = State::STRING;
                    }
                    else
                    {
                        state_ = State::OPERATION;
                    }
                }
            }
        }// while

        return token_;
    }

    void SCanner::handleEOFState()
    {
        loc_ = getTokenLocation();

        makeToken(TokenType::END_OF_FILE, TokenValue::UNRESERVED, loc_,
                    std::string("END_OF_FILE"));
        // close the file
        input_.close();
    }

    void Scanner::handleIdentifierState()
    {
        loc_ = getTokenLocation();

        addToBuffer(currentChar_);
        getNextChar();

        while(std::isalnum(currentChar_) || currentChar_ == '_')
        {
            addToBuffer(currentChar_);
            getNextChar();
        }

        auto tokenMeta = dictionary_.lookup(buffer_);
        makeToken(std::get<0>(tokenMeta), std::get<1>(tokenMeta), loc_, buffer_);
    }

    void Scanner::handleNumberState()
    {
        loc_ = getTokenLocation();
        bool isFloat = false;
        bool isExponent = false;
        int numberBase = 10;

        if(currentChar_ == '0')
        {
            numberBase = 8;
            
            if(peekChar() == 'x' || peekChar() == 'X')
            {
                numberBase = 16;
            }
        }

        enum class NumberState
        {
            INTEGER,
            FRACTION,
            EXPONENT,
            DONE
        };
        NumberState numberState = NumberState::INTEGER;

        while(numberState != NumberState::DONE)
        {
            switch(numberState)
            {
                case NumberState::INTEGER:
                    if(numberBase == 10)
                    {
                        handleDigit();
                    }
                    else if(numberBase == 8)
                    {
                        handleODigit();
                    }
                    else if(numberBase == 16)
                    {
                        handleXDigit();
                    }
                    break;

                case NumberState::FRACTION:
                    handleFraction();
                    isFloat = true;
                    break;

                case NumberState::EXPONENT:
                    handleExponent();
                    isExponent = true;
                    break;

                case NumberState::DONE:
                    break;

                default:
                    errorReport("Match number error!");
                    break;
            }

            if(currentChar_ == '.')
            {
                if(isFloat)
                {
                    errorReport("Fraction number can not be have more than one dot.");
                }
                
                if(numberBase != 10)
                {
                    errorReport("Fracton should be a decimal number.");
                }

                numberState = NumberState::FRACTION;
            }
            else if(currentChar_ == 'E' || currentChar_ = 'e')
            {
                if(isExponent)
                {
                    errorReport("Scientist presentation can not have more than one e / E");
                }

                numberState = NumberState::EXPONENT;
            }
            else
            {
                numberState = NumberState::DONE;
            }
        }// while

        if(!getErrorFlag())
        {
            if(isFloat || isExponent)
            {
                makeToken(TokenType::REAL, TokenValue::UNRESERVED, loc_,
                            std::stod(buffer_), buffer_);
            }
            else
            {
                makeToken(TokenType::INTEGER, TokenValue::UNRESERVED, loc_,
                            std::stol(buffer_, 0, numberBase), buffer_);
            }
        }
        else
        {
            buffer_.clear();
            state_ = State::NONE;
        }

    }

    void Scanner::handleStringState()
    {
        loc_ = getTokenLocation();
        
        if(currentChar_ == '\'')
        {
            getNextChar();  // 去掉', currentChar_为字符常量
            if(currentChar_ == '\'')
            {
                errorReport(" empty character constant.");
            }
            else if(peerChar() != '\'')
            {
                errorReport(" multi-character character constant.");
            }
            else
            {
                addToBuffer(currentChar_);
                makeToken(TokenType::CHAR, TokenValue::UNRESERVED, loc_,
                          static_cast<long>(buffer_.at(0)), buffer_);
            } 

            getNextChar();  // 去掉', currentChar_指向下一个token头
            getNextChar();

            return ;
        }

        getNextChar();  // 去掉", currentChar_为字符串首
        
        while(currentChar_ != '\"')
        {
            addToBuffer(currentChar_);
            getNextChar();
        }

        getNextChar();  // 去掉", currentChar_指向下一个token头
        makeToken(TokenType::STRING, TokenValue::UNRESERVED, loc_,
                  buffer_, buffer_);
    }

    void Scanner::handleOperationState()
    {
        loc_ = getTokenLocation();

        addToBuffer(currentChar_);
        addToBuffer(peekChar());

        if(dictionary_.haveToken(buffer_))
        {
            getNextChar();  // 运算符由两个字符组成
        }
        else
        {
            reduceBuffer();
        }

        auto tokenMeta = dictionary_.lookup(buffer_);
        makeToken(std::get<0>(tokenMeta), std::get<1>(tokenMeta), loc_,
                  buffer_);
        getNextChar();

    }


    void Scanner::handleDigit()
    {
        do
        {
            addToBuffer(currentChar_);
            getNextChar();
            // 当currentChar_不为数字是退出
        }while(std::isdigit(currentChar_));
    }

    void Scanner::handleODigit()
    {
        do
        {
            addToBuffer(currentChar_);
            getNextChar();
            if(currentChar_ >= '8')
            {
                errorReport(" invalid digit '" + currentChar_ + "' in octal constant.");
            }
        }while(std::isdigit(currentChar_));
    }

    void Scanner::handleXDigit()
    {
        // 去掉0x
        addToBuffer(currentChar_);
        getNextChar();
        addToBuffer(currentChar_);
        getNextChar();

        while(std::isxdigit(currentChar_))
        {
            addToBuffer();
            getNextChar();
        }
    }

    void Scanner::handleFraction()
    {
        // currentChar_ is .(dot)
        if(!std::isdigit(peekChar()))
        {
            errorReport("Fraction number part should be nubmers.");
        }

        // get the .(dot)
        addToBuffer();
        getNextChar();

        while(std::isdigit(currentChar_))
        {
            addToBuffer();
            getNextChar();
        }
    }

    void Scanner::handleExponent()
    {

    }


    void Scanner::errorReport(const std::string &msg)
    {
        errorToken(getTokenLocation().toString() + msg);
    }

}
