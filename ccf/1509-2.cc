#include <iostream>
using namespace std;

bool is_leap(int y)
{
    return y%400 == 0 || (y%4 == 0 && y%100 != 0);
}

int main()
{
    int y, d, m = 1;
    int md[13] = {0, 31, 28, 31, 30, 31, 30, 
                     31, 31, 30, 31, 30, 31};

    cin >> y >> d;
    if(is_leap(y)) md[2] = 29;

    while(d > md[m]) d -= md[m++];

    cout << m << endl << d << endl;

    return 0;
}
