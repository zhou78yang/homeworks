#include <iostream>
using namespace std;

#define N 505
int arr[N][N];

int main()
{
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int r = 1, c = 1;

    while(r <= n && c <= n)
    {
        // 右上至左下
        if(r == 1 || c == n)
        {
            while(1)
            {
                cout << arr[r][c] << " " ;
                if(c == 1 || r == n) break;
                r++; c--;
            }
        }
        // 左下至右上
        else
        {
            while(1)
            {
                cout << arr[r][c] << " ";
                if(r == 1 || c == n) break;
                r--; c++;
            }
        }
        if(r == 1 || r == n) c++;
        else r++;
    }
    cout << endl;
    return 0;
}

           




