#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int charClass;
#define MAX_LEN 100
char lexeme[MAX_LEN];
char nextChar;
char next2Char;
int lexLen;
int token;
int nextToken;
FILE *inFile;

#define LETTER  0
#define DIGIT   1
#define UNKNOWN 999

enum { WHILE = 258, IF, ELSE, FOR, RET, INT, ID, EQU, UNEQU, GEQU, LEQU, ERROR};
char *keywords[] = {"while", "if", "else", "for", "return", 0};

void addChar()
{
    if(lexLen <= MAX_LEN - 2)
    {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    }
    else
    {
        printf("Error:lexeme is too long.\n");
    }
}

void getChar()
{
    static int firstRun = 1;
    if(firstRun)
    {
        nextChar = getc(inFile);
        next2Char = getc(inFile);
        firstRun = 0;
    }
    else
    {
        nextChar = next2Char;
        next2Char = getc(inFile);
    }

    if(nextChar == EOF)
    {
        charClass = EOF;
    }
    else
    {
        if(isalpha(nextChar))
        {
            charClass = LETTER;
        }
        else if(isdigit(nextChar))
        {
            charClass = DIGIT;
        }
        else
        {
            charClass = UNKNOWN;
        }
    }
}

void getNonBlank()
{
    while(isspace(nextChar))
    {
        getChar();
    }
}

int checkSymbol(char ch, char nextCh)
{
    switch(ch)
    {
        case '(':case ')':case ';':case '+':case '-':case '"':
        case '\'':case '[':case ']':case '{':case '}':case ',':
        case ':':case '.':case '\\':case '*':
        addChar();
        nextToken = ch;
        break;
    case '=':
        addChar();
        nextToken = ch;
        if(nextCh == '=')
        {
            getChar();
            addChar();
            nextToken = EQU;
        }
        break;
    case '!':
        addChar();
        nextToken = ch;
        if(nextCh == '=')
        {
            getChar();
            addChar();
            nextToken = UNEQU;
        }
        break;
    case '>':
        addChar();
        nextToken = ch;
        if(nextCh == '=')
        {
            getChar();
            addChar();
            nextToken = GEQU;
        }
        break;
    case '<':
        addChar();
        nextToken = ch;
        if(nextCh == '=')
        {
            getChar();
            addChar();
            nextToken = LEQU;
        }
        break;
    case EOF:
        addChar();
        nextToken = EOF;
        break;
    default:
        printf("Error:unknown character '%c'.\n", ch);
        nextToken = ERROR;
    }
    return nextToken;
}


void checkKeywords(char *pword)
{
    int i = 0;
    while(keywords[i] != 0)
    {
        char *pkeyword = keywords[i];
        if(strcmp(pword, pkeyword) == 0)
        {
            nextToken = 258 + i;
            return ;
        }
        i++;
    }
}

int lexer()
{
    lexLen = 0;
    getNonBlank();
    switch(charClass)
    {
    case LETTER:
        addChar();
        getChar();
        while(charClass == LETTER || charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = ID;
        // 检查当前标志符是否是关键字
        checkKeywords(lexeme);
        break;
    case DIGIT:
        addChar();
        getChar();
        while(charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = INT;
        break;

    case UNKNOWN:
        checkSymbol(nextChar, next2Char);
        getChar();
        break;
    case EOF:
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = '\0';
        break;
    }

    printf("<%6d,  %s  >\n", nextToken, lexeme);
    return nextToken;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Error: input file name is needed. \n");
        exit(0);
    }
    inFile = fopen(argv[1], "r");
    if(inFile == NULL)
    {
        printf("Error: can not open file.\n");
        exit(0);
    }

    getChar();
    while(nextToken != EOF)
    {
        lexer();
    }
}

