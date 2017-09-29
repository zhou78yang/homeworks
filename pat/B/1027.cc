#include <iostream>
using namespace std;

int main()
{
    int n, x = 1;
    char ch;

    cin >> n >> ch;
    while(2*x*x-1 <= n) x++;
    x--;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = 0; j < 2*(x-i)-1; j++) cout << ch;
        cout << endl;
    }
    for(int i = x-2; i >= 0; i--)
    {
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = 0; j < 2*(x-i)-1; j++) cout << ch;
        cout << endl;
    }
    cout << n-2*x*x+1 << endl;

    return 0;
}
    
