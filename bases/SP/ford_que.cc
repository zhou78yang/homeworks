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

    int que[M], tail = 1;       // 注意队列长度，需要优化
    bool book[N] = {0};
    que[tail++] = 1;
    book[1] = true;
    
    // 优化后的bellman-ford算法，有松弛的边的终点才加入队列
    for(int head = 1; head < tail; head++)
    {
        int s = que[head];
        book[s] = false;
        for(int i = first[s]; i != -1; i = next[i])
        {
            if(dis[v[i]] > dis[s] + w[i])
            {
                dis[v[i]] = dis[s] + w[i];
                if(!book[v[i]]) que[tail++] = v[i];
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;

    return 0;
}

