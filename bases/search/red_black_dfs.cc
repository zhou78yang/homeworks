#include <iostream>
#include <cstring>

using namespace std;

#define N 25

int m, n;
char map[N][N];

int dfs(int i, int j)
{
    if(i < 1 || j < 1 || i > m || j > n) return 0;
    if(map[i][j] == '#') return 0;
    map[i][j] = '#';
    return 1 + dfs(i-1, j) + dfs(i+1, j) + dfs(i, j-1) + dfs(i, j+1);
}


int main(int argc, char *argv[])
{
    while(cin >> m >> n)
    {
        int x, y;
        for(int i = 1; i <= m; i++)
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

        cout << dfs(x, y) << endl;
    }
    return 0;
}
