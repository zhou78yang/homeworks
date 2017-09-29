#include <iostream>
using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;

    for(int i = 0; i < n; i++) cout << ch;
    cout << endl;
    for(int i = 4; i < n; i += 2)
    {
        cout << ch;
        for(int i = 2; i < n; i++) cout << " ";
        cout << ch << endl;
    }
    for(int i = 0; i < n; i++) cout << ch;
    cout << endl;

    return 0;
}
