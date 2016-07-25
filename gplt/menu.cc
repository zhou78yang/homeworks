#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int level, n;

    cin >> level >> n;
    for(int i = 1; i <= n; i++)
    {
        printf("+ [L%d-%03d](./L%d_%03d.cc)", level, i, level, i);
        printf(" [oj](https://www.patest.cn/contests/gplt/L%d-%03d)\n", level, i);
    }

    return 0;
}
