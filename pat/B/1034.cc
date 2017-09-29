#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    if(a < b) swap(a, b);
    if(b == 0) return 1;
    return a % b ? gcd(b, a%b) : b;
}

void print(long long a, long long b, long long s)
{
    if(b == 0) 
    {
        cout << "Inf";
        return ;
    }
    if(a == 0)
    {
        cout << "0";
        return ;
    }
    if(s == -1) cout << "(-";
    long long k = a / b;
    a %= b;
    if(k && a) cout << k << " " << a << "/" << b;
    else if(a) cout << a << "/" << b;
    else if(k) cout << k;

    if(s == -1) cout << ")";
}

int main()
{
    char op[] = "+-*/";
    long long a1, b1, a2, b2, mod, a[4], b[4], s[4];

    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    long long s1, s2;
    s1 = a1 < 0 ? -1 : 1;
    s2 = a2 < 0 ? -1 : 1;
    a1 *= s1; a2 *= s2;
    mod = gcd(a1, b1);
    a1 /= mod; b1 /= mod;
    mod = gcd(a2, b2);
    a2 /= mod; b2 /= mod;

    a[0] = s1*a1*b2 + s2*a2*b1;     b[0] = b1*b2;
    a[1] = s1*a1*b2 - s2*a2*b1;     b[1] = b1*b2;
    a[2] = s1*a1*s2*a2;             b[2] = b1*b2;
    a[3] = s1*s2*a1*b2;             b[3] = b1*a2;

    for(int i = 0; i < 4; i++)
    {
        s[i] = a[i] < 0 ? -1 : 1;
        a[i] *= s[i];
        mod = gcd(a[i], b[i]);
        a[i] /= mod; b[i] /= mod;
    }
    
    for(int i = 0; i < 4; i++)
    {
        print(a1, b1, s1);
        cout << " " << op[i] << " ";
        print(a2, b2, s2);
        cout << " = ";
        print(a[i], b[i], s[i]);
        cout << endl;
    }
   
    return 0;
}
