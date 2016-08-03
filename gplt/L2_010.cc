#include <iostream>
using namespace std;

#define N       105

int F[N];
bool E[N][N] = {0};

int getF(int x)
{
    if(F[x] == x) return x;

    F[x] = getF(F[x]);
    return F[x];
}

void merge(int a, int b)
{
    int fa = getF(a);
    int fb = getF(b);

    if(fa < fb) F[fb] = fa;
    else F[fa] = fb;
}

int main()
{
    int n, m, k;

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) F[i] = i;

    int a, b, r;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> r;
        if(r == 1) merge(a, b);
        else E[a][b] = E[b][a] = true;
    }

    for(int i = 0; i < k; i++)
    {
        cin >> a >> b;
        if(getF(a) == getF(b))
        {
            if(!E[a][b]) cout << "No problem" << endl;
            else cout << "OK but..." << endl;
        }
        else
        {
            if(!E[a][b]) cout << "OK" << endl;
            else cout << "No way" << endl;
        }
    }

    return 0;
}
