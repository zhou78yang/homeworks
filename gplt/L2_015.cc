#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n, k, m;
    int table[10005][10];

    cin >> n >> k >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> table[i][j];
        }
    }

    double score[10005];
    for(int i = 0; i < n; i++)
    {
        int sum = 0, max = 0, min = 100;
        for(int j = 0; j < k; j++)
        {
            sum += table[i][j];
            if(max < table[i][j]) max = table[i][j];
            if(min > table[i][j]) min = table[i][j];
        }
        sum = sum - max - min;
        score[i] = (double)sum / (k-2);
    }

    sort(score, score+n);

    for(int i = n-m; i < n-1; i++)
    {
        printf("%.3lf ", score[i]);
    }
    printf("%.3lf\n", score[n-1]);

    return 0;
}
    
