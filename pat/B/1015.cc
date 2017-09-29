#include <iostream>
#include <algorithm>
using namespace std;

#define N   100005

struct Student
{
    int id, sum;
    int de, cai;
};

bool comp(Student a, Student b)
{
    return a.sum > b.sum || (a.sum == b.sum && a.de > b.de) ||
        (a.sum == b.sum && a.de == b.de && a.id < b.id);
}

int main()
{
    int n, L, H, id, de, cai;
    Student kind[4][N];
    int len[4] = {0};

    cin >> n >> L >> H;
    while(n-- > 0)
    {
        cin >> id >> de >> cai;
        if(de >= H && cai >= H)
        {
            kind[0][len[0]].id = id;
            kind[0][len[0]].de = de;
            kind[0][len[0]].cai = cai;
            kind[0][len[0]].sum = de + cai;
            len[0]++;
        }
        else if(de >= H && cai >= L)
        {
            kind[1][len[1]].id = id;
            kind[1][len[1]].de = de;
            kind[1][len[1]].cai = cai;
            kind[1][len[1]].sum = de + cai;
            len[1]++;
        }
        else if(de >= L && cai >= L)
        {
            if(de >= cai)
            {
                kind[2][len[2]].id = id;
                kind[2][len[2]].de = de;
                kind[2][len[2]].cai = cai;
                kind[2][len[2]].sum = de + cai;
                len[2]++;
            }
            else
            {
                kind[3][len[3]].id = id;
                kind[3][len[3]].de = de;
                kind[3][len[3]].cai = cai;
                kind[3][len[3]].sum = de + cai;
                len[3]++;
            }
        }
    }

    for(int i = 0; i < 4; i++) sort(kind[i], kind[i]+len[i], comp);

    cout << len[0]+len[1]+len[2]+len[3] << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < len[i]; j++) 
        {
            printf("%08d %d %d\n", kind[i][j].id, kind[i][j].de, kind[i][j].cai);
        }
    }

    return 0;
}
