#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n, a, b;
    double r = 0.0, tmp;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        tmp = sqrt(a*a+b*b);
        if(r < tmp) r = tmp;
    }
    printf("%.2f\n", r);

    return 0;
}
