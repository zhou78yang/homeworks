#include <iostream>
using namespace std;

int main()
{
    int count[10] = {0};
    char s[1005];       

    cin >> s;
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        count[s[i]-'0']++;
    }

    for(int i = 0; i < 10; i++)
    {
        if(count[i] > 0)
        {
            cout << i << ":" << count[i] << endl;
        }
    }

    return 0;
}
