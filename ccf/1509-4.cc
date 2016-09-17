#include <iostream>
using namespace std;

#define N   10005
#define M   100005

int u[M], v[M], first[N], nxt[M];       // 邻接表
int num[N], low[N], index = 0;          // 时间戳，最小到达值
int stack[N], top = 0;                  // 栈
bool book[N] = {0};                     // 记录结点是否入栈
int answer = 0;

void dfs(int cur)
{
    ++index;
    num[cur] = index;
    low[cur] = index;
    stack[top++] = cur;
    book[cur] = true;

    for(int i = first[cur]; i != -1; i = nxt[i])
    {
        if(num[v[i]] == 0)
        {
            dfs(v[i]);
            low[cur] = min(low[cur], low[v[i]]);
        }
        else if(book[v[i]])
        {
            low[cur] = min(low[cur], num[v[i]]);
        }
    }

    if(low[cur] == num[cur])
    {
        // 找到一个强连通分量的起点
        int cnt = 0, j;
        do
        {
            j = stack[--top];
            book[j] = false;
            cnt++;
        }while(top > 0 && cur != j);
    
        answer += cnt * (cnt-1) / 2;
    }
}

int main()
{
    int n, m;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) first[i] = -1;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        nxt[i] = first[u[i]];
        first[u[i]] = i;
    }

    dfs(1);

    cout << answer << endl;

    return 0;
}

