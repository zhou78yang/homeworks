#include <iostream>
#include "vigenere.h"

void Vigenere::init()
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            cipherTable[i][j] = (i+j) % 26;
        }
    }
}

void Vigenere::encryption()
{
    cipherText = explicitly;
    int m, n;
    for(int i = 0; i < explicitly.length(); i++)
    {
        if(explicitly[i] == ' ') continue;
        m = int(explicitly[i] - 'a');
        n = int(key[i%(key.length())] - 'a');
        cipherText[i] = char('A' + cipherTable[n][m]);
    }
}

void Vigenere::decryption()
{
    explicitlyText = cipherText;
    int m, n;
    for(int i = 0; i < cipherText.length(); i++)
    {
        if(explicitly[i] == ' ') continue;
        n = int(key[i%(key.length())] - 'a');
        m = getPosition(i, n);
        explicitlyText[i] = char('a' + m);
    }
}

int Vigenere::getPosition(int p, int n)
{
    int position;
    for(int i = 0; i < 26; i++)
    {
        if(char(cipherText[p]) == char('A' + cipherTable[n][i]))
        {
            position = i;
            break;
        }
    }
    return position;
}

void Vigenere::setKey()
{
    getline(cin, key);
}

void Vigenere::setExplicitly()
{
    getline(cin, explicitly);
}

void Vigenere::output()
{
    cout << "key: " << key << endl;
    cout << "msg: " << explicitly << endl;
    cout << "cip: " << cipherText << endl;
    cout << "out: " << explicitlyText << endl;
}
