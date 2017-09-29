#include <iostream>
using namespace std;

#define N   100

int main()
{
    char a1[N], a2[N], b1[N], b2[N];
    bool hasFoundDay = false;
    string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    cin.getline(a1, 60);
    cin.getline(b1, 60);
    cin.getline(a2, 60);
    cin.getline(b2, 60);

    for(int i = 0; a1[i] != '\0' && b1[i] != '\0'; i++)
    {
        if(a1[i] == b1[i])
        {
            if(!hasFoundDay)
            {
                if(a1[i] >= 'A' && a1[i] <= 'G')
                {
                    cout << day[a1[i]-'A'] << " ";
                    hasFoundDay = true;
                }
            }
            else
            {
                if(a1[i] >= '0' && a1[i] <= '9')
                {
                    cout << "0" << a1[i] << ":";
                    break;
                }
                else if(a1[i] >= 'A' && a1[i] <= 'N')
                {
                    int h = a1[i] - 'A' + 10;
                    cout << h << ":";
                    break;
                }
            }
        }
    }

    for(int i = 0; a2[i] != '\0' && b2[i] != '\0'; i++)
    {
        if(isalpha(a2[i]) && a2[i] == b2[i])
        {
            if(i < 10) cout << "0" << i << endl;
            else cout << i << endl;
            break;
        }
    }

    return 0;
}

