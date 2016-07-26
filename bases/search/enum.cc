#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n, a, b, c;
    double tmp;

    while(cin >> n)
    {
        a = b = c = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            if(tmp < 0.0) a++;
            else if(tmp == 0.0) b++;
            else c++;
        }
        cout << "a: " << a << "\tb: " << b << "\tc: " << c << endl;
    }

    return 0;
}
