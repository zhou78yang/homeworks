#include <iostream>
using namespace std;

int book[10][3] = {0};
int len = 0;

bool check(int a, int b, int c)
{
    if(c < 0 || b < 1) return false;
    if(b == 1 && a == c) return true;
    return check(a, b-1, c-a);
}

int main()
{
    int n;
    char s[105];

    cin >> n;
    for(int k = 0; k < n; k++)
    {
        cin >> s;
        int i = 0, j = 0, a[3] = {0};
        char sep[3] = "PT";
        bool result = true;

        while(s[i] != '\0')
        {
            if(s[i] != 'A')
            {
                if(s[i] == sep[j])
                {
                    a[j++] = i;
                }
                else
                {
                    result = false;
                    break;
                }
            }
            i++;
        }
        a[2] = i;

        if(result) result = check(a[0], a[1]-a[0]-1, a[2]-a[1]-1);
        if(result)
        {
            cout << "YES\n";
            book[len][0] = a[0];
            book[len][1] = a[1]-a[0]-1;
            book[len][2] = a[2]-a[1]-1;
            len++;
        }
        else cout << "NO\n";
    }
    return 0;
}
            



