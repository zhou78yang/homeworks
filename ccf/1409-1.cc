#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    int a[1005];
    bool book[10005] = {0};

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        book[a[i]] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        if(book[a[i]-1])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
