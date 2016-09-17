#include <iostream>
using namespace std;

#define N   10005


void siftup(int *heap, int i)
{
    while(i && heap[i] < heap[i/2])
    {
        swap(heap[i], heap[i/2]);
        i /= 2;
    }
}

void siftdown(int *heap, int i, int n)
{
    int tmp;

    while(i <= n/2)
    {
        tmp = i * 2;
        if(tmp < n && heap[tmp] > heap[tmp+1])
        {
            tmp += 1;
        }

        if(heap[i] > heap[tmp])
        {
            swap(heap[i], heap[tmp]);
            i = tmp;
        }
        else break;
    }
}

void creatU(int *heap, int *arr, int n)
{
    for(int i = 1; i <= n; i++)
    {
        heap[i] = arr[i];
        siftup(heap, i);
    }
}

void creatD(int *heap, int n)
{
    for(int i = n/2; i > 0; i--)
    {
        siftdown(heap, i, n);
    }
}

void heapsort(int *heap, int n)
{
    for(int i = n/2; i > 0; i--)
    {
        siftdown(heap, i, n);
    }
    
    while(n > 1)
    {
        swap(heap[1], heap[n]);
        n--;
        siftdown(heap, 1, n);
    }
}

int main()
{
    int arr[N], n;
    int heap[N];

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    creatU(heap, arr, n);
    creatD(arr, n);

    cout << "create by sift up: ";
    for(int i = 1; i <= n; i++) cout << heap[i] << " ";
    cout << endl;
    cout << "create by sift down: ";
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;

    heapsort(heap, n);
    cout << "sorted : ";
    for(int i = 1; i <= n; i++) cout << heap[i] << " ";
    cout << endl;

    return 0;
}
        
