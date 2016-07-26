/*
 * 滑雪
 *      输入：输入第一行表示区域的行数Ｒ和列数Ｃ（1 <= R, C <= 100)．
 *      下面是R行，每行有C个整数，代表高度h，０<=h<= 10000
 *      输出：最长能够滑过的区域
 */

#include <iostream>
#include <cstring>

using namespace std;

#define N 105
int R, C;
int map[N][N];
int way[N][N];

int f(int r, int c)
{
    if(r < 1 || c < 1 || r > R || c > C) return 0;
    if(way[r][c] > 0) return way[r][c];
    
    int left, right, up, down;
    left = right = up = down = 0;
    if(c > 1 && map[r][c] > map[r][c-1]) left = f(r, c-1);
    if(c < C && map[r][c] > map[r][c+1]) right = f(r, c+1);
    if(r > 1 && map[r][c] > map[r-1][c]) up = f(r-1, c);
    if(r < R && map[r][c] > map[r+1][c]) down = f(r+1, c);

    int max = left > right ? left : right;
    max = max > up ? max : up;
    max = max > down ? max : down;

    way[r][c] = max + 1;
    return way[r][c];
}

int main(int argc, char *argv[])
{
    cin >> R >> C;
    memset(way, 0, sizeof(way));

    for(int i = 1; i <= R; i++)
    {
        for(int j = 1;j <= C; j++)
        {
            cin >> map[i][j];
        }
    }
    int max = 0;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(max < f(i, j)) max = f(i,j);
        }
    }
    cout << max << endl;

    return 0;
}

