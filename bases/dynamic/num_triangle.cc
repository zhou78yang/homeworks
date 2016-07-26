/*
 * 数字三角形
 *      给出一个数字三角形。
 *      从这个三角形的顶部到底部有很多条不同的路径。
 *      对与每条路径，把路径上的数字加起来得到一个和，
 *      求整个三角形中的和最大值
 */

#include <iostream>
#include <cstring>

using namespace std;

#define N   105

int map[N][N];
int sum[N][N];

int main(int argc, char *argv[])
{
    int map[N][N];
    int sum[N][N];
    int n;
    cin >> n;

    memset(sum, 0, sizeof(sum));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> map[i][j];
            if(sum[i-1][j] > sum[i-1][j-1])
            {
                sum[i][j] = map[i][j] + sum[i-1][j];
            }
            else
            {
                sum[i][j] = map[i][j] + sum[i-1][j-1];
            }
        }
    }

    int max = sum[n][1];
    for(int i = 2; i <= n; i++)
    {
        if(max < sum[n][i]) max = sum[n][i];
    }
    
    cout << max << endl;

    return 0;
}

