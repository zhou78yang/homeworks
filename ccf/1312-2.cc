#include <iostream>
using namespace std;

int main()
{
    char isbn[15], n = 0;
    int sum = 0;
    const char table[] = {'0', '1', '2', '3', '4', '5',
                          '6', '7', '8', '9', 'X'};

    for(int i = 0; i < 13; i++)
    {
        cin >> isbn[i];
        if(isbn[i] != '-' && ++n < 10)
        {
            sum += (isbn[i] - '0') * n;
        }
    }

    sum %= 11;
    if(table[sum] == isbn[12])
    {
        cout << "Right" << endl;
    }
    else
    {
        isbn[12] = table[sum];
        cout << isbn << endl;
    }

    return 0;
}
