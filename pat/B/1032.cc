#include <iostream>
using namespace std;

int main()
{
    int n, S[100000] = {0}, id, score, max = 1;

    cin >> n;
    while(n-- > 0)
    {
        cin >> id >> score;
        S[id] += score;
        if(S[id] > S[max]) max = id;
    }

    cout << max << " " << S[max] << endl;

    return 0;
}

