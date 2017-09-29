#include <iostream>
using namespace std;

int callatz(int x)
{
    if(x % 2 == 0) return x/2;
    else return (3*x+1)/2;
}

int main()
{
    int x;
    cin >> x;
    int count = 1;
    while((x = callatz(x)) != 1) count++;
    cout << count << endl;
    
    return 0;
}
