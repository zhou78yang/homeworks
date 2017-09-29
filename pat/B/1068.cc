#include <iostream>
#include <map>
using namespace std;

#define N   1005

bool sim(int a, int b, int tol)
{
    return a > b+tol || a < b-tol;
}

int main()
{
    int n, m, tol;
    int table[N][N] = {0};
    map<int, int> book;

    cin >> m >> n >> tol;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> table[i][j];
            if(book.find(table[i][j]) != book.end()) book[table[i][j]]++;
            else book.insert(pair<int, int>(table[i][j], 1));
        }
    }
    for(int i = 0; i <= m+1; i++) table[0][i] = table[n+1][i] = -200;
    for(int i = 0; i <= n+1; i++) table[i][0] = table[i][m+1] = -200;

    int count = 0, x, y;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(book[table[i][j]] == 1)
            {
                if(sim(table[i][j], table[i-1][j-1], tol) && sim(table[i][j], table[i-1][j], tol)
                && sim(table[i][j], table[i-1][j+1], tol) && sim(table[i][j], table[i][j-1], tol)
                && sim(table[i][j], table[i][j+1], tol) && sim(table[i][j], table[i+1][j-1], tol)
                && sim(table[i][j], table[i+1][j], tol) && sim(table[i][j], table[i+1][j+1], tol))
                {
                    x = i; y = j;
                    count++;
                }
            }
        }
    }
    
    if(count == 1) printf("(%d, %d): %d\n", y, x, table[x][y]);
    else if(count == 0) cout << "Not Exist\n";
    else cout << "Not Unique\n";

    return 0;
}
