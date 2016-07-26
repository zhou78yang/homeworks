#include <iostream>
using namespace std;

int main()
{
    int n, m, map[1005][1005];

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int j = m; j > 0; j--)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
