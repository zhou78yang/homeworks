#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return a % b ? gcd(b, a%b) : b;
}

int main()
{
    int n1, m1, n2, m2, k, mod;

    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    mod = gcd(max(n1, m1), min(n1, m1));
    n1 /= mod; m1 /= mod;
    mod = gcd(max(n2, m2), min(n2, m2));
    n2 /= mod; m2 /= mod;

    if(n1*m2 > n2*m1)
    {
        swap(n1, n2);
        swap(m1, m2);
    }
    
    int s = n1/m1*k;
    while(s*m1 <= n1*k) s++;
    bool foundBefore = false;

    for(int i = s; i*m2 < n2*k; i++)
    {
        if(gcd(max(k, i), min(k, i)) == 1)
        {
            if(foundBefore) cout << " ";
            foundBefore = true;
            cout << i << "/" << k;
        }
    }
    cout << endl;

    return 0;
}
