#include <iostream>
#include <vector>
#include <map>
using namespace std;

int book[100], len = 0;
map<int, vector<int>> list;

void dfs(int id, int level)
{
    if(level > len) len = level;
    if(list[id].empty())
    {
        book[level]++;
        return;
    }
    for(auto e : list[id])
    {
        dfs(e, level+1);
    }
}

int main()
{
    int n, m, k, p_id, c_id;

    cin >> n >> m;
    while(m-- > 0)
    {
        cin >> p_id >> k;
        while(k-- > 0)
        {
            cin >> c_id;
            list[p_id].push_back(c_id);
        }
    }

    dfs(1, 0);
    for(int i = 0; i < len; i++) cout << book[i] << " ";
    cout << book[len] << endl;

    return 0;
}
