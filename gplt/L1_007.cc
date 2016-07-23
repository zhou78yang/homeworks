#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 0;
    char s[1005];
    const string table[10] = {"ling", "yi", "er", "san", "si",
                              "wu", "liu", "qi", "ba", "jiu" };

    cin >> s;

    if(s[i] == '-')
    {
        cout << "fu" << " ";
        i++;
    }

    while(true)
    {
        cout << table[s[i]-'0'];
        if(s[++i] == '\0') break;
        cout << " ";
    }
    cout << endl;

    return 0;
}
    
