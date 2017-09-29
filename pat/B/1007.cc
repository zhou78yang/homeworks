#include <iostream>
using namespace std;

int primers[50000] = {0};
int len = 0;

bool is_primer(int x)
{
    for(int i = 0; i < len; i++)
    {
        if(x % primers[i] == 0)
        {
            return false;
        }
    }
    primers[len++] = x;
    return true;
}

int main()
{
    int n, count = 0;

    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 2; i <= n; i++)
    {
        if(is_primer(i))
        {
            if(len > 1 && primers[len-1]-primers[len-2] == 2)
            {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}
    
