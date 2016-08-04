#include <iostream>
using namespace std;

#define N   1005

int map[N][N] = {0};

void traver(int n)
{
    int r = 1, c = 1, nr, nc;   // nextR, nextC
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
            nr = r+1; nc = c-1;
        }
        else
        {
            nr = r-1; nc = c+1;
        }

        if(nr < 1 || nr > n)
        {
            if(c < n) c++;
            else r++;
            southwest = !southwest;
        }
        else if(nc < 1 || nc > n)
        {
            if(r < n) r++;
            else c++;
            southwest = !southwest;
        }
        else
        {
            r = nr; c = nc;
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
    
