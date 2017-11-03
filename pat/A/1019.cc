#include <iostream>
using namespace std;

int main()
{
    long long origin;
    int b, num[100], len = 0;

    cin >> origin >> b;
    do
    {
        num[len++] = origin % b;
        origin /= b;
    } while(origin > 0);

    int lo = 0, hi = len-1;
    bool flag = true;
    while(lo < hi)
    {
        if(num[lo] != num[hi])
        {
            flag = false;
            break;
        }
        lo++; hi--;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
    for(int i = len-1; i > 0; i--) cout << num[i] << " ";
    cout << num[0] << endl;

    return 0;
}
