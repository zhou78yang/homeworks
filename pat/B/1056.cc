#include <iostream>
using namespace std;

int main()
{
    int n, t, sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
    }
    sum *= n-1;
    cout << 11*sum << endl;

    return 0;
}
