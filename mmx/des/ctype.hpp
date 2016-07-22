#ifndef CTYPE_HPP_
#define CTYPE_HPP_

// 数据转换为文本表示形式
std::string DES::ullToStr(unsigned long long num)
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
std::string DES::ullToHex(unsigned long long num)
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
std::string DES::ullToBin(unsigned long long num)
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

#endif
