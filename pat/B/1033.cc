#include <iostream>
using namespace std;

#define N   100005

int main()
{
    char bad[256], input[N], output[N];
    bool book[256] = {0}, shift = true;

    cin.getline(bad, 256);
    cin.getline(input, N);

    for(int i = 0; i < 256; i++)
    {
        book[bad[i]] = true;
    }
    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(book[i])
        {
            book[i+'a'-'A'] = true;
        }
    }
    if(book['+'])
    {
        for(int i = 'A'; i <= 'Z'; i++) book[i] = true;
    }

    for(int i = 0; input[i] != '\0'; i++)
    {
        if(!book[input[i]]) cout << input[i];
    }
    cout << endl;

    return 0;
}
