#include <iostream>
using namespace std;

int main()
{
    int index = 0;
    int book[10] = {0};
    char phone[11];

    cin >> phone;
    for(int i = 0; i < 11; i++)
    {
        book[phone[i]-'0'] = 1;
    }

    cout << "int[] arr = new int[]";
    for(int i = 9; i >= 0; i--)
    {
        if(book[i])
        {
            if(index == 0) cout << "{";
            else cout << ",";
            cout << i;
            book[i] = index++;
        }
        else
        {
            book[i] = -1;
        }
    }
    cout << "};" << endl
         << "int[] index = new int[]{";

    for(int i = 0; i < 10; i++)
    {
        cout << book[phone[i]-'0'] << ",";
    }
    cout << book[phone[10]-'0'] << "};" << endl;

    return 0;
}
