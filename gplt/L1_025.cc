#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char A[1005], B[1005], tail[1005];
    bool digitA = true, digitB = true;
    long long numA = 0, numB = 0;

    cin >> A >> B;
    while(cin >> tail)
    {
        digitB = false;
    }

    for(int i = 0; A[i] != '\0'; i++)
    {
        if(!isdigit(A[i]))
        {
            digitA = false;
            break;
        }
        numA = numA * 10 + A[i] - '0';            
    }
    if(numA < 1 || numA > 1000) digitA = false;

    for(int i = 0; B[i] != '\0'; i++)
    {
        if(!isdigit(B[i]))
        {
            digitB = false;
            break;
        }
        numB = numB * 10 + B[i] - '0';
    }
    if(numB < 1 || numB > 1000) digitB = false;

    if(digitA)
    {
        cout << numA << " + ";
    }
    else
    {
        cout << "? + ";
    }

    if(digitB)
    {
        cout << numB << " = ";
    }
    else
    {
        cout << "? = ";
    }

    if(digitA && digitB)
    {
        cout << numA + numB << endl;
    }
    else
    {
        cout << "?" << endl;
    }

    return 0;
}

