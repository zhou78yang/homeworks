#include <iostream>
using namespace std;

int main()
{
    int book[256] = {0}, sum = 0, one = 0, zero = 0;
    char str[100005];

    cin.getline(str, 100005);
    for(int i = 0; str[i] != '\0'; i++) book[str[i]]++;

    for(int i = 0; i < 26; i++)
    {
        sum += (i+1)*(book['A'+i]+book['a'+i]);
    }

    while(sum > 0)
    {
        if(sum&1) one++;
        else zero++;
        sum >>= 1;
    }

    cout << zero << " " << one << endl;

    return 0;
}
