#include <iostream>
using namespace std;

#define N   1005

int map[N][N] = {0};

void traver(int n)
{
    int r = 1, c = 1, dr, dc;
    bool southwest = false;

    while(true)
    {
        cout << map[r][c] << " ";
        if(r == n && c == n)
        {
            break;
        }

        if(southwest)
        {
            dr = 1; dc = -1;
        }
        else
        {
            dr = -1; dc = 1;
        }

        r += dr; c += dc;
        if(r < 1 || r > n)
        {
            r -= dr; c -= dc;
            if(c < n) c++;
            else r++;
            southwest = !southwest;
        }
        if(c < 1 || c > n)
        {
            r -= dr; c -= dc;
            if(r < n) r++;
            else c++;
            southwest = !southwest;
        }
    }
    cout << endl;
}

int main()
{
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    traver(n);

    return 0;
}
    
