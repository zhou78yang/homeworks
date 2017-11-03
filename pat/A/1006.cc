#include <iostream>
using namespace std;

struct Time
{
    int h, m, s;
    Time(int h_, int m_, int s_)
        : h(h_), m(m_), s(s_)
    {}
    bool operator < (const Time &t)
    {
        return h < t.h || (h == t.h && m < t.m)
            || (h == t.h && m == t.m && s < t.s);
    }
    Time &operator = (const Time &t)
    {
        h = t.h; m = t.m; s = t.s;
        return *this;
    }
};

struct Vistor
{
    string id;
    Time in, out;
    Vistor():id(""), in(0,0,0), out(0,0,0){}
};


int main()
{
    Vistor P[10005];
    int n, h, m, s;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> P[i].id;
        scanf("%d:%d:%d", &h, &m, &s);
        P[i].in = Time(h, m, s);
        scanf("%d:%d:%d", &h, &m, &s);
        P[i].out = Time(h, m, s);
    }
    int earliest = 0, latest = 0;
    for(int i = 1; i < n; i++)
    {
        if(P[i].in < P[earliest].in) earliest = i;
        if(P[latest].out < P[i].out) latest = i;
    }

    cout << P[earliest].id << " " << P[latest].id << endl;

    return 0;
}

