#include <iostream>
#include <map>
using namespace std;

map<char, int> book;

unsigned long long getDecimal(string num, int radix)
{
    unsigned long long origin = 0;
    for(int i = 0; i < num.size(); i++)
    {
        origin = origin * radix + book[num[i]];
    }
    return origin;
}

int getRadix(string num, unsigned long long origin)
{
    int radix = 2;
    for(int i = 0; i < num.size(); i++)
    {
        if(book[num[i]] >= radix) radix = book[num[i]]+1;
    }

    while(radix <= 36)
    {
        unsigned long long x = 0;
        for(int i = 0; i < num.size(); i++) x = x * radix + book[num[i]];
        if(x == origin) return radix;
        if(x > origin) return -1;
        radix++;
    }
    return -1;
}

int main()
{
    unsigned long long origin = 0;
    string n1, n2, digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    int tag, r1, r2;
    
    for(int i = 0; i < digits.size(); i++) book[digits[i]] = i;
    cin >> n1 >> n2 >> tag;

    if(tag == 1)
    {
        cin >> r1;
        origin = getDecimal(n1, r1);
        r2 = getRadix(n2, origin);
        if(r2 != -1) cout << r2 << endl;
        else cout << "Impossible\n";
    }
    else
    {
        cin >> r2;
        origin = getDecimal(n2, r2);
        r1 = getRadix(n1, origin);
        if(r1 != -1) cout << r1 << endl;
        else cout << "Impossible\n";
    }

    return 0;
}
