#include <iostream>
using namespace std;

#define N   1005

int main()
{
    int n, a[N], count = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 2; i < n; i++)
    {
        if( (a[i] > a[i-1] && a[i] > a[i+1]) || 
            (a[i] < a[i-1] && a[i] < a[i+1]))
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

