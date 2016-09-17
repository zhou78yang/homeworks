#include <iostream>
#include <cstdio>
using namespace std;

const int md[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const int weekday[7] = {7, 1, 2, 3, 4, 5, 6};

bool is_leap(int y)
{
    return (y % 100 != 0 && y % 4 == 0) ||
           (y % 400 == 0);
}

void output(int m, int w, int wd, int y)
{
    int days = 0;
    for(int i = 1850; i < y; i++)
    {
        if(is_leap(i)) days += 366;
        else days += 365;
    }

    int k = is_leap(y) ? 1 : 0;
    for(int i = 1; i < m; i++)
    {
        days += md[k][i];
    }
    
    days = weekday[(1+days)%7];
    int d = wd - days;
    if(d <= 0) d += 7;
    d += (w-1)*7;
    if(d <= md[k][m])
    {
        printf("%d/%02d/%02d\n", y, m, d);
    }
    else
    {
        cout << "none" << endl;
    }
}

int main()
{
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    for(int i = y1; i <= y2; i++)
    {
        output(a, b, c, i);
    }

    return 0;
}

