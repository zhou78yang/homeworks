#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define N   10000

int host[N], house[N] = {0};
double space[N] = {0};

void init()
{
    for(int i = 0; i < N; i++) host[i] = i;
}

int getH(int x)
{
    if(host[x] == x) return x;

    host[x] = getH(host[x]);
    return host[x];
}

void merge(int a, int b)
{
    if(a == -1 || b == -1) return ;

    int h1 = getH(a), h2 = getH(b);

    if(h1 == h2) return ;
    else if(h1 < h2)
    {
        host[h2] = h1;
        house[h1] += house[h2];
        space[h1] += space[h2];
    }
    else
    {
        host[h1] = h2;
        house[h2] += house[h1];
        space[h2] += space[h1];
    }
}

struct Family {
    int h_id, member;
} F[N];

bool comp(const Family &a, const Family &b)
{
    int x1 = a.h_id, x2 = b.h_id;
    double s1 = space[x1] / a.member;
    double s2 = space[x2] / b.member;

    return s1 > s2 || (s1 == s2 && x1 < x2);
}

int main()
{
    int n, id, f_id, m_id, k, k_id, h;
    double s;

    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id >> f_id >> m_id >> k;
        merge(id, f_id);
        merge(id, m_id);
        
        for(int j = 0; j < k; j++)
        {
            cin >> k_id;
            merge(id, k_id);
        }

        cin >> h >> s;
        id = getH(id);
        house[id] += h;
        space[id] += s;
    }

    int member[N] = {0};
    int len = 0;
    for(int i = 0; i < N; i++)
    {
        id = getH(i);
        member[id]++;
        if(id == i && house[id] > 0)
        {
            F[len++].h_id = id;
        }
    }

    for(int i = 0; i < len; i++)
    {
        id = F[i].h_id;
        F[i].member = member[id];
    }

    sort(F, F+len, comp);

    cout << len << endl;
    for(int i = 0; i < len; i++)
    {
        id = F[i].h_id;
        printf("%04d %d %.3lf %.3lf\n", id, member[id],
                    (double)house[id]/member[id], 
                    space[id]/member[id]);
    }

    return 0;
}
