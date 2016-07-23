#include <iostream>
using namespace std;

int main()
{
    char time[5];
    int h, m;

    cin >> time;
    h = (time[0] - '0') * 10 + (time[1] - '0');
    m = (time[3] - '0') * 10 + (time[4] - '0');

    if(h < 12 || (h == 12 && m == 0))
    {
        cout << "Only " << time << ".  Too early to Dang." << endl;
    }
    else
    {
        h -= 12;
        if(m > 0) h++;
        while(h-- > 0)
        {
            cout << "Dang";
        }
        cout << endl;
    }

    return 0;
}

