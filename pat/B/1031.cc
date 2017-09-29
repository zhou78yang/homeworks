#include <iostream>
using namespace std;

int main()
{
    int n, weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}, z;
    char id[20], code[12] = "10X98765432";
    bool all_right = true;

    cin >> n;
    cin.getline(id, 20);
    while(n-- > 0)
    {
        bool fack = false;
        cin.getline(id, 20);
        z = 0;
        for(int i = 0; i < 17; i++)
        {
            if(id[i] == 'X')
            {
                fack = true;
                break;
            }
            z += (id[i] - '0') * weight[i];
        }
        z %= 11;
        if(code[z] != id[17]) fack = true;
        if(fack)
        {
            cout << id << endl;
            all_right = false;
        }
    }
    if(all_right) cout << "All passed\n";

    return 0;
}

