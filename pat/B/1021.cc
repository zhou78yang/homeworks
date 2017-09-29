#include <iostream>
using namespace std;

int main()
{
    int book[256] = {0};
    char num[1005];

    cin >> num;
    for(int i = 0; num[i] != '\0'; i++)
    {
        book[num[i]]++;
    }

    for(int i = 0; i < 10; i++)
    {
        if(book['0'+i])
        {
            cout << i << ":" << book['0'+i] << endl;
        }
    }

    return 0;
}

