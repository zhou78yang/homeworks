#include <iostream>
using namespace std;

void merge(int *A, int lo, int mi, int hi)
{
    int len = 0, j = 0, k = mi, tmp[105];
    for(int i = lo; i < mi; i++) tmp[len++] = A[i];

    for(int i = lo; i < hi; i++)
    {
        if(tmp[j] <= A[k])
        {
            if(j >= len) break;
            A[i] = tmp[j];
            j++;
        }
        else
        {
            if(k >= hi) break;
            A[i] = A[k];
            k++;
        }
    }
    if(j < len)
    {
        for(int i = 1; i <= len-j; i++) A[hi-i] = tmp[len-i];
    }
}
        
void mergeSort(int *A, int n, int *B)
{
    bool match = false;
    for(int k = 1; k < n; k <<= 1)
    {
        for(int i = 0; i+k < n; i += k<<1)
        {
            merge(A, i, i+k, min(i+k+k, n));
        }
        match = true;
        for(int i = 0; i < n; i++)
        {
            if(A[i] != B[i])
            {
                match = false;
                break;
            }
        }
        if(match)
        {
            k <<= 1;
            for(int i = 0; i+k < n; i += k<<1)
            {
                merge(B, i, i+k, min(i+k+k, n));
            }
            break;
        }
    }
}


int main()
{
    int n, A[105], tmp[105];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> tmp[i];

    bool insert = true;
    int index;
    for(int i = 1; i < n; i++)
    {
        if(tmp[i] < tmp[i-1])
        {
            index = i;
            break;
        }
    }
    for(int i = index; i < n; i++)
    {
        if(A[i] != tmp[i])
        {
            insert = false;
            break;
        }
    }

    if(insert)
    {
        cout << "Insertion Sort\n";
        for(int i = index; i > 0; i--)
        {
            if(tmp[i] < tmp[i-1])
            {
                swap(tmp[i], tmp[i-1]);
            }
            else break;
        }
    }
    else
    {
        cout << "Merge Sort\n";
        mergeSort(A, n, tmp);
    }

    cout << tmp[0];
    for(int i = 1; i < n; i++) cout << " " << tmp[i];
    cout << endl;
    
    return 0;
}
