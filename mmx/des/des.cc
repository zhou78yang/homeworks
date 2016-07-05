#include "des.h"

// 初始变换IP
const int DES::IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7};

// 逆初始变换IPI
const int DES::IPI[64] = {
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25};





// 密钥置换选择1
const int DES::keyIP[56] = {
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4};

// 密钥置换选择2
const int DES::keyCP[48] = {
    14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

// 密钥循环左移位数
const int DES::encKeyRound[16] = {
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1};





// 扩展变换E : 输入32位
const int DES::EP[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32,  1};

// S盒定义
const int DES::SBox[8][4][16] = {
    // S1 Box
    14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
    4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
    15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
    // S2 Box
    15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
    0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
    13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,
    // S3 Box
    10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
    13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
    // S4 Box
    7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
    10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
    // S5 Box
    2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 2, 9, 8, 6,
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,
    // S6 Box
    12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
    9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,
    // S7 Box
    4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
    1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
    // S8 Box
    13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

// P置换 : 输入32位，来自S盒
const int DES::P[32] = {
    16,  7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26,  5, 18, 31, 10,
     2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25};   











// 设置密钥
//  输入限制：k的长度为8
void DES::setKey(const char k[])
{
    key = 0;
    unsigned long long c;
    for(int i = 0; i < 8; i++)
    {
        c = k[i];
        key |= c << ((7-i) * 8);
    }
}


// 设置明文
//  输入限制：p的长度为8
void DES::setPlainText(const char p[])
{
    unsigned long long c;
    for(int i = 0; i < 8; i++)
    {
        c = p[i];
        plainText |= c << ((7-i) * 8);
    }
}







// 轮密钥生成器
//  生成16个密钥, 对应16轮乘积变换
void DES::genEncKey()
{
    unsigned long long gKey;                            // 临时计算的密钥
    gKey = permutations(key, keyIP, 64, 56);            // 置换选择1

    for(int i = 0; i < 16; i++)
    {
        gKey = keyLS(gKey, encKeyRound[i]);
        encKey[i] = permutations(gKey, keyCP, 56, 48);  // 置换选择2
    }
}

// 密钥循环左移操作
//  输入: encKey[i-1], encKeyRound[i-1]
//  输出: encKey[i]
unsigned long long DES::keyLS(unsigned long long k, int n)
{
    unsigned long long tempKey = 0;
    unsigned long long L, R;                            // 密钥的左右两半
    L = (k&0xFFFFFFF0000000LL) >> 28;
    R = k &0x0000000FFFFFFFLL;
    if(1 == n)
    {
        L = ((L&0x7FFFFFF)<<1) | ((L>>27)&1);
        R = ((R&0x7FFFFFF)<<1) | ((R>>27)&1);
        tempKey = (L<<28) | R;
    }
    else if(2 == n)
    {
        L = ((L&0x3FFFFFF)<<2) | ((L>>26)&3);
        R = ((R&0x3FFFFFF)<<2) | ((R>>26)&3);
        tempKey = (L<<28) | R;
    }
    else
    {
        tempKey = k;
    }
    return tempKey;
}


// 置换操作
//  num : 要处理的数字
//  P   : 选择的置换数组
//  pmax: 置换数组位数/输入的位数
//  n   : 输出的位数
unsigned long long DES::permutations(unsigned long long num,
                                     const int p[], int pmax, int n)
{
    unsigned long long temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp <<= 1;             
        temp |= (num >> (pmax-p[i]))&1;
    }
    return temp;
}


// 加密操作
void DES::encryption()
{
    // 1. 初始置换IP
    unsigned long long temp = permutations(plainText, IP, 64, 64);
    unsigned long long L, R, tempR;

    L = (temp&0xFFFFFFFF00000000LL)>>32;
    R = (temp&0x00000000FFFFFFFFLL);
    tempR = R;

    // 2. 16轮乘积变换
    for(int i = 0; i < 16; i++)
    {
        tempR = permutations(R, EP, 32, 48);        // 2-1. 拓展变换E
        tempR = tempR ^ encKey[i];                  
        tempR = SBoxes(tempR);                      // 2-2. S盒操作
        tempR = permutations(tempR, P, 32, 32);     // 2-3. P盒操作
        tempR = tempR ^ L;                          
        L = R;
        R = tempR;
    }
    temp = (R<<32) | L;

    // 3. 逆初始置换IPI
    cipherText = permutations(temp, IPI, 64, 64);
}

// S盒操作
//  要求对数据进行压缩,
//  输入48位数据，输出32位运算结果.
unsigned long long DES::SBoxes(unsigned long long num)
{
    unsigned long long temp, result = 0;
    int x, y;

    // 8个S盒操作
    for(int i = 0; i < 8; i++)
    {
        temp = (num>>((7-i)*6))&0x3F;               // 6位输入
        x = ((temp>>4)&0x2) | (temp&0x1);           // 首尾2位
        y = (temp>>1)&0xF;                          // 中间4位
        temp = SBox[i][x][y];                       // S盒4位输出

        // 输出加入结果
        temp = temp<<((7-i)*4);
        result |= temp;
    }

    return result;
}


// 解密操作
//  解密过程与加密过程相似，解密与加密使用相同的算法
//  但是，解密时子密钥的使用顺序要反过来
void DES::decryption()
{
    unsigned long long temp = permutations(cipherText, IP, 64, 64);
    unsigned long long L, R, tempR;
    
    L = (temp&0xFFFFFFFF00000000LL)>>32;
    R = (temp&0x00000000FFFFFFFFLL);
    tempR = R;

    for(int i = 15; i >= 0; i--)
    {
        tempR = permutations(R, EP, 32, 48);
        tempR = tempR ^ encKey[i];                  // 子密钥使用顺序相反
        tempR = SBoxes(tempR);
        tempR = permutations(tempR, P, 32, 32);
        tempR = tempR ^ L;
        L = R;
        R = tempR;
    }
    temp = (R<<32) | L;

    decipherText = permutations(temp, IPI, 64, 64);
}







// 数据转换为文本表示形式
std::string DES::toString(unsigned long long num)
{
    std::string str = "";
    char c;
    for(int i = 0; i < 8; i++)
    {
        c = (char)((num >> (7-i)*8)&0xFF);
        str += c;
    }

    return str;
}

// 数据转换为16进制表示形式
std::string DES::toHex(unsigned long long num)
{
    static const char hex_table[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    std::string str = "";

    for(int i = 0; i < 16; i++)
    {
        int tmp = (int)((num >> (15-i)*4)&0x000F);
        str += hex_table[tmp];
    }

    return str;
}

// 数据转换为2进制表示形式
std::string DES::toBin(unsigned long long num)
{
    std::string str = "";
    for(int i = 63; i >= 0; i--)
    {
        if((num>>i)&1)
        {
            str += '1';
        }
        else
        {
            str += '0';
        }

        if(i % 8 == 0) str += ' ';
    }
    
    return str;
}

// 显示内部信息
void DES::dump(std::ostream &out /* = std::cout */)
{
    out << "K: " << toString(key) << "\t" << toHex(key) << "\n"
        << "P: " << toString(plainText) << "\t" << toHex(plainText) << "\n"
        << "C: " << toString(cipherText) << "\t" << toHex(cipherText) << "\n"
        << "D: " << toString(decipherText) << "\t" << toHex(decipherText) << "\n"
        << "encKeys: " << "\n";

    for(int i = 0; i < 16; i++)
    {
        out << (i+1) << ":\t" << toHex(encKey[i]) << "\n";
    }
}


// 返回内部信息
std::string DES::getCipherText()
{
    return toString(cipherText);
}

std::string DES::getDecipherText()
{
    return toString(decipherText);
}

std::string DES::getKey()
{
    return toString(key);
}

