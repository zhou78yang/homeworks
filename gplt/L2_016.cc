#include <iostream>
#include <cstdio>
using namespace std;

#define N       100005

struct Person {
    char sex;
    int f_id = -1; 
    int m_id = -1;
} P[N];

bool check(int a, int b, int n)
{
    if(n == 0 || a == -1 || b == -1) return true;

    if(a == b) return false;

    int f1 = P[a].f_id, f2 = P[b].f_id;
    int m1 = P[a].m_id, m2 = P[b].m_id;

    return check(f1, f2, n-1) && check(f1, m2, n-1)
        && check(m1, f2, n-1) && check(m1, m2, n-1);
}

int main()
{
    int n, k, id, f_id, m_id;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id;
        cin >> P[id].sex >> f_id >> m_id;
        P[id].f_id = f_id;
        P[id].m_id = m_id;
        P[f_id].sex = 'M';
        P[m_id].sex = 'F';
    }

    int a, b;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> a >> b;
        if(P[a].sex == P[b].sex) cout << "Never Mind" << endl;
        else if(check(a, b, 5)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

