#include <iostream>
using namespace std;

int main()
{
    int h, t, n;
    int x;

    cin >> x;
    h = x / 100;
    t = x % 100 / 10;
    n = x % 10;
    for(int i = 0; i < h; i++) cout << 'B';
    for(int i = 0; i < t; i++) cout << 'S';
    for(int i = 1; i <= n; i++) cout << i;
    cout << endl;

    return 0;
}
