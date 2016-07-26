#include <iostream>
#include <cstring>

using namespace std;

char map[10][10];
bool vis[10][10];
const int dir[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
struct queue
{
    int x, y;
    int pre;
} list[100];

bool go(int x, int y)
{
    if(x < 1 || y < 1 || x > 5 || y > 5) return false;
    if(vis[x][y] || map[x][y] == '#') return false;
    return true;
}

void print(int n)
{
    if(n < 0) return;
    print(list[n].pre);
    cout << "( " << list[n].x << " , " << list[n].y << " )" << endl;
}

void bfs()
{
    int head = 0;
    int tail = 1;
    list[head].x = list[head].y = 1;
    list[head].pre = -1;

    while(head < tail)
    {
        if(list[head].x == 5 && list[head].y == 5)
        {
            print(head);
            break;
        }
        int x = list[head].x;
        int y = list[head].y;
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(go(xx, yy))
            {
                vis[xx][yy] = true;
                list[tail].x = xx;
                list[tail].y = yy;
                list[tail].pre = head;
                tail++;
            }
        }
        head++;
    }

}


int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> map[i][j];
        }
    }
    bfs();

    return 0;
}
