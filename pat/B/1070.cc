#include <iostream>
#include <algorithm>
using namespace std;

#define N   10005

int main()
{
    int n, A[N];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A, A+n);

    double cur = A[0];
    for(int i = 1; i < n; i++)
    {
        cur += A[i];
        cur /= 2;
    }

    cout << (int)cur << endl;

    return 0;
}

