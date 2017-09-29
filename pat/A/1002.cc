#include <iostream>
using namespace std;

int main()
{
    int k, id, count = 0;
    double tmp, A[1005] = {0}, B[1005] = {0};
    bool book[1005] = {0};

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> id >> tmp;
        A[id] = tmp;
        if(!book[id]) count++;
        book[id] = true;
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> id >> tmp;
        B[id] = tmp;
        if(!book[id]) count++;
        book[id] = true;
    }

    cout << count;
    for(int i = 1000; i >= 0; i--)
    {
        if(book[i])
        {
            cout << " " << i << " " << A[i]+B[i];
        }
    }
    cout << endl;

    return 0;
}
