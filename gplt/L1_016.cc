#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1,
                  6, 3, 7, 9, 10, 5, 8, 4, 2};
const char M[11] = {'1', '0', 'X', '9', '8', 
                    '7', '6', '5', '4', '3', '2'};

int main()
{
    int n;
    char id[20];
    bool all_passed = true;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> id;
        int check = 0;
        for(int j = 0; j < 17; j++)
        {
            if(id[j] == 'X')
            {
                cout << id << endl;
                all_passed = false;
                break;
            }
            check += weight[j] * (id[j] - '0');
        }

        if(M[check%11] != id[17])
        {
            cout << id << endl;
            all_passed = false;
        }
    }

    if(all_passed)
    {
        cout << "All passed" << endl;
    }

    return 0;
}

