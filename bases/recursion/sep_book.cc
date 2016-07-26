#include <iostream>
#include <cstring>
using namespace std;

#define N   1005

int map[N][N];
int ans[N], n;
bool vis[N];

bool search(int m)
{
    if(n == m) return true;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i] && map[m][i])
        {
            ans[m] = i + 1;
            vis[i] = true;
            if(search(m+1)) return true;
            vis[i] = 0;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    while(cin >> n)
    {
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        if(search(0))
        {
            for(int i = 0; i < n; i++) 
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
