#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[1005];
    cin.getline(str, 1005);

    int count[256] = {0};
    for(int i = 0; str[i] != '\0'; i++) count[str[i]]++;

    int det = 'A'-'a';
    for(int i = 'a'; i <= 'z'; i++) count[i] += count[i+det];
    char max = 'a';
    for(int i = 'b'; i <= 'z'; i++)
    {
        if(count[i] > count[max]) max = i;
    }
    cout << max << " " << count[max] << endl;

    return 0;
}
