#include <iostream>

using namespace std;

long long f(int n)
{
    return 0 == n ? 1 : n * f(n-1);
}

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        cout << f(n) << endl;
    }

    return 0;
}
