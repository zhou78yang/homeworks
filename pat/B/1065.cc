#include <iostream>
#include <algorithm>
using namespace std;

#define DELTA   1
#define N       100005

int main()
{
    int couple[N] = {0};
    int n, id1, id2;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id1 >> id2;
        couple[id1+DELTA] = id2+DELTA;
        couple[id2+DELTA] = id1+DELTA;
    }

    bool present[N] = {0};
    int guest[10005];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> guest[i];
        present[guest[i]+DELTA] = true;
    }

    int single[10005], len = 0;
    for(int i = 0; i < n; i++)
    {
        if(couple[guest[i]+DELTA] == 0) single[len++] = guest[i];
        else if(!present[couple[guest[i]+DELTA]]) single[len++] = guest[i];
    }

    sort(single, single+len);
    cout << len << endl;
    if(len)
    {
        printf("%05d", single[0]);
        for(int i = 1; i < len; i++) printf(" %05d", single[i]);
		cout << endl;
    }

    return 0;
}
