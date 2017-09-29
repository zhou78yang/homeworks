#include <iostream>
using namespace std;

int d(int a, int b)
{
    return a*b;
}

int main()
{
    int a[2005], b[2005];
    int len = 0, s = 0;

    while(cin >> a[len] >> b[len]) len++;

    if(b[0] == 0){
        if(len == 1)
        {
            cout << "0 0\n";
            return 0;
        }
        else
        {
            s = 1;
        }
    }
    cout << a[s]*b[s] << " " << b[s]-1;
    for(int i = s+1; i < len; i++)
    {
        if(b[i] == 0) continue;
        cout << " ";
        cout << a[i]*b[i] << " " << b[i]-1;
    }
    cout << endl;

    return 0;
}

