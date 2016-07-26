#include <iostream>
using namespace std;

int main()
{
    int n, max = 0, num;
    int count[10005] = {0}, a[1005];

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num;
        count[num]++;
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(count[i] > max)
        {
            max = count[i];
            num = i;
        }
    }
    cout << num << endl;

    return 0;
}

