#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    long long w[1005];

    w[1] = 2; w[2] = 24; w[3] = 96;

    cin >> N;
    for(int i = 4; i <= N; i++)
    {
        w[i] = 2 * (w[i-1] + 2 * w[i-2]);
    }

    cout << w[N] << endl;
    return 0;
}
