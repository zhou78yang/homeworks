#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N       1005

int manachar(char *s)
{
    int len = 0, ret = 1;
    int P[2*N];
    char str[2*N];
    
    str[len++] = '$';
    str[len++] = '#';

    for(int i = 0; s[i] != '\0'; i++)
    {
        str[len++] = s[i];
        str[len++] = '#';
    }

    int m = 1, index = 1;
    for(int i = 1; i < len; i++)
    {
        if(i < m)
        {
            P[i] = min(m-i, P[2*index-i]);
        }
        else
        {
            P[i] = 1;
        }

        while(str[i-P[i]] == str[i+P[i]]) P[i]++;

        if(P[i] + i > m)
        {
            m = i + P[i];
            index = i;
        }
        if(P[i] > ret) ret = P[i];
    }

    return ret-1;
}

int main()
{
    char s[N];
    
    gets(s);
    cout << manachar(s) << endl;

    return 0;
}

