#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 99999999

int main()
{
    int n, m, u, v, w;
    int e[N][N], dis[N];
    bool book[N] = {0};

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

    for(int i = 1; i <= n; i++) dis[i] = e[1][i];

    // Dijkstra算法:通过最近点松弛图
    book[1] = true;
    for(int k = 1; k <= n-1; k++)
    {
        int min = INF, s;
        for(int i = 1; i <= n; i++)
        {
            if(!book[i] && min > dis[i])
            {
                min = dis[i];
                s = i;
            }
        }

        book[s] = true;
        for(int i = 1; i <= n; i++)
        {
            if(dis[i] > dis[s] + e[s][i])
            {
                dis[i] = dis[s] + e[s][i];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}

