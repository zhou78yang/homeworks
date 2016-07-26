#include <iostream>
#include <cstring>
using namespace std;

#define N 25

int m, n;
char map[N][N];
bool vis[N][N];
int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct queue
{
    int x, y;
} list[N*N];

bool go(int i, int j)
{
    if(i < 1 || j < 1 || i > m || j > n) return false;
    if(map[i][j] == '#' || vis[i][j]) return false;
    return true;
}

int bfs(int i, int j)
{
    int head = 0, tail = 1;
    int count = 1;
    list[head].x = i; list[head].y = j;
    vis[i][j] = true;

    while(head < tail)
    {
        for(int i = 0; i < 4; i++)
        {
            int x = list[head].x + dir[i][0];
            int y = list[head].y + dir[i][1];
            if(go(x, y))
            {
                list[tail].x = x;
                list[tail].y = y;
                vis[x][y] = true;
                tail++;
                count++;
            }
        }
        head++;
    }
    return count;
}

int main()
{
    while(cin >> m >> n)
    {
        int x, y;
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        cout << bfs(x, y) << endl;
    }

    return 0;
}

           
    
