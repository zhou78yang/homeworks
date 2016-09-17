#include <iostream>
using namespace std;

#define N   1005
#define M   10005

int n, m;
int u[M], v[M], first[N], nxt[M];
int num[N], low[N], index = 0;
bool book[N] = {0};

void dfs(int cur, int father)
{
    num[cur] = ++index;
    low[cur] = index;

    for(int i = first[cur]; i != -1; i = nxt[i])
    {
        if(num[v[i]] == 0)
        {
            dfs(v[i], cur);
            low[cur] = min(low[cur], low[v[i]]);

            if(low[v[i]] > num[cur])
            {
                cout << cur << "-" << v[i] << " 是割边" << endl;
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

        u[i+m] = v[i];
        v[i+m] = u[i];
        nxt[i+m] = first[v[i]];
        first[v[i]] = i+m;
    }

    dfs(1, 1);

    return 0;
}
