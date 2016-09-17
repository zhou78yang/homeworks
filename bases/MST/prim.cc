#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 9999999

int main()
{
    int n, m, u, v, w;
    int e[N][N], dis[N];
    int sum = 0;

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
        e[v][u] = w;
    }

    for(int i = 1; i <= n; i++) dis[i] = e[1][i];   // 以1为起点

    // Prim算法:依次录入距离树最近的点，总共n-1个
    for(int k = 1; k <= n-1; k++)
    {
        // 获取距离树最近的点
        int min = INF, p;
        for(int i = 1; i <= n; i++)
        {
            if(dis[i] && dis[i] < min)
            {
                min = dis[i];
                p = i;
            }
        }
        sum += dis[p];
        cout << "include the point " << p << endl;
        dis[p] = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dis[i] > e[p][i])
            {
                dis[i] = e[p][i];
            }
        }
    }

    cout << "sum : " << sum << endl;

    return 0;
}

