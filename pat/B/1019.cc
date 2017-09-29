#include <iostream>
#include <algorithm>
using namespace std;

void reduce(int *arr, int n)
{
    for(int i = 0; i < 4; i++)
    {
        arr[i] = n % 10;
        n /= 10;
    }
    sort(arr, arr+4);
}

bool allSame(int *arr)
{
    for(int i = 1; i < 4; i++) if(arr[i] != arr[0]) return false;
    return true;
}

int min(int *arr)
{
    int n = arr[0];
    for(int i = 1; i < 4; i++) n = 10 * n + arr[i];
    return n;
}

int max(int *arr)
{
    int n = arr[3];
    for(int i = 2; i >= 0; i--) n = 10 * n + arr[i];
    return n;
}

int main()
{
    int n;
    int arr[4];

    cin >> n;

    reduce(arr, n);
    if(allSame(arr))
    {
        printf("%04d - %04d = %04d\n", n, n, 0);
        return 0;
    }
    
    do
    {
        int a = max(arr), b = min(arr);
        n = a - b;
        printf("%04d - %04d = %04d\n", a, b, n);
        reduce(arr, n);
    }while(n != 6174);

    return 0;
}

