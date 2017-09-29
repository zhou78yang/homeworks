#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    char num[105];
    string s[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    cin >> num;
    for(int i = 0; num[i] != '\0'; i++)
    {
        sum += num[i] - '0';
    }

    int code[5] = {0}, len = 0;
    do
    {
        code[len++] = sum % 10;
        sum /= 10;
    } while(sum > 0);
    cout << s[code[--len]];
    while(len > 0)
    {
        cout << " " << s[code[--len]];
    }
    cout << endl;

    return 0;
}

