#include <iostream>
#include <vector>
using namespace std;

vector<int> table[1005];
bool book[1005] = {0};

void dfs(int from, int limit)
{
    for(auto e : table[from])
    {
        if(!book[e] && e != limit)
        {
            book[e] = true;
            dfs(e, limit);
        }
    }
}

int main()
{
    int n, m, k, c1, c2;
    cin >> n >> m >> k;
    while(m-- > 0)
    {
        cin >> c1 >> c2;;
        table[c1].push_back(c2);
        table[c2].push_back(c1);
    }

    while(k-- > 0)
    {
        int limit, count = 0;
        cin >> limit;
        for(int i = 0; i <= n; i++) book[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!book[i] && i != limit)
            {
                count++;
                book[i] = true;
                dfs(i, limit);
            }
        }
        cout << count-1 << endl;
    }

    return 0;
} 
