#include <iostream>
using namespace std;

int main()
{
    int n;
    char c;

    cin >> n >> c;

    for(int i = 1; i <= n; i+=2)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

