#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int H;
    double W;

    cin >> H;
    W = (H-100)*0.9*2;

    printf("%.1lf\n", W);

    return 0;
}
