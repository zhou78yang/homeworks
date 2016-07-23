#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, limit, len = 0, begin = 1;

    cin >> n;
    limit = sqrt(n) + 1;

    for(int i = 2; i < limit; i++)
    {
        int tmp = n, mod = i, count = 0;
        while(tmp % mod == 0)
        {
            tmp /= mod;
            count++;
            mod++;
        }
        if(count > len)
        {
            len = count;
            begin = i;
        }
    }

    if(len == 0 || n == 1)
    {
        len = 1;
        begin = n;
    }

    cout << len << endl << begin;
    for(int i = 1; i < len; i++)
    {
        cout << "*" << ++begin;
    }
    cout << endl;

    return 0;
}

