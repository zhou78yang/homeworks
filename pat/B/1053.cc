#include <iostream>
using namespace std;

int main()
{
    int n, k, D;
    int empty = 0, maybe_empty = 0;
    double e, t;

    cin >> n >> e >> D;

    for(int i = 0; i < n; i++)
    {
        int d = 0;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> t;
            if(t < e) d++;
        }
        if(d*2 > k)
        {
            if(k > D) empty++;
            else maybe_empty++;
        }
    }

    printf("%.1f", (double)maybe_empty*100/n);
    cout << "% ";
    printf("%.1f", (double)empty*100/n);
    cout << "%\n";
    
    return 0;
}
