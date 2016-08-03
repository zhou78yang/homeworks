#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N   1005

int F[N] = {0}, C[N] = {0};

int getF(int x)
{
    if(x == F[x]) return x;
    F[x] = getF(F[x]);
    return F[x];
}

void merge(int a, int b)
{
    int f1 = getF(a);
    int f2 = getF(b);

    if(f1 == f2) return ;
    else if(f1 < f2)
    {
        F[f2] = f1;
        C[f1] += C[f2];
        C[f2] = 0;
    }
    else
    {
        F[f1] = f2;
        C[f2] += C[f1];
        C[f1] = 0;
    }
}

void init()
{
    for(int i = 1; i <= N; i++) F[i] = i;
}

int main()
{
    int n, k, x, y;

    cin >> n;
    init();
    for(int i = 1; i <= n; i++)
    {
        scanf("%d: %d", &k, &x);
        for(int j = 1; j < k; j++)
        {
            cin >> y;
            merge(x, y);
        }
        C[getF(x)] += 1;
    }

    int club[N], len = 0;
    for(int i = 1; i <= 1000; i++)
    {
        if(C[i] && i == getF(i))
        {
            club[len++] = C[i];
        }
    }

    sort(club, club+len);
    cout << len << endl;
    for(int i = len-1; i > 0; i--)
    {
        cout << club[i] << " ";
    }
    cout << club[0] << endl;

    return 0;
}

    
