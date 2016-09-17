#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 99999999

int dis[N], heap[N], pos[N], size;

void swap(int a, int b)
{
    int t = heap[a];
    heap[a] = heap[b];
    heap[b] = t;

    t = pos[heap[a]];
    pos[heap[a]] = pos[heap[b]];
    pos[heap[b]] = t;
}

void siftup(int i)
{
    while(i && dis[heap[i]] < dis[heap[i/2]])
    {
        swap(i, i/2);
        i /= 2;
    }
}

void siftdown(int i)
{
    int tmp;
    while(i <= size/2)
    {
        tmp = i*2;
        if(tmp < size && dis[heap[tmp]] > dis[heap[tmp+1]])
        {
            tmp += 1;
        }

        if(dis[heap[i]] > dis[heap[tmp]])
        {
            swap(i, tmp);
            i = tmp;
        }
        else break;             // 注意
    }
}

int pop()
{
    int t = heap[1];
    swap(1, size--);
    siftdown(1);

    return t;
}

int main()
{
    int n, m, sum = 0;
    int u[M], v[M], w[M], first[N], next[M];

    cin >> n >> m;
    for(int i = 1; i <= n; i++) first[i] = -1;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        next[i] = first[u[i]];
        first[u[i]] = i;

        // 无向图，需要录入反向边
        u[i+m] = v[i];
        v[i+m] = u[i];
        w[i+m] = w[i];
        next[i+m] = first[v[i]];
        first[v[i]] = i+m;
    }

    // 初始化堆
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        heap[i] = i;
        pos[i] = i;
    }
    dis[1] = 0;
    size = n;

    // Prim算法: 依次添加树的n个结点
    for(int k = 1; k <= n; k++)
    {
        int p = pop();              // 总计O(nlogn)

        cout << "include the point " << p 
             << " and sum add " << dis[p] << endl;
        sum += dis[p];
        dis[p] = 0;
        for(int i = first[p]; i != -1; i = next[i])
        {
            if(dis[v[i]] > w[i])
            {
                dis[v[i]] = w[i];
                siftup(pos[v[i]]);  // 总计O(mlogn)
            }
        }
    }

    cout << "sum : " << sum << endl;

    return 0;
}
    
