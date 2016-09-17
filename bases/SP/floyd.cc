#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 99999999

int main()
{
    int n, m, u, v, w;
    int e[N][N]; 

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            e[i][j] = i == j ? 0 : INF;
        }
    }
    
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        e[u][v] = w;
    }

    // Floyd核心算法:k为中间点，更新全图
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(e[i][j] > e[i][k] + e[k][j])
                {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << e[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
