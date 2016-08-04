#include <iostream>
using namespace std;

int table[25][15] = {0}, block[4][4];

bool check(int l, int s)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(table[l+i][s+j] && block[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int shift;

    // input
    for(int i = 5; i < 20; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            cin >> table[i][j];
        }
    }
    for(int i = 1; i <= 10; i++) table[20][i] = 1;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> block[i][j];
        }
    }
    cin >> shift;

    // process
    for(int l = 1; l < 20; l++)
    {
        if(!check(l+1, shift))
        {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    table[l+i][shift+j] += block[i][j];
                }
            }
            break;
        }
    }

    // output
    for(int i = 5; i < 20; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

