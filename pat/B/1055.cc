#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Person
{
    int height;
    string name;
};

bool comp(Person a, Person b)
{
    return a.height > b.height || (a.height == b.height && a.name < b.name);
}

Person *setLine(Person *P, int m)
{
    int order[10005] = {0};
    int left = m/2-1, right = m/2, i = 0;

    order[right++] = i++;
    while(i < m)
    {
        order[left--] = i++;
        order[right++] = i++;
    }
    cout << P[order[0]].name;
    for(int i = 1; i < m; i++) cout << " " << P[order[i]].name;
    cout << endl;

    return P+m;
}

int main()
{
    int n, k, m;
    Person P[10005];

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> P[i].name >> P[i].height;
    sort(P, P+n, comp);

    m = n / k;
    Person *p = setLine(P, m+n%k);
    for(int i = 1; i < k; i++)
    {
        p = setLine(p, m);
    }

    return 0;
}
