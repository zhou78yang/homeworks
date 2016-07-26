#include <iostream>
#include <cstring>

using namespace std;

#define N   25

char map[N][N];

int brick(int x, int y)
{
    if(map[x][y] == '.' || map[x][y] == '@')
    {
        map[x][y] = '#';    // 避免重复计数
        return 1 + brick(x-1, y) + brick(x, y-1)
            + brick(x+1, y) + brick(x, y+1);
    }
    return 0;
}

int main()
{
    int W, H;
    int x, y;
    while(cin >> W >> H)
    {
        for(int i = 1; i <= H; i++)
        {
            for(int j = 1; j <= W; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == '@')
                {
                    x = i; y = j;
                }
            }
        }
        cout << brick(x, y) << endl;
    }
    return 0;
}

