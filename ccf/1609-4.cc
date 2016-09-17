#include <iostream>
using namespace std;

#define N   10005
#define M   200005
#define INF 99999999

struct Edge {
    int u, v, w;
    int next;
};

int main()
{
    int n, m;
    Edge e[M];
    int first[N], dis[N], pre[N] = {0};
    bool book[N] = {0};

    cin >> n >> m;
    for(int i = 1; i <= n; i++) first[i] = -1;
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].next = first[e[i].u];
        first[e[i].u] = i;

        e[i+m].u = e[i].v;
        e[i+m].v = e[i].u;
        e[i+m].w = e[i].w;
        e[i+m].next = first[e[i].v];
        first[e[i].v] = i+m;
    }

    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0;

    for(int k = 1; k <= n; k++)
    {
        int min = INF, j;
        for(int i = 1; i <= n; i++)
        {
            if(!book[i] && min > dis[i])
            {
                min = dis[i];
                j = i;
            }
        }

        book[j] = true;
        for(int i = first[j]; i != -1; i = e[i].next)
        {
            if(dis[e[i].v] >= dis[j] + e[i].w)
            {
                dis[e[i].v] = dis[j] + e[i].w;
                pre[e[i].v] = j;
            }
        }
    }

#ifdef DEBUG
    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;
#endif

    int sum = 0;
    for(int i = 1; i <= n; i++) book[i] = false;
    for(int i = n; i > 0; i--)
    {
        if(!book[i])
        {
            sum += dis[i];
            for(int j = i; j > 1; j = pre[j])
            {
                book[j] = true;
#ifdef DEBUG
                cout << "include " << j << endl;
#endif
            }
        }
    }

    cout << sum << endl;

    return 0;
}

