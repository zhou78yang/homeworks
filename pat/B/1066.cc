#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, a, b, replay;
    int R[500][500];
    cin >> n >> m >> a >> b >> replay;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> R[i][j];
            if(R[i][j] >= a && R[i][j] <= b)
            {
                R[i][j] = replay;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%03d", R[i][0]);
        for(int j = 1; j < m; j++)
        {
            printf(" %03d", R[i][j]);
        }
        cout << endl;
    }

    return 0;
}
