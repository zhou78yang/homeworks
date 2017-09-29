#include <iostream>
using namespace std;

int main()
{
    int len = 0, j = 0;
    char input[100], output[100], badkey[80];
    bool book[256] = {0}, checkin[256] = {0};

    cin >> input >> output;
    for(int i = 0; output[i] != '\0'; i++) book[output[i]] = true;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == output[j] && output[j] != '\0') j++;
        else
        {
            if(input[i] >= 'a' && input[i] <= 'z') input[i] += 'A'-'a';
            if(!checkin[input[i]] && !book[input[i]] && !book[input[i]-'A'+'a'])
            {
                badkey[len++] = input[i];
                checkin[input[i]] = true;
            }
        }
    }
    badkey[len] = '\0';
    cout << badkey << endl;
    
    return 0;
}
