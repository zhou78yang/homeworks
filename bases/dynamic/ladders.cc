/*
 * 超级楼梯
 *      一个楼梯有Ｎ级，每次只能走一级或者两级，问走到顶端有多少种走法
 *
 *
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    long long ladders[55];

    ladders[1] = 1; ladders[2] = 1;
    for(int i = 3; i < 55; i++)
    {
        ladders[i] = ladders[i-1] + ladders[i-2];
    }

    while(cin >> n)
    {
        cout << ladders[n] << endl;
    }

    return 0;
}

