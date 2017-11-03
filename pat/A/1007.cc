#include <iostream>
using namespace std;

struct Sum
{
    int value = 0, max = -99999999, pos;
};

int main()
{
    int A[10005], n;
    Sum S[10005];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++)
    {
        S[i].pos = i;
        for(int j = i; j < n; j++)
        {
            S[i].value += A[j];
            if(S[i].max < S[i].value)
            {
                S[i].max = S[i].value;
                S[i].pos = j;
            }
        }
    }
    int max_value = S[0].max, pos = 0;
    for(int i = 1; i < n; i++)
    {
        if(S[i].max > max_value)
        {
            max_value = S[i].max;
            pos = i;
        }
    }
    
    cout << max_value << " " << A[pos] << " " << A[S[pos].pos] << endl;

    return 0;
}
    
