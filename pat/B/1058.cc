#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

#define N   1005
#define M   105

int main()
{
    int n, m;
    int answer[M][7] = {0}, result[M] = {0};
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
    int score;
    string line;
    while(n-- > 0)
    {
        score = 0;
        getline(cin, line);
        istringstream in(line);
        for(int i = 0; i < m; i++)
        {
            int g = goal[i];
            cin >> item >> k;

            if(k < answer[i][6]) g = 0;
            for(int j = 0; j < k; j++)
            {
                cin >> item;
                if(!answer[i][item-'a']) g = 0;
            }
            if(g == 0)
            {
                result[i]++;
                if(max < result[i]) max = result[i];
            }
            score += g;
            cin >> item;
        }
        cout << score << endl;
    }


    if(max == 0) cout << "Too simple" << endl;
    else
    {
        cout << max;
        for(int i = 0; i < m; i++)
        {
            if(result[i] == max)
            {
                cout << " " << i+1;
            }
        }
        cout << endl;
    }

    return 0;
}
