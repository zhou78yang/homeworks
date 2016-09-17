#include <iostream>
#include <algorithm>
using namespace std;

#define N   1005
#define M   10005
#define INF 9999999

struct Edge {
    int u, v, w;
};
int F[N] = {0};

bool comp(const Edge &a, const Edge &b)
{
    return a.w < b.w ||
          (a.w == b.w && a.u < b.u) ||
          (a.w == b.w && a.u == b.u && a.v < b.v);
}

int getf(int x)
{
    if(F[x] == x) return x;
    F[x] = getf(F[x]);

    return F[x];
}

bool merge(int a, int b)
{
    int t1 = getf(a);
    int t2 = getf(b);
    if(t1 == t2) return false;
    F[t2] = t1;

    return true;
}


int main()
{
    int n, m, sum = 0, count = 0;
    Edge e[M];

    cin >> n >> m;
    for(int i = 1; i <= m; i++) 
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e+1, e+m+1, comp);     // 边排序
    for(int i = 1; i <= n; i++) F[i] = i;   // 初始化并查集

    for(int i = 1; i <= m && count < n-1; i++)
    {
        if(merge(e[i].u, e[i].v))
        {
            sum += e[i].w;
            cout << "include " << e[i].u << "->" << e[i].v << endl;
        }
    }

    cout << "sum : " << sum << endl;

    return 0;
}
