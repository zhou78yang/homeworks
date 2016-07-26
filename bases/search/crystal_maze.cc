#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

#define N   505

char map[N][N];
bool vis[N][N];
int m, n;

int f(int x, int y)
{
    if(x < 1 || y < 1 || x > m || y > n) return 0;
    if(vis[x][y] == true || map[x][y] == '#') return 0;
    vis[x][y] = true;
    int path = f(x-1, y) + f(x+1, y) + f(x, y-1) + f(x, y+1);
    if(map[x][y] == 'C') path++;
    return path;
}

int main()
{
    int T;
    int start = clock();
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int q;
        cin >> m >> n >> q;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
            }
        }
        int x, y;
        cout << "Case " << i+1 << ":" << endl;
        for(int i = 0; i < q; i++)
        {
            cin >> x >> y;
            memset(vis, 0, sizeof(vis));
            cout << f(x, y) << endl;
        }
    }

    cout << "time: " << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}


