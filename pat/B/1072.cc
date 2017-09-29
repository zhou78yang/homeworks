#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, id, k;
    bool book[10000] = {0};
    char name[5];

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> id;
        book[id] = true;
    }

    int total_t = 0, total_s = 0;
    string line;
    cin.getline(name, 5);
    while(n-- > 0)
    {
        bool has = false;
        getline(cin, line);
        istringstream in(line);
        in >> name >> k;
        while(k-- > 0)
        {
            in >> id;
            if(book[id])
            {
                if(!has) cout << name << ":";
                has = true;
                total_t++;
                printf(" %04d", id);
            }
        }
        if(has)
        {
            total_s++;
            cout << endl;
        }
    }
    cout << total_s << " " << total_t << endl;

    return 0;
}
