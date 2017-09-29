#include <iostream>
using namespace std;

struct Table 
{
    int id;
    int set;
};

int main()
{
    int n, m, test;
    char id[1005][15];
    Table table[1005];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id[i];
        cin >> test;
        cin >> table[test].set;
        table[test].id = i;
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> test;
        cout << id[table[test].id] << " " << table[test].set << endl;
    }
    
    return 0;
}
