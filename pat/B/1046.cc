#include <iostream>
using namespace std;

int main()
{
    int a1, a2, b1, b2;
    int n, d1 = 0, d2 = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        if(a2 == b2) continue;
        if(a2 == a1 + b1) d2++;
        if(b2 == a1 + b1) d1++;
    }

    cout << d1 << " " << d2 << endl;

    return 0;
}
