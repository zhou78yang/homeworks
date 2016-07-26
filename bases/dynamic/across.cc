/*
 * 穿过街道
 *      一个城市的街道布局如下：
 *      从最左下方走到最右上方，每次只能向上或向右走，一共有多少种走法
 *      注意：处理边界的时候应该赋值为１
 */

#include <iostream>
#include <cstring>

using namespace std;

#define N 25

int map[N][N];

int getWays(int x, int y)
{
    if(map[x][y] > 0) return map[x][y];
    if(0 == x || 0 == y) map[x][y] = 1;
    else map[x][y] = getWays(x-1, y) + getWays(x, y-1);
    return map[x][y];
}


int main(int argc, char *argv[])
{
    int x, y;
    memset(map, 0, sizeof(map));

    for(int i = 0; i < N; i++)
    {
        map[0][i] = map[i][0] = 1;
    }

    while(cin >> x >> y)
    {
        cout << getWays(x, y) << endl;
    }

    return 0;
}

