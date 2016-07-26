/*
 * 计算N!
 *      有多组数据，每组一行，用Ｎ表示
 *      输出Ｎ的阶乘
 *
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    long long N[55];

    N[1] = 1;
    for(int i = 2; i <= 50; i++)
    {
        N[i] = i * N[i-1];
    }

    while(cin >> n)
    {
        cout << N[n] << endl;
    }
    return 0;
}
