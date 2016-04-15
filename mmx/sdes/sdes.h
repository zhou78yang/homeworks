#ifndef SDES_H_
#define SDES_H_

#include <iostream>
#include <string>

using namespace std;

class SDES
{
public:
    SDES(){}
    void setKey(string s);          // 设置密钥
    void setPlainText(string s);    // 设置明文
    void fk(int key, int &left, int right); // fx运算
    void getKey();                  // 获得密钥k1和k2
    void encryption();              // 加密过程
    void decryption();              // 解密过程
    int permutations(int num, const int p[], int pmax, int n);  // 置换操作
    int shiftLS(int num);           // 循环左移（左右各半分别左移一位）
    void showResult();              // 显示结果

private:
    int key;                        // 初始密钥
    int key1;                       // 密钥K1
    int key2;                       // 密钥k2
    int binStrToInt(string s);      // 将01字符串转换为数值
    int plainText;                  // 明文
    int cipherText;                 // 密文
    int decipherText;               // 解密后的明文
    // 以下为常量
    static const int P10[10];       // P10置换常量
    static const int P8[8];         // P8置换常量
    static const int IP[8];         // IP置换常量
    static const int IPI[8];        // IP的逆的置换常量
    static const int EP1[4];        // E/P1 置换常量
    static const int EP2[4];        // E/P2 置换常量
    static const int P4[4];         // P4置换常量
    static const int S0[4][4];      // S0 box
    static const int S1[4][4];      // S1 box
};

#endif
