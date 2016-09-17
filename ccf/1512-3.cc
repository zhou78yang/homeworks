#include <iostream>
using namespace std;

#define N   1000
int c, r, q;
char map[N][N];
bool book[N][N];
const int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void drawline(int x1, int y1, int x2, int y2)
{
    if(x1 == x2)
    {
        // draw '|'
        if(y1 > y2) swap(y1, y2);
        for(int i = y1; i <= y2; i++)
        {
            if(map[i][x1] == '+' || map[i][x1] == '-') map[i][x1] = '+';
            else map[i][x1] = '|';
        }
    }
    else
    {
        // draw '-'
        if(x1 > x2) swap(x1, x2);
        for(int i = x1; i <= x2; i++)
        {
            if(map[y1][i] == '+' || map[y1][i] == '|') map[y1][i] = '+';
            else map[y1][i] = '-';
        }
    }
}

void print(int x, int y, char ch)
{
    if(x < 0 || y < 0 || x >= c || y >= r) return ;
    if(book[y][x] || map[y][x] == '-' || map[y][x] == '|' || map[y][x] == '+') return ;

    map[y][x] = ch;
    book[y][x] = true;
    for(int i = 0; i < 4; i++)
    {
        print(x+dire[i][0], y+dire[i][1], ch);
    }
}


        
int main()
{
    cin >> c >> r >> q;

    for(int i = 0; i <= r; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            map[i][j] = '.';
        }
    }

    for(int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            for(int i = 0; i <= r; i++)
            {
                for(int j = 0; j <= c; j++)
                {
                    book[i][j] = false;
                }
            }
            int x, y;
            char ch;
            cin >> x >> y >> ch;
            print(x, y, ch);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            drawline(x1, y1, x2, y2);
        }
    }

    for(int i = r-1; i >= 0; i--)
    {
        for(int j = 0; j < c; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}
