#include <iostream>
using namespace std;

int main()
{
    int n;
    double A[100005], sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++)
    {
        double sum_i = 0, tmp = 0;
        for(int j = i; j < n; j++)
        {
            tmp += A[j];
            sum_i += tmp;
        }
        sum += sum_i;
    }
    printf("%.2lf\n", sum);

    return 0;
}
