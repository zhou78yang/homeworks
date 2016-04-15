#include <iostream>
using namespace std;

struct ExtEuc
{
    int d;
    int s;
    int t;
};

ExtEuc ExtEuclid(int a, int b)
{
    ExtEuc eu, eu1;
    if(b == 0)
    {
        eu1.d = a;
        eu1.s = 1;
        eu1.t = 0;
        return eu1;
    }
    eu1 = ExtEuclid(b, a%b);
    eu.d = eu1.d;
    eu.s = eu1.t;
    eu.t = eu1.s - (a/b) * eu1.t;
    return eu;
}

int main(int argc, char **argv)
{
    ExtEuc eu;
    int a, b;
    
    while(cin >> a >> b)
    {
        eu = ExtEuclid(a, b);
        cout << "d = " << eu.d << "  "
            <<  "s = " << eu.s << "  "
            <<  "t = " << eu.t << "  "
            <<  endl;
    }
    return 0;
}


