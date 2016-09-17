#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 9999999

int main()
{
    int n, m;
    int u[M], v[M], w[M], first[N], next[M];
    int dis[N];
   
    cin >> n >> m;
    for(int i = 1; i <= n; i++) first[i] = -1;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0;

    // 至多需要n-1次松弛
    for(int k = 1; k <= n-1; k++)
    {
        bool flag = true;   // 标记，若不再松弛则退出

        for(int i = 1; i <= m; i++)
        {
            if(dis[v[i]] > dis[u[i]] + w[i])
            {
                dis[v[i]] = dis[u[i]] + w[i];
                flag = false;
            }
        }

        if(flag) break;
    }

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;

    return 0;
}
