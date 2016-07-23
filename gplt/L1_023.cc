#include <iostream>
using namespace std;

int main()
{
    int count[256] = {0};
    char s[10005];

    cin >> s;

    for(int i = 0; s[i] != '\0'; i++)
    {
        count[s[i]]++;
    }

    int g = count['g'] + count['G'];
    int p = count['p'] + count['P'];
    int l = count['l'] + count['L'];
    int t = count['t'] + count['T'];

    while(g || p || l || t)
    {
        if(g && g--) cout << 'G';
        if(p && p--) cout << 'P';
        if(l && l--) cout << 'L';
        if(t && t--) cout << 'T';
    }
    cout << endl;

    return 0;
}
