#include <iostream>
#include <cstdio>
using namespace std;
char tmp[1000];

int main()
{
    char A[100], B[100];
    int a = 0, b = 0;
    bool fa = true, fb = true;

    cin >> A >> B;
    gets(tmp);

    for(int i = 0; A[i] != '\0'; i++)
    {
        if(A[i] < '0' || A[i] > '9')
        {
            fa = false;
            break;
        }
        else
        {
            a = a * 10 + (A[i] - '0');
        }
    }
    if(fa) cout << a;
    else cout << "?";
    cout << " + ";

    for(int i = 0; B[i] != '\0'; i++)
    {
        if(B[i] < '0' || B[i] > '9')
        {
            fb = false;
            break;
        }
        else
        {
            b = b * 10 + (B[i] - '0');
        }
    }
    if(fb) cout << b;
    else cout << "?";
    cout << " = ";
    if(fa && fb) cout << a + b << endl;
    else cout << "?" << endl;

    return 0;
}

