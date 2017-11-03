#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N   10005

vector<int> tree[N];
bool book[N] = {0};

void travel(int from, int cur)
{
    for(auto e : tree[cur])
    {
        if(e == from || book[e]) continue;
        book[e] = true;
        travel(cur, e);
    }
}

int getDeep(int from, int cur)
{
    int d = 0;
    for(auto e : tree[cur])
    {
        if(e == from) continue;
        int t = getDeep(cur, e);
        if(t > d) d = t;
    }
    return d+1;
}

int main()
{
    int n, a, b;

    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int count = 0;        
    for(int i = 1; i <= n; i++)
    {
        if(!book[i])
        {
            book[i] = true;
            count++;
            travel(0, i);
        }
    }
    if(count > 1) cout << "Error: " << count << " components\n";
    else
    {
        vector<int> deepest;
        int max = 0;
        for(int i = 1; i <= n; i++)
        {
            if(tree[i].size() == 1)
            {
                int d = getDeep(0, i);
                if(d > max)
                {
                    max = d;
                    deepest.clear();
                    deepest.push_back(i);
                }
                else if(d == max)
                {
                    deepest.push_back(i);
                }
            }
        }
        sort(deepest.begin(), deepest.end());
        for(auto e : deepest) cout << e << endl;
    }

    return 0;
}

