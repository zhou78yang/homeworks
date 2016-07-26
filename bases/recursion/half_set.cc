// half_set:
//  半数集，给定一个自然数n,由n开始一次产生半数集set(n)
//  ｎ是set(n)的一个元素，在ｎ的左边添加一个数字，添加的数字不能大于最近添加数字的一半,知道不能添加数字为止

#include <iostream>
#include <cstring>

using namespace std;

int shu[1005];

/*
 *  效率低下
int half_set(int n)
{
    int ans = 1;
    if(n > 1)
    {
        for(int i = 1; i <= n / 2; i++)
        {
            ans += half_set(i);
        }
    }
    return ans;
}
*/

// 修正版
int half_set(int n)
{
    int ans = 1;
    if(shu[n]) return shu[n];
    if(n > 1)
    {
        for(int i = 1; i <= n / 2; i++)
        {
            ans += half_set(i);
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        memset(shu, 0, sizeof(shu));
        cout << half_set(n) << endl;
    }

    return 0;
}
    
