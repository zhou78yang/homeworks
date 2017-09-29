#include <iostream>
#include <algorithm>
using namespace std;

struct Cake
{
    double q, p, a;
};

bool comp(Cake a, Cake b)
{
    return a.a > b.a;
}

int main()
{
    int n, D;
    double tmp;
    Cake cake[1005];

    cin >> n >> D;
    for(int i = 0; i < n; i++) cin >> cake[i].q;
    for(int i = 0; i < n; i++) cin >> cake[i].p;
    for(int i = 0; i < n; i++) cake[i].a = cake[i].p / cake[i].q;

    sort(cake, cake+n, comp);

    double income = 0;
    for(int i = 0; i < n; i++)
    {
        if(cake[i].q <= D)
        {
            income += cake[i].p;
            D -= cake[i].q;
        }
        else
        {
            income += cake[i].a * D;
            break;
        }
    }

    printf("%.2f\n", income);
    return 0;
}
