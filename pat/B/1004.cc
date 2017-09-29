#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    char name[12];
    char id[12];
    int score;
};

int main()
{
    Student A[105];
    int n, min = 0, max = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i].name >> A[i].id >> A[i].score;
    }
    for(int i = 1; i < n; i++)
    {
        if(A[i].score > A[max].score) max = i;
        if(A[i].score < A[min].score) min = i;
    }
    cout << A[max].name << " " << A[max].id << endl;
    cout << A[min].name << " " << A[min].id << endl;

    return 0;
}
