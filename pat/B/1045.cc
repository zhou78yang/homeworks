#include <iostream>
#include <algorithm>
using namespace std;

#define N       100005
#define MIN     -1
#define MAX     1000000005

int main()
{
    int n, A[N], left[N], right[N];

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];

    left[0] = MIN;
    right[n+1] = MAX;
    for(int i = 1; i <= n; i++) left[i] = A[i] > left[i-1] ? A[i] : left[i-1];
    for(int i = n; i > 0; i--) right[i] = A[i] < right[i+1] ? A[i] : right[i+1];

    int len, book[N];
    for(int i = 1; i <= n; i++)
    {
        if(A[i] > left[i-1] && A[i] < right[i+1])
        {
            book[len++] = A[i];
        }
    }

    if(len == 0) cout << "0\n\n";
    else
    {
        cout << len << endl << book[0];
        for(int i = 1; i < len; i++) cout << " " << book[i];
        cout << endl;
    }

    return 0;
}
