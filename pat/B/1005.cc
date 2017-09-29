#include <iostream>
#include <algorithm>
using namespace std;

bool book[105] = {0};

void callatz(int x)
{
    if(x == 1) return ;

    int child = x % 2 == 0 ? x/2 : (3*x+1)/2;

	if(child <= 100)
	{
        if(book[child]) return;
		book[child] = true;
    }
	callatz(child);
}

int main()
{
    int n, A[100];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        callatz(A[i]);
    }

    int key[100], len = 0;
    for(int i = 0; i < n; i++)
    {
        if(!book[A[i]])
        {
            key[len++] = A[i];
        }
    }
    sort(key, key+len);
    for(int i = len-1; i > 0; i--) cout << key[i] << " ";
    cout << key[0] << endl;

    return 0;
}

