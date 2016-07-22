#include <iostream>
using namespace std;

int pos[10005] = {0};
int in_order[10005] = {0};
bool hasIn[10005] = {0};

int main()
{
    int n, p;
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p;
        in_order[i] = p;
        pos[p] = i;
    }

    int len = 1, num = 0;
    int obj = n;
    for(int i = 1; i <= n; i++)
    {
        num++;                  // train in
        hasIn[in_order[i]] = true;
        if(in_order[i] == obj)
        {
            obj--; num--;
            while(hasIn[obj] && obj > 0)
            {
                obj--; num--;
            }
        }
        else
        {
            // add a wait train
            num++;
            if(len < num) len = num;
        }
    }
    cout << len << endl;
    return 0;
}
        
    
