#include <iostream>
#include <algorithm>
using namespace std;

#define N   100005

int main()
{
    int n, p, A[N], P, max = 0;

    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A, A+n);

	int j = 1;
    for(int i = 0; i < n; i++)
    {
        P = A[i] * p;
        if(P < 0)
		{
			max = max > n - i ? max : n-i;
			break;
		}
        while(A[j] <= P && j < n) j++;
        if(max < j-i) max = j-i;
    }
    cout << max << endl;

    return 0;
}
