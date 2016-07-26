#include <iostream>
#include <algorithm>
using namespace std;

int book[1005] = {0};

bool comp(int a, int b)
{
    return book[a] > book[b] || 
          (book[a] == book[b] && a < b);
}

int main()
{
    int n, a[1005], num, len = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        if(!book[num]++) a[len++] = num;
    }

    sort(a, a+len, comp);

    for(int i = 0; i < len; i++)
    {
        cout << a[i] << " " << book[a[i]] << endl;
    }

    return 0;
}

