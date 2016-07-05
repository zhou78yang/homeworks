#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "des.h"
using namespace std;

int main(int argc, char *argv[])
{
    DES des;

//    课本实例
//    des.setKey(0xAABB09182736CCDD);
//    des.setPlainText(0x123456ABCD132536);
//    des.genEncKey();
//    des.encryption();
//    des.decryption();
//    des.dump();

    ifstream in;
    ofstream out;

    if(argc >= 3)
    {
        in.open(argv[1]);
        out.open(argv[2]);
        des.setKey(argv[3]);
    }
    else
    {
        in.open("input.txt");
        out.open("output.txt");
        des.setKey("~1bji3s8");
    }

    char buffer[8];
    int i = 0;
    while(!in.eof())
    {
        for(i = 0; i < 8 && !in.eof(); i++) in >> buffer[i];
        des.setPlainText(buffer);
        des.encryption();
        if(i == 8)
        {
            out << des.getCipherText();
        }
        else
        {
            string s = des.getCipherText();
            for(int j = 0; j < i; j++) out << s[j];
        }
    }
    
    in.close();
    out.close();
        
    return 0;
}
