#include <iostream>
#include <cstring>
using namespace std;

#define N   1005
char A[64][N][N];
char b[N], res[N], tmp_res[N];
int m;
bool vis[64];

void getA(int n)
{
    if(vis[n]) return;
    getA(n-1);
    vis[n] = true;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char tmp = A[n-1][i][0] & A[n-1][0][j];
            for(int k = 1; k < m; k++)
            {
                tmp ^= (A[n-1][i][k] & A[n-1][k][j]);
            }
            A[n][i][j] = tmp;
        }
    }
}

void mul(int n)
{
    // 当前结果与A[n]相乘的结果
    getA(n);
    for(int i = 0; i < m; i++) tmp_res[i] = res[i];
    for(int i = 0; i < m; i++)
    {
        char tmp = tmp_res[i] & A[n][i][0];
        for(int j = 1; j < m; j++)
        {
            tmp ^= (tmp_res[j] & A[n][i][j]);
        }
        res[i] = tmp;
    }
}



int main()
{
    cin >> m;
    for(int i = 0; i < m; i++) cin >> A[1][i];
    cin >> b;
    
    memset(vis, 0, sizeof(vis));
    vis[1] = true;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        // 总共计算n次
        for(int j = 0; j < m; j++) res[j] = b[j];// 结果初始化

        int k, x = 1;   // x记录A的乘方
        cin >> k;
        while(k > 0)
        {
            if(k%2 == 1)
            {
                // 进行一次计算
                mul(x);
            }
            x++; k>>=1;
        }
        for(int j = 0; j < m; j++) cout << res[j];
        cout << endl;
    }
    return 0;
}
