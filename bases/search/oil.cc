#include <iostream>
#include <cstring>

using namespace std;

#define N 105

int m, n;
char map[N][N];

bool deposits(int i, int j)
{
    if(i < 1 || j < 1 || i > m || j > n) return false;
    if(map[i][j] == '*') return false;
    map[i][j] = '*';
    deposits(i-1, j); deposits(i+1, j);
    deposits(i, j+1); deposits(i, j-1);
    deposits(i-1, j-1); deposits(i+1, j+1);
    deposits(i-1, j+1); deposits(i+1, j-1);
    return true;
}

int main(int argc, char *argv[])
{
    while(cin >> m >> n)
    {
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
            }
        }
        int count = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(deposits(i, j)) count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}


