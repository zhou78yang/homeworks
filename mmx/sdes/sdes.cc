#include "sdes.h"

const int SDES::P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
const int SDES::P8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
const int SDES::IP[8] = {2, 6, 3, 1, 4, 8, 5, 7};
const int SDES::IPI[8] = {4, 1, 3, 5, 7, 2, 8, 6};
const int SDES::EP1[4] = {4, 1, 2, 3};
const int SDES::EP2[4] = {2, 3, 4, 1};
const int SDES::P4[4] = {2, 4, 3, 1};
const int SDES::S0[4][4] = {{1, 0, 3, 2},
                            {3, 2, 1, 0},
                            {0, 2, 1, 3},
                            {3, 1, 3, 2}};
const int SDES::S1[4][4] = {{0, 1, 2, 3},
                            {2, 0, 1, 3},
                            {3, 0, 1, 0},
                            {2, 1, 0, 3}};


void SDES::setKey(string s)
{
    key = binStrToInt(s);
}

void SDES::setPlainText(string s)
{
    plainText = binStrToInt(s);
}

int SDES::binStrToInt(string s)
{
    int key = 0; 
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        key = key * 2 + s[i] - '0';
    }
    return key;
}

void SDES::getKey()
{
    int tempKey;
    tempKey = permutations(key, P10, 10, 10);
    tempKey = shiftLS(tempKey);
    key1 = permutations(tempKey, P8, 10, 8);
    tempKey = shiftLS(tempKey);
    tempKey = shiftLS(tempKey);
    key2 = permutations(tempKey, P8, 10, 8);
}

int SDES::permutations(int num, const int p[], int pmax, int n)
{
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp <<= 1;
        temp |= (num>>(pmax-p[i]))&1;
    }
    return temp;
}

int SDES::shiftLS(int num)
{
    // 长度为10的int型数据,第10位移动到第6位，第5位移动到第1位
    int L = (num>>5) & 0x1F;            
    int R = num & 0x1F;
    L = ((L&0xF)<<1) | ((L&0x10)>>4);
    R = ((R&0xF)<<1) | ((R&0x10)>>4);

    return (L<<5) | R;
}

void SDES::encryption()
{
    cipherText = permutations(plainText, IP, 8, 8);
    int R, L;
    R = cipherText & 0xF;
    L = ((cipherText & 0xF0)>>4);
    fk(key1, L, R);
    int temp = L;
    L = R;
    R = temp;
    fk(key2, L, R);
    temp = (L<<4) | R;
    cipherText = permutations(temp, IPI, 8, 8);
}

void SDES::fk(int key, int &left, int right)
{
    int L = left;
    int R = right;
    int temp;
    int tempL, tempR;
    temp = ((permutations(R, EP1, 4, 4))<<4) | (permutations(R, EP2, 4, 4));
    temp = temp ^ key;
    tempR = temp & 0xF;
    tempL = ((temp & 0xF0) >> 4);
    tempL = S0[((tempL & 0x8)>>2) | (tempL&1)][(tempL>>1)&0x3];
    tempR = S1[((tempR & 0x8)>>2) | (tempR&1)][(tempR>>1)&0x3];
    temp = (tempL<<2) | tempR;
    temp = permutations(temp, P4, 4, 4);
    left = L ^ temp;
}

void SDES::decryption()
{
    decipherText = permutations(cipherText, IP, 8, 8);
    int R, L;
    R = decipherText & 0xF;
    L = ((decipherText & 0xF0)>>4);
    fk(key2, L, R);
    int temp = L;
    L = R; 
    R = temp;
    fk(key1, L, R);
    temp = (L<<4) | R;
    decipherText = permutations(temp, IPI, 8, 8);
}


void SDES::showResult()
{
    cout << "key  : " << key << endl;
    cout << "key1 : " << key1 << endl;
    cout << "key2 : " << key2 << endl;
    cout << "plain : " << plainText << endl;
    cout << "cipher: " << cipherText << endl;
    cout << "deciph: " << decipherText << endl;
}

