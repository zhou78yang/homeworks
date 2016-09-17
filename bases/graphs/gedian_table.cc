#include <iostream>
#include <algorithm>
using namespace std;

#define N   1005
#define M   10005

int n, m;
int u[M], v[M], first[N], nxt[M];
int num[N], low[N], index = 0, root;    
bool book[N] = {0};             // 记录是否为割点

void dfs(int cur, int father)
{
    int child = 0;

    num[cur] = ++index;
    low[cur] = index;

    for(int i = first[cur]; i != -1; i = nxt[i])
    {
        if(num[v[i]] == 0)      // v[i]没有被访问过
        {
            child++;            // 增加一个子结点

            dfs(v[i], cur);
            low[cur] = min(low[cur], low[v[i]]);

            if(cur != root && low[v[i]] >= num[cur])
            {
                book[cur] = true;
            }
            if(cur == root && child == 2)
            {
                book[cur] = true;
            }
        }
        else if(v[i] != father)
        {
            low[cur] = min(low[cur], num[v[i]]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) first[i] = -1;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        nxt[i] = first[u[i]];
        first[u[i]] = i;

        // 注意: 无向图需要录入对边
        u[i+m] = v[i];
        v[i+m] = u[i];
        nxt[i+m] = first[v[i]];
        first[v[i]] = i+m;
    }

    root = 1;
    dfs(1, 1);

    for(int i = 1; i <= n; i++)
    {
        if(book[i])
        {
            cout << i << " 是割点" << endl;
        }
    }

    return 0;
}

