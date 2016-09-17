#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 99999999

int main()
{
    int n, m;
    int u[M], v[M], w[M], first[N], next[M];
    int dis[N];
    bool book[N] = {0};

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
        for(int i = first[s]; i != -1; i = next[i])
        {
            if(dis[v[i]] > dis[s] + w[i])
            {
                dis[v[i]] = dis[s] + w[i];
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;

    return 0;
}
