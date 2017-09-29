#include <iostream>
using namespace std;

int main()
{
    char A[11], B[11], Da, Db;
    cin >> A >> Da >> B >> Db;

    int a = 0, b = 0;
    for(int i = 0; A[i] != '\0'; i++)
    {
        if(A[i] == Da) a = 10 * a + Da - '0';
    }
    for(int i = 0; B[i] != '\0'; i++)
    {
        if(B[i] == Db) b = 10 * b + Db - '0';
    }
    cout << a + b << endl;

    return 0;
}
