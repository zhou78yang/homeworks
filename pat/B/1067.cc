#include <iostream>
#include <sstream>
using namespace std;

bool comp(char *a, char *b)
{
    int i = 0;
    for( ;a[i] != '\0'; i++)
    {
        if(a[i] != b[i]) return false;
    }

    return b[i] == '\0';
}

int main()
{
    int n;
    char psw[25], input[80];
    string line;

    getline(cin, line);
    istringstream in(line);
    in >> psw >> n;
    while(true)
    {
        cin.getline(input, 80);
        if(input[0] == '#' && input[1] == '\0') break;
        if(comp(psw, input))
        {
            cout << "Welcome in\n";
            break;
        }
        else
        {
            cout << "Wrong password: " << input << endl;
            if(--n == 0)
            {
                cout << "Account locked\n";
                break;
            }
        }
    }

    return 0;
}

