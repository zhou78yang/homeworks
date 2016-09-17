#include <iostream>
using namespace std;

#define N   1005
#define M   10005

int n, m;
int u[M], v[M], first[N], nxt[M];
int num[N], low[N], index = 0;

void dfs(int cur, int father)
{
    num[cur] = ++index;
    low[cur] = index;

    for(int i = first[cur]; i != -1; i = nxt[i])
    {
        if(num[v[i]] == 0)
        {
            dfs(v[i], cur);
        }
        low[cur] = min(low[cur], low[v[i]]);
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
    }
            
    dfs(1, 1);
    /*
     * DEBUG
    cout << "num : ";
    for(int i = 1; i <= n; i++) cout << num[i] << " ";
    cout << endl;
    cout << "low : ";
    for(int i = 1; i <= n; i++) cout << low[i] << " ";
    cout << endl;
    */

    int book[N] = {0};
    for(int i = 1; i <= n; i++) book[low[i]]++;

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += book[i] * (book[i]-1) / 2;
    }
    
    cout << sum << endl;
    return 0;
}
