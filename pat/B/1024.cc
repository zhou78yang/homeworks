#include <iostream>
using namespace std;

int main()
{
    char input[10005], num[10005];

    cin >> input;
    int i = 1, len = 0;
    while(input[i] != 'E')
    {
        if(input[i] != '.') num[len++] = input[i];
        i++;
    }
    num[len] = '\0';

    int e = 0;
    char sign_e = input[++i];
    while(input[++i] != '\0')
    {
        e = e * 10 + input[i] - '0';
    }
    if(sign_e == '-') e = -e;
    e += 1;

    if(input[0] == '-') cout << '-';
    if(e <= 0)
    {
        cout << "0.";
        while(e++ < 0) cout << "0";
        cout << num << endl;
    }
    else if(e >= len)
    {
        cout << num;
        while(e-- > len) cout << "0";
        cout << endl;
    }
    else
    {
        for(i = 0; i < e; i++) cout << num[i];
        cout << ".";
        for(i = e; i < len; i++) cout << num[i];
        cout << endl;
    }

    return 0;
}
