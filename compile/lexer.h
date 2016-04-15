#ifndef LEXER_H_
#define LEXER_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

#define MAX_LEN 256
#define LETTER  0
#define DIGIT   1
#define UNKNOWN 999

enum { WHILE = 258, IF, ELSE, FOR, RET, INT, ID, EQU, UNEQU, GEQU, LEQU, ERROR};
char *keywords[] = {"while", "if", "else", "for", "return", 0};


class Lexer
{
public:
    Lexer(){}
    void addChar();
    void getChar();
    void getNonBlank();
    int checkSymbol(char ch, char nextch);
    void checkKeywords(char *pword);
    int lexer();
    void readFile(ifstream file);

private:
    int token
    char lexeme[MAX_LEN];
};

#endif
