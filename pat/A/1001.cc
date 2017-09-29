#include <iostream>
using namespace std;

int main()
{
    int a, b, sum, s, num[3], len = 0;

    cin >> a >> b;
    sum = a + b;
    if(sum < 0) cout << "-";
    sum = abs(sum);

    while(sum > 0)
    {
        num[len++] = sum % 1000;
        sum /= 1000;
    }
    cout << num[--len];
    for(int i = len-1; i >= 0; i--) printf(",%03d", num[i]);
    cout << endl;

    return 0;
}
