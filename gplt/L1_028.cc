#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, num, limit;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        bool is_prime = true;
        cin >> num;
        limit = sqrt(num) + 1;
        
        if(num == 2)
        {
            cout << "Yes" << endl;
            continue;
        }
        if(num % 2 == 0 || num == 1)
        {
            cout << "No" << endl;
            continue;
        }

        for(int i = 3; i < limit; i+=2)
        {
            if(num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
