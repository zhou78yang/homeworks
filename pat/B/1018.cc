#include <iostream>
#include <map>
using namespace std;

#define WIN     0
#define LOSE    1
#define DRAW    2

int main()
{
    int T, A[3] = {0}, B[3] = {0}, type[2][3] = {0}, max[2] = {0};
    char a, b, gesture[] = "BCJ";
    map<char, int> score;
    for(int i = 0; i < 3; i++) score.insert(pair<char, int>(gesture[i], i));

    cin >> T;
    while(T-- > 0)
    {
        cin >> a >> b;
        int r = score[a] - score[b];
        switch(r)
        {
        case 0:
            A[DRAW]++; B[DRAW]++;
            break;
        case 1: case -2:
            // a lose
            A[LOSE]++; B[WIN]++;
            type[1][score[b]]++;
            if(max[1] < type[1][score[b]]) max[1] = type[1][score[b]];
            break;
        case 2: case -1:
            // a win
            A[WIN]++; B[LOSE]++;
            type[0][score[a]]++;
            if(max[0] < type[0][score[a]]) max[0] = type[0][score[a]];
            break;
        }
    }

    cout << A[WIN] << " " << A[DRAW] << " " << A[LOSE] << endl;
    cout << B[WIN] << " " << B[DRAW] << " " << B[LOSE] << endl;
    for(int i = 0; i < 3; i++)
    {
        if(max[0] == type[0][i])
        {
            cout << gesture[i] << " ";
            break;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(max[1] == type[1][i])
        {
            cout << gesture[i] << endl;
            break;
        }
    }

    return 0;
}

