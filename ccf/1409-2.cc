#include <iostream>
using namespace std;

int main()
{
    int n, x1, y1, x2, y2;
    bool book[105][105] = {0};

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        for(int i = y1; i < y2; i++)
        {
            for(int j = x1; j < x2; j++)
            {
                book[i][j] = true;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(book[i][j]) count++;
        }
    }
    cout << count << endl;

    return 0;
}
