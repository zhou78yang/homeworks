#include <iostream>
using namespace std;

long long fib(int n)
{
    return n < 2 ? 1 : fib(n-1) + fib(n-2);
}

/*
 *  迭代版
long long fib(int n)
{
    int f = 1, g = 1;

    while(n-- > 0)
    {
        f += g;
        g = f - g;
    }
    return g;
}
*/

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        cout << fib(n) << endl;
    }

    return 0;
}
