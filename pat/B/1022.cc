#include <iostream>
using namespace std;

int main()
{
    int a, b, c, mod;
    int num[32], len = 0;

    cin >> a >> b >> mod;
    c = a + b;

    do
    {
        num[len++] = c % mod;
        c /= mod;
    } while(c > 0);

    for(int i = len-1; i >= 0; i--) cout << num[i];
    cout << endl;

    return 0;
}

