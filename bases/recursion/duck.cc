#include <iostream>

using namespace std;

long long duck(int n)
{
    return 0 == n ? 2 : duck(n-1) * 2 + 4;
}

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        cout << duck(n) << endl;
    }
    return 0;
}
