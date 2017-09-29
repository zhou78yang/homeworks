#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

#define N   1005
#define M   105

int main()
{
    int n, m;
    int answer[M][7] = {0}, result[M][5] = {0};
    int goal[M];
    char item;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> goal[i] >> answer[i][5] >> answer[i][6];
        for(int j = 0; j < answer[i][6]; j++)
        {
            cin >> item;
            answer[i][item-'a'] = 1;
        }
    }

    int k, max = 0;
    double score, g;
    string line;
    while(n-- > 0)
    {
        score = 0;
        getline(cin, line);
        istringstream in(line);
        for(int i = 0; i < m; i++)
        {
            int solu[5] = {0};
            g = goal[i];
            cin >> item >> k;
            if(k < answer[i][6]) g /= 2;
            for(int j = 0; j < k; j++)
            {
                cin >> item;
                solu[item-'a'] = 1;
                if(!answer[i][item-'a']) g = 0;
            }
            for(int j = 0; j < 5; j++)
            {
                if(answer[i][j]^solu[j])
                {
                    result[i][j]++;
                    if(max < result[i][j]) max = result[i][j];
                }
            }
            score += g;
            cin >> item;
        }
        printf("%.1f\n", score);
    }

    if(max == 0) cout << "Too simple" << endl;
    else
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < answer[i][5]; j++)
            {
                if(result[i][j] == max)
                {
                    printf("%d %d-%c\n", max, i+1, 'a'+j);
                }
            }
        }
    }

    return 0;
}
