#include <iostream>
using namespace std;

#define DELTA       1000

int main()
{
    int n, count = 0;
    int a[505];
    bool book[2005] = {0};

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(book[DELTA-a[i]])
        {
            count++;
        }
        else
        {
            book[a[i]+DELTA] = true;
        }
    }

    cout << count << endl;

    return 0;
}

