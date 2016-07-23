#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char c;
    int n, l = 1, r;   // n: 总数, l: 层数, r: 剩余数

    cin >> n >> c;

    while(2*l*l-1 <= n) l++;
    l -= 1;
    r = n + 1 - 2 * l * l;

    for(int i = l; i > 0; i--)
    {
        for(int j = 0; j < l-i; j++) cout << " ";
        for(int j = 0; j < 2*i-1; j++) cout << c;
        cout << endl;
    }
    for(int i = 2; i <= l; i++)
    {
        for(int j = 0; j < l-i; j++) cout << " ";
        for(int j = 0; j < 2*i-1; j++) cout << c;
        cout << endl;
    }
    cout << r << endl;

    return 0;
}
    
