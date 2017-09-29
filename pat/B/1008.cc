#include <iostream>
using namespace std;

int main()
{
    int A[100], n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> A[i];
    int index = (n-m%n) % n;
    cout << A[index];
    for(int i = 1; i < n; i++)
    {
        index = (index+1)%n;
        cout << " " << A[index];
    }
    cout << endl;

    return 0;
}
