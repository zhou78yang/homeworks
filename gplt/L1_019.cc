#include <iostream>
using namespace std;

int main()
{
    int totalA, totalB, countA = 0, countB = 0;
    int numA, numB, sumA, sumB, n, sum;

    cin >> totalA >> totalB;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> numA >> sumA >> numB >> sumB;
        if(sumA == sumB) continue;

        sum = numA + numB;
        if(sumA == sum)
        {
            countA++;
            if(countA > totalA)
            {
                cout << "A" << endl;
                cout << countB << endl;
                break;
            }
        }

        if(sumB == sum)
        {
            countB++;
            if(countB > totalB)
            {
                cout << "B" << endl;
                cout << countA << endl;
                break;
            }
        }
    }

    return 0;
}

