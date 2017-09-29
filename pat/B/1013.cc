#include <iostream>
#include <cstdio>
using namespace std;

int primers[10005] = {0};
int len = 0;

bool isPrimer(int x)
{
    for(int i = 1; i <= len && primers[i]*primers[i] <= x; i++)
    {
        if(x % primers[i] == 0) return false;
    }
    primers[++len] = x;
    return true;
}

int main()
{
    int n, m, x = 3;
    cin >> n >> m;

    primers[++len] = 2;
    while(len < m)
    {
        isPrimer(x);
        x += 2;
    }

    int count = 0;
    while(m > n)
    {
        printf("%d", primers[n++]);
        if(++count % 10) printf(" ");
        else printf("\n");
    }
    printf("%d\n", primers[m]);

    return 0;
}

