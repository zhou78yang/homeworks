#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n, sep, s;
    map<string, int> list;
    string name;

    cin >> n >> sep >> s;

    n -= s;
    if(n < 0) cout << "Keep going...\n";
    else
    {
        while(s-- > 0) cin >> name;
        cout << name << endl;
        list.insert(pair<string, int>(name, 1));
    }

    int index = 1;
    while(n-- > 0 && cin >> name)
    {
        if(index < sep) index++;
        else
        {
            if(list.find(name) == list.end())
            {
                list.insert(pair<string, int>(name, 1));
                cout << name << endl;
                index = 1;
            }
        }
    }

    return 0;
}
