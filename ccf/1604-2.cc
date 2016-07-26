#include <iostream>
using namespace std;

int shift;
int map[25][12] = {0}, block[4][4];

bool can_place(int l)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(block[i][j] && map[l+i][j+shift])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    for(int i = 4; i < 19; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> block[i][j];
        }
    }
    cin >> shift;

    int l = 1, bottom = 15;
    for(int i = 3; i >= 0; i--)
    {
        bool flag = true;
        for(int j = 0; j < 4; j++)
        {
            if(block[i][j])
            {
                flag = false;
                break;
            }
        }
        if(flag) bottom++;
        else break;
    }

    while(can_place(l) && l <= bottom) l++;

    l--;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[l+i][shift+j] += block[i][j];
        }
    }

    for(int i = 4; i < 19; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

