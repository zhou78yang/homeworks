#ifndef VIGENERE_H_
#define VIGENERE_H_

#include <string>
using namespace std;

class Vigenere
{
private:
    int cipherTable[26][26];    // 数字编码表
    string key;                 // 密钥
    string explicitly;          // 待处理的明文
    string cipherText;          // 待处理的密文
    string explicitlyText;      // 解密后的明文

public:
    Vigenere(){ init(); }
    void init();                // 初始化cipherTable
    void setKey();              // 设置加密密钥
    void setExplicitly();       // 设置明文
    void encryption();      
    void decryption();
    void output();
    int getPosition(int p, int n);  // 获取密文解密的位置
};

#endif
