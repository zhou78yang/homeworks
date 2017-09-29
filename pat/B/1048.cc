#include <iostream>
#include <string>
using namespace std;

int main()
{
    string A, tB;
    char odd[] = "0123456789JQK";
    char even[] = "01234567890123456789";
    int len_a, len_b, tmp, count = 1;

    cin >> A >> tB;
    len_a = A.size(); len_b = tB.size();
    tmp = len_a > len_b ? len_a - len_b : 0;

    string B(tmp, '0');
    B += tB;
    len_b += tmp;

    for(int i = len_b-1; i >= len_b-len_a; i--)
    {
        if(count % 2 == 1)
        {
            tmp = A[len_a-len_b+i] - '0' + B[i] - '0';
            B[i] = odd[tmp%13];
        }
        else
        {
            tmp = B[i] - A[len_a-len_b+i];
            B[i] = even[tmp+10];
        }
        count++;
    }

    cout << B << endl;

    return 0;
}
