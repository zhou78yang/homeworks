#include <iostream>
#include <algorithm>
using namespace std;

#define N   10005
#define M   100005
#define INF 999999

int n, m;
bool e[N][N] = {0}, visit[N][N] = {0};
int stack[M], top = 0;

bool dfs(int cur)
{
    if(top > m) return true;

    for(int i = 1; i <= n; i++)
    {
        if(e[cur][i] && !visit[cur][i])
        {
            stack[top++] = i;
            visit[cur][i] = visit[i][cur] = true;
            if(dfs(i)) return true;

            visit[cur][i] = visit[i][cur] = false;
            top--;
        }
    }
    return false;
}

int main()
{
    int u, v;

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        e[u][v] = e[v][u] = true;
    }

    stack[top++] = 1;
    
    if(dfs(1))
    {
        for(int i = 0; i <= m; i++) cout << stack[i] << " ";
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
