#include <iostream>
using namespace std;

#define N   100005
#define MOD 1000000007

int main()
{
    char str[N];
    cin >> str;

    int has_p[N] = {0}, count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'P') count++;
        has_p[i] = count;
    }
    
    int sum_a[N] = {0}, sum = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'A') sum += has_p[i];
        sum_a[i] = sum;
    }

    int total = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'T')
        {
            total += sum_a[i];
            if(total > MOD) total %= MOD;
        }
    }

    cout << total << endl;

    return 0;
}
