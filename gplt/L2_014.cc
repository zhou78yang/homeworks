#include <iostream>
using namespace std;

#define N       100005

int tail[N] = {0};              // the train last into the pipe


int bin_search(int lo, int hi, int x)
{
    // search in [lo, hi)
    int mi;
    while(hi > lo)
    {
        mi = (lo + hi) / 2;
        if(tail[mi] < x) lo = mi+1;     // search [mi+1, hi)
        else hi = mi;                   // search [lo, mi)
    }
    return lo;                          
}


int main()
{
    int count = 0, n, entra;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> entra;
        int j = bin_search(0, count, entra);

        if(j >= count)
        {
            tail[count++] = entra;
        }
        else
        {
            tail[j] = entra;
        }
    }
    cout << count << endl;

    return 0;
}
