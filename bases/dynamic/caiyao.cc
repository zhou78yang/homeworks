/*
 * 采药
 *  输入:第一行有两个整数Ｔ(1<=T<=1000)和Ｍ(1<=M<=100)，
 *  Ｔ表示总共能够用来采药的时间，Ｍ表示能采药的总数。接下来的Ｍ行，
 *  每行包括两个整数，分别用来表示采药需要花费的时间和药的价值
 *  输出：可以采到药物的最大价值
 */

#include <iostream>
#include <cstring>

using namespace std;

#define N 105

int T[N], V[N];
int memo[1005][N];

int caiyao(int t, int k)
{
    // t表示能够采药的最大时间，ｋ表示药的种数
    if(memo[t][k] > 0) return memo[t][k];
    if(t == 0 || k == 0) return 0;
    if(t >= T[k])
    {
        memo[t][k] = max(caiyao(t-T[k], k-1) + V[k], caiyao(t, k-1));
    }
    else
    {
        memo[t][k] = caiyao(t, k-1);
    }

    return memo[t][k];
}

int main(int argc, char *argv[])
{
    int t, m;
    cin >> t >> m;

    memset(memo, 0, sizeof(memo));

    for(int i = 1; i <= m; i++)
    {
        cin >> T[i] >> V[i];
    }

    cout << caiyao(t, m) << endl;

    return 0;
}
