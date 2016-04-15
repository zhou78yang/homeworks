#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char c;
    while(cin >> c)
    {
        for(int i = 7; i >= 0; i--)
        {
            cout << int((c>>i)&1);
        }
        cout << endl;
    }
    return 0;
}
