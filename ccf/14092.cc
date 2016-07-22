#include <iostream>
#include <cstring>
using namespace std;

bool vis[105][105];

int main()
{
    int n;
    int x1, x2, y1, y2;
    int count = 0;

    memset(vis, 0, sizeof(vis));

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++)
        {
            for(int j = x1; j < x2; j++)
            {
                if(!vis[i][j])
                {
                    vis[i][j] = true;
                    count++;
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}
