#include <iostream>
using namespace std;

int main()
{
    int n;
    long long a, b, c;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
       cin >> a >> b >> c;
       if(a+b > c) cout << "Case #" << i << ": true\n";
       else cout << "Case #" << i << ": false\n";
    }

    return 0;
}

