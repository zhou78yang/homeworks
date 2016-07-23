#include <iostream>
using namespace std;

int main()
{
    int N, M;
    char id[1005][15];
    int table[1005], sit[1005];
    int tmp;

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> id[i] >> tmp >> sit[i];
        table[tmp] = i;
    }

    cin >> M;
    for(int i = 1; i <= M; i++)
    {
        cin >> tmp;
        tmp = table[tmp];
        cout << id[tmp] << " " << sit[tmp] << endl;
    }

    return 0;
}
