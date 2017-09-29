#include <iostream>
using namespace std;

struct Date
{
    int y, m, d;
    Date(int yy, int mm, int dd):y(yy), m(mm), d(dd){}
    bool lt(Date x)
    {
        return y > x.y || (y == x.y && m > x.m) ||
            (y == x.y && m == x.m && d >= x.d);
    }
    bool bt(Date x)
    {
        return y < x.y || (y == x.y && m < x.m) ||
            (y == x.y && m == x.m && d <= x.d);
    }
    bool legal()
    {
        return lt(Date(1814, 9, 6)) && bt(Date(2014, 9, 6));
    }
};

int main()
{
    int T, y, m, d, count = 0;
    Date youngest(1814, 9, 6), oldest(2014, 9, 6);
    string name, name_y, name_o;

    cin >> T;
    while(T-- > 0)
    {
        cin >> name;
        scanf("%d/%d/%d", &y, &m, &d);
        Date tmp(y, m, d);
        if(tmp.legal())
        {
            if(tmp.lt(youngest))
            {
                youngest = tmp;
                name_y = name;
            }
            if(tmp.bt(oldest))
            {
                oldest = tmp;
                name_o = name;
            }
            count++;
        }
    }

    if(count) cout << count << " " << name_o << " " << name_y << endl;
	else cout << "0\n";
	
    return 0;
}
