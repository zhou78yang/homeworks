#include <iostream>
#include <string>
using namespace std;

#define N       1005
#define DELTA   10000

int heap[N] = {0};
int posi[20005] = {0};

void siftup(int x)
{
    for(int i = x; i > 1 && heap[i] < heap[i/2]; i/=2)
    {
        swap(heap[i], heap[i/2]);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> heap[i];
        siftup(i);
    }
    for(int i = 1; i <= n; i++)
    {
        posi[heap[i]+DELTA] = i;
    }

    int x, y;
    string word;

    for(int i = 0; i < m; i++)
    {
        cin >> x;
        cin >> word;
        if(word[0] == 'a')
        {
            // x and y are siblings
            cin >> y >> word >> word;
            if(posi[x+DELTA]/2 == posi[y+DELTA]/2) cout << "T\n";
            else cout << "F\n";
        }
        else
        {
            cin >> word;
            if(word[0] == 'a')
            {
                // x is a child of y
                cin >> word >> word >> y;
                if(posi[x+DELTA]/2 == posi[y+DELTA]) cout << "T\n";
                else cout << "F\n";
            }
            else
            {
                cin >> word;
                if(word[0] == 'r')
                {
                    // x is the root;
                    if(posi[x+DELTA] == 1) cout << "T\n";
                    else cout << "F\n";
                }
                else
                {
                    // x is the parent of y
                    cin >> word >> y;
                    if(posi[x+DELTA] == posi[y+DELTA]/2) cout << "T\n";
                    else cout << "F\n";
                }
            }// x is the
        }// x is
    }

    return 0;
}
                
