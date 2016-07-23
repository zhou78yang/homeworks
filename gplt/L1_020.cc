#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    bool has_friend[100005] = {0};
    bool book[100005] = {0};
    int n, k, id;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        if(k > 1)
        {
            for(int j = 0; j < k; j++)
            {
                cin >> id;
                has_friend[id] = true;
            }
        }
        else
        {
            cin >> id;
        }
    }

    cin >> n;
    bool NOH = true;
    bool first_handsome = true;
    for(int i = 0; i < n; i++)
    {
        cin >> id;
        if(!has_friend[id] && !book[id])
        {
            book[id] = true;
            NOH = false;
            if(!first_handsome)
            {
                cout << " ";
            }
            else
            {
                first_handsome = false;
            }
            printf("%05d", id);
        }
    }

    if(NOH)
    {
        cout << "No one is handsome";
    }
    cout << endl;

    return 0;
}

