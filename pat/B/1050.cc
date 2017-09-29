#include <iostream>
#include <algorithm>
using namespace std;

int T, n, m, A[100005], map[505][505] = {0};
int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, cur = 0;

void moveTo(int x, int y, int index)
{
    map[x][y] = A[index];
    int xx = x + direct[cur][0];
    int yy = y + direct[cur][1];

    int count = 0;
    while(xx < 1 || xx > m || yy < 1 || yy > n || map[xx][yy] != 0)
    {
        cur = (cur+1)%4;
        xx = x + direct[cur][0];
        yy = y + direct[cur][1];
        if(map[xx][yy] == 0) break;
        if(++count == 4) break;
    }

    if(index < T-1) moveTo(xx, yy, index+1);
}

int lt(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> T;
    for(int i = 0; i < T; i++) cin >> A[i];
    n = 1; m = T / n;
    for(int i = n + 1; i * i <= T; i++)
    {
        if(T % i == 0)
        {
            n = i; m = T / i;
        }
    }

    sort(A, A+T, lt);
    moveTo(1, 1, 0);

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j < n; j++) cout << map[i][j] << " ";
        cout << map[i][n] << endl;
    }

    return 0;
}

