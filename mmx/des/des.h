#ifndef DES_H_
#define DES_H_

#include <iostream>
#include <string>

using namespace std;

class DES
{
  public:
    DES():key(0), plainText(0), cipherText(0), decipherText(0)
    {}
    void setKey(char *k);
    void setPlainText(char *p);
    void genEncKey();
    void encryption();
    void decryption();
    void showBinary(unsigned long long num);
    void showResult();

  private:
    unsigned long long permutations(unsigned long long num,
                                    const int p[], int pmax, int n);
    unsigned long long SBoxes(unsigned long long num);
    unsigned long long keyLS(unsigned long long k, int n);

  private:
    unsigned long long key;             // 输入的密钥
    unsigned long long plainText;       // 输入的明文
    unsigned long long cipherText;      // 加密的密文
    unsigned long long decipherText;    // 解密后的到的明文
    unsigned long long encKey[16];      // 加密密钥，共16个

    static const int IP[64];            // 初始置换数组
    static const int IPI[64];           // 逆初始置换数组
    static const int keyIP[56];         // 密钥置换选择1数组
    static const int keyCP[48];         // 密钥置换选择2数组
    static const int encKeyRound[16];   // 循环左移位数
    static const int EP[48];            // 扩展置换数组
    static const int SBox[32][16];      // S盒运算的二维数组
    static const int P[32];             // P盒数组，用于S盒置换后
};


#endif
