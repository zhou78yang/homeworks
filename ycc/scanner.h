#ifndef SCANNER_H_
#define SCANNER_H_

#include <fstream>
#include <string>
#include "token.h"
#include "dictionary.h"

namespace ycc
{
    class Scanner
    {
      public:
        explicit        Scanner(const std::string &srcFileName);
        Token           getToken() const;
        Token           getNextToken();
        TokenLocation   getTokenLocation() const;
        static bool     getErrorFlag();
        static void     setErrorFlag(bool flag);

      private:
        void            getNextChar();                          // 获取下一个字符
        char            peekChar();                             // 窥视下一个字符
        void            addToBuffer(char c);                    // 添加字符到buffer
        void            reduceBuffer();                         // 删除buffer末尾字符

        void            makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc, 
                                  std::string name);
        void            makeToken(TokeyType tt, TokenValue tv, const TokenLocation &loc, 
                                  long intValue, std::sring name);
        void            makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc, 
                                  double realValue, std::string name);
        void            makeToken(TokenType tt, TokenValue tv, const TokenLocation &loc, 
                                  const std::string &strValue, std::string name);

        void            preprocess();                           // 无效字符处理
        void            handleLineComment();                    // 行注释处理
        void            handleBlockComment();                   // 块注释处理

        void            handleEOFState();                       // 文件结束状态
        void            handleIdentifierState();                // 扫描到标识符
        void            handleNumberState();                    // 扫描到数字
        void            handleStringState();                    // 扫描到字符 or 字符串
        void            handleOperationState();                 // 扫描到操作符

        void            handleDigit();                          // 十进制数扫描
        void            handleODigit();                         // 八进制数扫描
        void            handleXDigit();                         // 十六进制数扫描
        void            handleFraction();                       // 浮点数扫描
        void            handleExponent();                       // 指数形式数字扫描

        void            errorReport(const std::string &msg);    // 错误处理

      public:
        enum class State
        {
            // 扫描状态
            NONE,                                               // Token的结束和开始
            END_OF_FILE,                                        // 文件结束
            IDENTIFIER,                                         // 标识符
            NUMBER,                                             // 数字
            STRING,                                             // 字符串
            OPERATION                                           // 操作符
        };

      private:
        std::ifstream   input_;                                 // 输入流
        std::string     fileName_;                              // 文件名
        long            line_;                                  // 行号
        long            column_;                                // 列号
        TokenLocation   loc_;                                   // Token位置
        char            currentChar_;                           // 当前字符
        State           state_;                                 // 扫描状态
        Token           token_;                                 // 当前扫描到的token
        Dictionary      dictionary_;                            // 符号表
        std::string     buffer_;                                // 输入栈
        static bool     errorFlag_;                             // 错误标识
    };

    inline Token Scanner::getToken() const
    {
        return token_;
    }

    inline bool Scanner::getErrorFlag()
    {
        return errorFalg_;
    }

    inline TokenLocation Scanner::getTokenLocation() const
    {
        return TokenLocation(fileName_, line_, column_);
    }

}

#endif
