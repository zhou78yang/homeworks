#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int n, m, k, q, take[1005], id;
    queue<int> inzone[21];
    queue<int> line;
    map<int, int> query;

    cin >> n >> m >> k >> q;
    for(int i = 1; i <= k; i++) cin >> take[i];

    int count = 0;
    for(int i = 0; i < m && count < k; i++)
    {
        for(int j = 0; j < n && count < k; j++)
        {
            inzone[j].push(++count);
        }
    }
    while(count < k) line.push(++count);

    // 17:00开始不接受新请求
    for(int t = 1; t < 540; t++)
    {
        for(int i = 0; i < n; i++)
        {
            if(inzone[i].empty()) continue;
            take[inzone[i].front()]--;
            if(take[inzone[i].front()] <= 0)
            {
                query[inzone[i].front()] = t;
                inzone[i].pop();
                if(!line.empty())
                {
                    inzone[i].push(line.front());
                    line.pop();
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(inzone[i].empty()) continue;
        query[inzone[i].front()] = 540+take[inzone[i].front()]-1;
    }

    while(q-- > 0)
    {
        cin >> id;
        auto iter = query.find(id);
        if(iter != query.end())
        {
            int h = iter->second / 60 + 8, m = iter->second % 60;
            printf("%02d:%02d\n", h, m);
        }
        else cout << "Sorry\n";
    }

    return 0;
}
