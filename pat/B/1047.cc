#include <iostream>
using namespace std;

int main()
{
    int n, team[1005] = {0};
    int t_id, p_id, score, max = 0;

    cin >> n;
    while(n-- > 0)
    {
        scanf("%d-%d %d", &t_id, &p_id, &score);
        team[t_id] += score;
        if(team[t_id] > team[max]) max = t_id;
    }
    cout << max << " " << team[max] << endl;

    return 0;
}
