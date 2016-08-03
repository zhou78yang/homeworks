#include <iostream>
using namespace std;

#define N   505
#define M   5005

int u[M], v[M], set[N];
bool lost[N] = {0};

void init(int n)
{
    for(int i = 0; i < n; i++) set[i] = i;
}

int getf(int x)
{
    if(x == set[x]) return x;
    set[x] = getf(set[x]);

    return set[x];
}

void merge(int a, int b)
{
    int fa = getf(a);
    int fb = getf(b);

    if(fa < fb) set[fb] = fa;
    else set[fa] = fb;
}

int getBlock(int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!lost[i] && i == getf(i)) count++;
    }

    return count;
}


int main()
{
    int n, m, k;

    cin >> n >> m;
    init(n);
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        merge(u[i], v[i]);
    }

    int sum = getBlock(n);

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int id;

        cin >> id;
        lost[id] = true;
        init(n);

        for(int i = 1; i <= m; i++)
        {
            if(!lost[u[i]] && !lost[v[i]])
            {
                merge(u[i], v[i]);
            }
        }

        int count = getBlock(n);

        if(count > sum)
        {
            cout << "Red Alert: City " << id << " is lost!" << endl;
        }
        else
        {
            cout << "City " << id << " is lost." << endl;
        }
        sum = count;
    }
    if(k == n) cout << "Game Over." << endl;

    return 0;
}
