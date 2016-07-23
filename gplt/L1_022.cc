#include <iostream>
using namespace std;

int main()
{
    int arr[1005], n;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i]&1)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }

    cout << odd << " " << even << endl;

    return 0;
}
