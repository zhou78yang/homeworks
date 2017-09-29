#include <iostream>
using namespace std;

#define N   10005

bool isPrimer(int x)
{
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(int i = 3; i * i <= x; i+= 2)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    int n, rank[N], id;
    bool book[N] = {0}, join[N] = {0};

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> id;
        rank[id] = i;
        join[id] = true;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id;
        if(!join[id])
        {
            printf("%04d: Are you kidding?\n", id);
            continue;
        }
        if(book[id]) 
        {
            printf("%04d: Checked\n", id);
            continue;
        }
        book[id] = true;
        if(rank[id] == 1) printf("%04d: Mystery Award\n", id);
        else if(isPrimer(rank[id])) printf("%04d: Minion\n", id);
        else printf("%04d: Chocolate\n", id);
    }

    return 0;
}
