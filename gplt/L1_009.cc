#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b)
{
    if(a < b) return gcd(b, a);
    return a % b ? gcd(b, a%b) : b;
}

int main()
{
    int n;
    long A[105], B[105];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%ld/%ld", A+i, B+i);
    }

    long long base = B[0];               // 求出最终分母
    for(int i = 1; i < n; i++)
    {
        base = base / gcd(base, B[i]) * B[i];   // 防溢出
    }

    long long frac = 0;
    for(int i = 0; i < n; i++)
    {
        frac += base / B[i] * A[i];
    }

    if(frac < 0)
    {
        cout << "-";
        frac = -frac;
    }

    long long tmp = gcd(frac, base);
    frac /= tmp;
    base /= tmp;

    if(base == 1)
    {
        cout << frac << endl;
    }
    else if(frac == 0)
    {
        cout << 0 << endl;
    }
    else if(frac > base)
    {
        cout << frac/base << " " << frac%base << "/" << base << endl;
    }
    else
    {
        cout << frac << "/" << base << endl;
    }

    return 0;
}
