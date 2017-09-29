#include <iostream>
using namespace std;

int main()
{
    int n, friend_id;
    char num[5];
    bool book[40] = {0};

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        friend_id = 0;
        for(int j = 0; num[j] != '\0'; j++) 
        {
            friend_id += num[j]-'0';
        }
        book[friend_id] = true;
    }

    int len = 0, list[40];
    for(int i = 0; i < 40; i++)
    {
        if(book[i]) list[len++] = i;
    }

    cout << len << endl << list[0];
    for(int i = 1; i < len; i++) cout << " " << list[i];
    cout << endl;

    return 0;
}

