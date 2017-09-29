#include <iostream>
using namespace std;

int main()
{
    char a[1005], q[1005];
    int b, r = 0, len = 0;

    cin >> a >> b;
    for(int i = 0; a[i] != '\0'; i++)
    {
        int d = 10 * r + a[i] - '0';
        q[i] = (d / b) + '0';
        r = d % b;
        len++;
    }
    q[len] = '\0';

    int i = 0;
    while(q[i] == '0' && i < len-1) i++;
    cout << q + i << " " << r << endl;

    return 0;
}

