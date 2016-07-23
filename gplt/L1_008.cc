#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int A, B;
    int count = 0, sum = 0;

    cin >> A >> B;

    for(int i = A; i <= B; i++)
    {
        sum += i;
        printf("%5d", i);
        if(++count % 5 == 0) cout << endl;
    }

    if(count % 5 != 0) cout << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}

