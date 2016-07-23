#include <iostream>
using namespace std;

int main()
{
    int d;

    cin >> d;
    d = (d+2)%7;

    if(d == 0) d = 7;
    cout << d << endl;

    return 0;
}
