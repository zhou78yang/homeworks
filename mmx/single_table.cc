#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const char c[27] = {'d', 'j', 'k', 'z', 'u', 'x', 'c', 'm', 'l', 'i', 'w',
    'b', 'v', 'n', 'o', 'p', 'q', 'a', 'r', 's', 'g', 'h', 'f', 't', 'y',
    'e', ' '};

void encryption(ifstream &fin, ofstream &fout);

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    fin.open("file_1.in");
    if(fin.fail())
    {
        cout << "File open error!(Input)" << endl;
        exit(1);
    }
    fout.open("file_1.out");
    if(fout.fail())
    {
        cout << "File open error!(Output)" << endl;
        exit(1);
    }
    encryption(fin, fout);
    fin.close();
    fout.close();
    return 0;
}

void encryption(ifstream &fin, ofstream &fout)
{
    char next;
    char ch;
    int i;
    while(fin.get(next))
    {
        if(next >= 'a' && next <= 'z')
        {
            i = next - 'a';
            ch = c[i];
            fout << ch;
        }
        else
        {
            fout << " ";
        }
    }
}
