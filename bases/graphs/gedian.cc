#include <iostream>
using namespace std;

#define N   1005

int n, m, root;
int num[N], low[N], index = 0;
bool book[N] = {0}, e[N][N] = {0};

void dfs(int cur, int father)
{
    int child = 0;

    book[cur] = true;
    num[cur] = ++index;
    low[cur] = index;
    for(int i = 1; i <= n; i++)
    {
        if(e[cur][i])
        {
            if(!book[i])
            {
                child++;
                dfs(i, cur);
                low[cur] = min(low[cur], low[i]);
                if(cur != root && low[i] >= num[cur])
                {
                    cout << cur << " is gedian" << endl;
                }
                if(cur == root && child == 2)
                {
                    cout << cur << " is gedian" << endl;
                }
            }
            else if(i != father)
            {
                low[cur] = min(low[cur], num[i]);
            }
        }
    }
}

int main()
{
    int u, v;

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        e[u][v] = true;
        e[v][u] = true;
    }

    root = 1;
    dfs(1, 1);

    return 0;
}

