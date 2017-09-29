#include <iostream>
using namespace std;

int main()
{
    int n, t, book[100005] = {0}, max = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        if(t > max) max = t;
        book[t]++;
    }

    int rest = n, e = 0;
    for(int i = 0; i <= max; i++)
    {
        rest -= book[i];
        if(i <= rest) e = i;
        else break;
    }

    cout << e << endl;

    return 0;
}

