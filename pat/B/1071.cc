#include <iostream>
using namespace std;

int main()
{
    int t, k, x, n1, n2;
    bool b;

    cin >> t >> k;
    x = t;
    for(int i = 0; i < k; i++)
    {
        cin >> n1 >> b >> t >> n2;
        if(t > x)
        {
            cout << "Not enough tokens.  Total = " << x << ".\n";
            continue;
        }

        if((n2 > n1)^b)
        {
            x -= t;
            cout << "Lose " << t << ".  Total = " << x << ".\n";
        }
        else
        {
            x += t;
            cout << "Win " << t << "!  Total = " << x << ".\n";
        }

        if(x == 0)
        {
            cout << "Game Over.\n";
            break;
        }
    }

    return 0;
}

