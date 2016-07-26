/*
 * fibonacci数列
 *      计算斐波那契数列的值
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    long long fib[55];
    fib[1] = fib[2] = 1;

    for(int i = 3; i <= 50; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    while(cin >> n)
    {
        cout << fib[n] << endl;
    }

    return 0;
}
    
