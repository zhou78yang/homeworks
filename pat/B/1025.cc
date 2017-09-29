#include <iostream>
using namespace std;

#define N   100005

struct Node
{
    int data, next;
};

int main()
{
    int head, n, k, addr;
    Node list[N];

    cin >> head >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> addr;
        cin >> list[addr].data >> list[addr].next;
    }

    int len = 0, order[N];
    for(int i = head; i != -1; i = list[i].next)
    {
        order[++len] = i;
    }

    for(int i = 0; (i+1)*k <= len; i++)
    {
        int l = i*k+1, r = (i+1)*k;
        while(l < r) swap(order[l++], order[r--]);
    }
    
    printf("%05d %d ", order[1], list[order[1]].data);
    for(int i = 2; i <= len; i++) printf("%05d\n%05d %d ", order[i], order[i], list[order[i]].data);
    cout << "-1\n";

    return 0;
}
