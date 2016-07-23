#include <iostream>
using namespace std;

int main()
{
    int N = 1, n, sum = 0;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        N *= i;
        sum += N;
    }
    cout << sum << endl;

    return 0;
}

