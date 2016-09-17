#include <iostream>
using namespace std;

#define N   1005
#define M   10005
#define INF 999999

int dis[N];     // 用来存储最短距离
int heap[N];    // 小顶堆，以dis内容作为排序依据
int pos[N];     // 记录各顶点在堆中的位置
int size;       // 堆的规模

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
        tmp = i * 2;
        if(tmp < size && dis[heap[tmp+1]] < dis[heap[tmp]])
        {
            tmp += 1;
        }

        if(dis[heap[i]] > dis[heap[tmp]])
        {
            swap(i, tmp);
            i = tmp;
        }
        else break;
    }
}

int pop()
{
    int t = heap[1];
    swap(1, size);
    size--;
    siftdown(1);
    
    return t;
}

int main()
{
    int n, m;
    int u[M], v[M], w[M], first[N], next[M];
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) first[i] = -1;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        next[i] = first[u[i]];
        first[u[i]] = i;
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

    // Dijkstra部分: 从∅ 开始添加元素，故需要n次
    for(int k = 1; k <= n; k++)
    {
        int s = pop();      // 获取堆顶元素
        for(int i = first[s]; i != -1; i = next[i])
        {
            if(dis[v[i]] > dis[s] + w[i])
            {
                dis[v[i]] = dis[s] + w[i];
                siftup(pos[v[i]]);  // 松弛后sift up
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;

    return 0;
}
