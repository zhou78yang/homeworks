#include <iostream>
using namespace std;

int main()
{
    int n, m, A[105], answer[105];

    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> answer[i];

    int solu, score;
    for(int i = 0; i < n; i++)
    {
        score = 0;
        for(int j = 0; j < m; j++)
        {
            cin >> solu;
            if(solu == answer[j])
            {
                score += A[j];
            }
        }
        cout << score << endl;
    }

    return 0;
}

