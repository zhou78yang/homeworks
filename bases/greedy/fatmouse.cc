// FatMouse's Trade.
/*
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct inp
{
    int j, f;
    double c;
    bool operator < (const inp &i){ return c < i.c; }
    bool operator > (const inp &i){ return c > i.c; }
    bool operator <=(const inp &i){ return c <= i.c;}
    bool operator >=(const inp &i){ return c >= i.c;}
} node[1005];


int main(int argc, char *argv[])
{
    int n, m;
    while(cin >> m >> n)
    {
        if(n == -1 || m == -1) break;
        for(int i = 0; i < n; i++)
        {
            cin >> node[i].j >> node[i].f;
            node[i].c = (double)node[i].j / (double)node[i].f;
        }
        sort(node, node + n);
        reverse(node, node + n);
        double j = 0.0;
        for(int i = 0; i < n; i++)
        {
            if(node[i].f <= m)
            {
                m -= node[i].f;
                j += node[i].j;
            }
            else
            {
                j += m * node[i].c;
                break;
            }
            cout << j << endl;
        }
    }

    return 0;
}
