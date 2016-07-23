#include <iostream>
using namespace std;

int main()
{
    char boys[30][10], girls[30][10];
    int n, sex[55];
    int bl = 0, gl = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> sex[i];
        if(sex[i] == 1)
        {
            cin >> boys[bl++];
        }
        else
        {
            cin >> girls[gl++];
        }
    }

    int bi = 0, gi = 0;
    for(int i = 0; i < n/2; i++)
    {
        if(sex[i] == 1)
        {
            cout << boys[bi++] << " " << girls[--gl] << endl;
        }
        else
        {
            cout << girls[gi++] << " " << boys[--bl] << endl;
        }
    }
    
    return 0;
}
