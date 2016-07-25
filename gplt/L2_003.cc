#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N   1005

struct Cake {
    double w, v;
} C[N];

bool comp(Cake a, Cake b)
{
    return a.v * b.w > b.v * a.w;
}

int main()
{
    int n, d;

    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> C[i].w;
    for(int i = 0; i < n; i++) cin >> C[i].v;

    sort(C, C+n, comp);

    double sum = 0, rest = d;
    for(int i = 0; i < n; i++)
    {
        if(C[i].w <= rest)
        {
            sum += C[i].v;
            rest -= C[i].w;
        }
        else
        {
            sum += C[i].v / C[i].w * rest;
            break;
        }
    }
    printf("%.2lf\n", sum);

    return 0;
}

