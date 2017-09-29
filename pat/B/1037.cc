#include <iostream>
using namespace std;

int main()
{
    int g1, g2, s1, s2, k1, k2;

    scanf("%d.%d.%d", &g1, &s1, &k1);
    scanf("%d.%d.%d", &g2, &s2, &k2);

    int t1 = g1*17*29+s1*29+k1;
    int t2 = g2*17*29+s2*29+k2;
    int change = t2 - t1;

    if(change < 0){
        cout << "-";
        change = -change;
    }

    cout << change/17/29 << ".";
    change %= 17*29;
    cout << change/29 << ".";
    change %= 29;
    cout << change << endl;

    return 0;
}
