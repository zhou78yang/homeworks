#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int score[10005][10];
int sum[10005] = {0};
int N, K, M;

int main()
{
    cin >> N >> K >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            cin >> score[i][j];
        }
    }

    for(int i = 1; i <= N; i++)
    {
        int min = 100, max = 0;
        for(int j = 0; j < K; j++)
        {
            sum[i] += score[i][j];
            if(score[i][j] > max) max = score[i][j];
            if(score[i][j] < min) min = score[i][j];
        }
        sum[i] = sum[i] - min - max;
    }

    sort(sum+1, sum+1+N);

    for(int i = N+1-M; i <= N; i++)
    {
        printf("%.3lf", (double)sum[i]/(K-2));
        if(i < N) cout << " ";
        else cout << endl;
    }

    return 0;
}

        

