#include <iostream>
using namespace std;

int main()
{
    char table[25], n1[25], n2[25];

    cin >> table >> n1 >> n2;
    int len = 0, l1 = 0, l2 = 0;
    while(table[len] != '\0') len++;
    while(n1[l1] != '\0') l1++;
    while(n2[l2] != '\0') l2++;

    int code[25], sum[25], jw = 0;
    for(int i = 0; i < len; i++)
    {
        code[i] = table[len-i-1] - '0';
        if(code[i] == 0) code[i] = 10;
    }

    for(int i = 0; i < len; i++)
    {
        int a = i < l1 ? n1[l1-i-1]-'0' : 0;
        int b = i < l2 ? n2[l2-i-1]-'0' : 0;
        sum[i] = a + b + jw;
        jw = sum[i] / code[i];
        sum[i] %= code[i];
    }
    if(jw) sum[len++] = jw;

    while(sum[len-1] == 0 && len > 1) len--;
    while(len-- > 0) cout << sum[len];
    cout << endl;

    return 0;
}
