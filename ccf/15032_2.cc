#include <iostream>
#include <cstring>
using namespace std;

struct {
    int val;
    int count;
} input[1005];
int len;

void check(int n)
{
    for(int i = 0; i < len; i++)
    {
        if(input[i].val == n)
        {
            input[i].count++;
            return ;
        }
    }
    input[len].val = n;
    input[len].count = 1;
    len++;
}

int main()
{
    int n, tmp;
    len = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        check(tmp);
    }
    for(int i = 0; i < len; i++)
    {
        int max = i;
        for(int j = i+1; j < len; j++)
        {
            if((input[max].count < input[j].count)||(input[max].count == input[j].count && input[max].val > input[j].val))
            {
                max = j;
            }
        }
        cout << input[max].val << " " << input[max].count << endl;
        input[max].val = input[i].val; input[max].count = input[i].count;
    }
    return 0;
}
