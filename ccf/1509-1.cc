#include <iostream>
using namespace std;

int main()
{
    int n, a[1005], count = 1;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
