#include <iostream>
using namespace std;

int main()
{
    char str[10005];
    int book[256] = {0};
    cin >> str;
    for(int i = 0; str[i] != '\0'; i++) book[str[i]]++;
    char ascii[7] = "PATest";
    int order[6];
    for(int i = 0; i < 6; i++) order[i] = book[ascii[i]];

    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 0; i < 6; i++)
        {
            if(order[i] > 0)
            {
                order[i]--;
                flag = true;
                cout << ascii[i];
            }
        }
    }
    cout << endl;

    return 0;
}

