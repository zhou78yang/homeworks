#include <iostream>
using namespace std;

#define N   35

int main()
{
    int n, m;
    int map[N][N] = {0}, output[N][N];

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            output[i][j] = map[i][j];
        }
    }

    for(int r = 0; r < n; r++)
    {
        int lo = 0;
        while(lo < m)
        {
            int hi = lo + 1;
            while(map[r][lo] == map[r][hi]) hi++;
            if(hi - lo >= 3)
            {
                for(int i = lo; i < hi; i++)
                {
                    output[r][i] = 0;
                }
            }
            lo = hi;
        }
    }
    for(int c = 0; c < m; c++)
    {
        int lo = 0;
        while(lo < n)
        {
            int hi = lo + 1;
            while(map[lo][c] == map[hi][c]) hi++;
            if(hi - lo >= 3)
            {
                for(int i = lo; i < hi; i++)
                {
                    output[i][c] = 0;
                }
            }
            lo = hi;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
            
