#include <iostream>
using namespace std;

int main()
{
    char num[55];
    double base = 1;
    int length = 0, count = 0;
    int i = 0;

    cin >> num;
    if(num[i] == '-')
    {
        base *= 1.5;
        i++;
    }

    while(num[i] != '\0')
    {
        length++;
        if(num[i] == '2')
        {
            count++;
        }
        i++;
    }

    if((num[i-1] - '0') % 2 == 0)
    {
        base *= 2;
    }

    double rate = (double)count / length * base * 100;
    printf("%.2lf", rate);
    cout << "%" << endl;

    return 0;
}

