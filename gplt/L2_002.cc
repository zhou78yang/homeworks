#include <iostream>
#include <cstdio>
using namespace std;

#define N   100000

int main()
{
    int n, first, addr;
    int key[N], next[N];
    bool book[N] = {0};

    cin >> first >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> addr;
        cin >> key[addr] >> next[addr];
    }

    int lr = 0, ld = 0;
    int val, rest[N], del[N];
    for(int i = first; i != -1; i = next[i])
    {
        val = key[i] < 0 ? -key[i] : key[i];
        
        if(book[val])
        {
            del[ld++] = i;
        }
        else
        {
            rest[lr++] = i;
            book[val] = true;
        }
    }

    printf("%05d %d ", rest[0], key[rest[0]]);
    for(int i = 1; i < lr; i++)
    {
        addr = rest[i];
        printf("%05d\n", addr);
        printf("%05d %d ", addr, key[addr]);
    }
    cout << -1 << endl;

    if(ld > 0)
    {
        printf("%05d %d ", del[0], key[del[0]]);
        for(int i = 1; i < ld; i++)
        {
            addr = del[i];
            printf("%05d\n", addr);
            printf("%05d %d ", addr, key[addr]);
        }
        cout << -1 << endl;
    }

    return 0;
}

