/*
 * 饭卡问题
 *  学校食堂的饭卡有一种很诡异的设计，即在购买之前判断余额，
 *  如果购买一个商品之前，卡上的余额大于或者等于５元，
 *  就一定可以购买成功（即使购买之后卡上的余额为负），
 *  否则无法购买（即使金额足够）。
 *  某天，食堂中有ｎ种菜出售，每种菜可以购买一次：
 *  输入：
 *      第一行为一个正整数ｎ，n <= 1000,表示菜的数量
 *      第二行包括ｎ个正整数，表示菜的价格，均不超过50
 *      第三航包括一个正整数m，m<= 1000,表示卡上余额
 */

#include <iostream>
using namespace std;

int ZeroOnePack(int price[], int money, int n, int pos)
{
    int f[1024] = {0};
    for(int i = 1; i <= n; i++)     // 前ｉ种物品能够购买的总价值
    {
        if(i == pos) continue;
        for(int j = money; j >= price[i]; j--)  // 钱大于菜的售价
        {
            if(f[j] < f[j-price[i]] + price[i])
            {
                f[j] = f[j-price[i]] + price[i];
            }
        }
    }
    return money - f[money];
}

int main(int argc, char *argv[])
{
    int n, money, price[1024];
    while(cin >> n)
    {
        int max = 0, pos;
        for(int i = 1; i <= n; i++)
        {
            cin >> price[i];
            if(max < price[i])
            {
                pos = i; 
                max = price[i];
            }
        }
        cin >> money;
        if(money >= 5)
        {
            cout << ZeroOnePack(price, money-5, n, pos) + 5 - max << endl;
        }
        else
        {
            cout << money;
        }
    }

    return 0;
}

    
