#ifndef DES_H_
#define DES_H_

#include <iostream>
#include <string>

class DES
{
  public:
    DES():key(0), plainText(0), cipherText(0), decipherText(0)
    {}

    void setKey(unsigned long long k);              // 直接设置密钥
    void setKey(const char k[]);                    // 文本设置密钥
    void setPlainText(unsigned long long p);        // 直接设置明文
    void setPlainText(const char p[]);              // 文本设置明文
    void setCipherText(unsigned long long c);       // 设置密文
    void setCipherText(const char c[]);             // 文本设置密文
    void genEncKey();                               // 轮密钥生成器
    void encryption();                              // 加密模块
    void decryption();                              // 解密模块
    void dump(std::ostream &out = std::cout);       // 显示内部信息

    // 返回内部信息
    std::string getCipherText();                    // 输出加密文本
    std::string getDecipherText();                  // 输出解密文本
    std::string getKey();                           // 显示密钥

  private:
    unsigned long long  permutations(unsigned long long num,
                                     const int p[], int pmax, int n);
    unsigned long long  SBoxes(unsigned long long num);
    unsigned long long  keyLS(unsigned long long k, int n);

  private:
    unsigned long long  key;                        // 输入的密钥
    unsigned long long  plainText;                  // 输入的明文
    unsigned long long  cipherText;                 // 加密的密文
    unsigned long long  decipherText;               // 解密后的到的明文
    unsigned long long  encKey[16];                 // 加密密钥，共16个

    static const int    IP[64];                     // 初始置换数组
    static const int    IPI[64];                    // 逆初始置换数组
    static const int    keyIP[56];                  // 密钥置换选择1数组
    static const int    keyCP[48];                  // 密钥置换选择2数组
    static const int    encKeyRound[16];            // 循环左移位数
    static const int    EP[48];                     // 扩展置换数组
    static const int    SBox[8][4][16];             // S盒数组
    static const int    P[32];                      // P盒数组

};

inline void DES::setKey(unsigned long long k)
{
    key = k;
}

inline void DES::setPlainText(unsigned long long p)
{
    plainText = p;
}

#endif
