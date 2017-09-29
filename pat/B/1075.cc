#include <iostream>
#include <iostream>
using namespace std;

#define N       100000
struct Node
{
    int data, next;
};

int main()
{
    int old_head, n, k, addr, data, next;
    Node list[N];

    cin >> old_head >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> addr >> data >> next;
        list[addr].data = data;
        list[addr].next = next;
    }

    int order[N], order_0[N], order_k[N], len, len_0, len_k;
    len = len_0 = len_k = 0;
    for(int i = old_head; i != -1; i = list[i].next)
    {
        if(list[i].data < 0)
        {
            order[len++] = i;
        }
        else if(list[i].data <= k)
        {
            order_0[len_0++] = i;
        }
        else
        {
            order_k[len_k++] = i;
        }
    }
    for(int i = 0; i < len_0; i++) order[len++] = order_0[i];
    for(int i = 0; i < len_k; i++) order[len++] = order_k[i];

    printf("%05d %d ", order[0], list[order[0]].data);
    for(int i = 1; i < len; i++) printf("%05d\n%05d %d ", order[i], order[i], list[order[i]].data);
    cout << "-1\n";

    return 0;
}

