#include <iostream>
using namespace std;

int getReverse(int x, int d)
{
    int r = 0;
    while(x > 0)
    {
        r = r * d + x % d;
        x /= d;
    }
    return r;
}

int len = 0, primers[100000];
bool isPrimer(int x)
{
    for(int i = 0; i < len && primers[i]*primers[i] <= x; i++)
    {
        if(x % primers[i] == 0) return false;
    }
    return true;
}

int main()
{
    int x, d;
    for(int i = 2; i < 100000; i++)
    {
        if(isPrimer(i))
        {
            primers[len++] = i;
        }
    }
    while(cin >> x >> d)
    {
        if(x < 0) break;
        if(isPrimer(x) && isPrimer(getReverse(x, d))) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
