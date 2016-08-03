#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Person {
    int id, money, get;
} P[10005];

bool comp(const Person &a, const Person &b)
{
    return a.money > b.money ||
    (a.money == b.money && a.get > b.get) ||
    (a.money == b.money && a.get == b.get && a.id < b.id);
}

int main()
{
    int n, k, id, sum, money;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        P[i].id = i;
        P[i].money = 0;
        P[i].get = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> k;
        sum = 0;
        for(int j = 0; j < k; j++)
        {
            cin >> id >> money;
            P[id].money += money;
            P[id].get++;
            sum += money;
        }
        P[i].money -= sum;
    }

    sort(P+1, P+n+1, comp);
    for(int i = 1; i <= n; i++)
    {
        double m = (double)P[i].money / 100;
        printf("%d %.2lf\n", P[i].id, m);
    }

    return 0;
}

