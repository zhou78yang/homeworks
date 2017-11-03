#include <iostream>
#include <cstring>
using namespace std;

void get_next(char *f, int *next, int n)
{
    int i = 0, j;
    j = next[0] = -1;
    while(i < n)
    {
        while(j != -1 && f[i] != f[j]) j = next[j];
        next[++i] = ++j;
    }
}

int kmp(char *T, char *F, int *next)
{
    int count = 0;
    int i = 0, j = 0, n = strlen(T), m = strlen(F);
    while(i < n)
    {
        while(j != -1 && T[i] != F[j]) j = next[j];
        ++i; ++j;
        if(j == m)
        {
            count++;
            j = next[j];
        }
    }
    return count;
}

int main()
{
    int T;
    char f[10005], t[1000005];
    int next[10005];

    cin >> T;
    while(T-- > 0)
    {
        scanf("%s%s", f, t);
        get_next(f, next, strlen(f));
        cout << kmp(t, f, next) << endl;
    }

    return 0;
}

