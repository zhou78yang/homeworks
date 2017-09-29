#include <iostream>
using namespace std;

int main()
{
    int t1, t2;

    cin >> t1 >> t2;
    int t = double(t2 - t1) / 100 + 0.5;

    int s = t % 60; t /= 60;
    int m = t % 60; t /= 60;
    printf("%02d:%02d:%02d\n", t, m, s);

    return 0;
}

