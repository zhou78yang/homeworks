#include <iostream>
using namespace std;

int main()
{
    int book[1005] = {0};
    int n, id;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id;
        cout << ++book[id] << " ";
    }
    cout << endl;

    return 0;
}

