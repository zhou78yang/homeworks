#include <iostream>
using namespace std;

#define INF     -1

int main()
{
    int n, R[1005], S = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> R[i];
    R[0] = R[n+1] = INF;

    for(int i = 1; i <= n; i++)
    {
        int w = 1;
        for(int j = i-1; R[i] <= R[j]; j--)
        {
            w++;
        }
        for(int j = i+1; R[i] <= R[j]; j++)
        {
            w++;
        }
        S = max(S, w*R[i]);
    }

    cout << S << endl;

    return 0;
}

