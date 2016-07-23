#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char A[10005], B[10005];

    gets(A);
    gets(B);

    for(int i = 0; A[i] != '\0'; i++)
    {
        bool flag = true;
        for(int j = 0; B[j] != '\0'; j++)
        {
            if(A[i] == B[j])
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
        {
            cout << A[i];
        }
    }
    cout << endl;

    return 0;
}
