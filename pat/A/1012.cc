#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;

#define A       0
#define C       1
#define M       2
#define E       3

struct Student
{
    int id, score[4], rank[4];
};

bool cmpA(Student &a, Student &b)
{
    return a.score[A] > b.score[A];
}

bool cmpC(Student &a, Student &b)
{
    if(a.score[C] > b.score[C]) return true;
    for(int i = 1; i < 4; i++) 
    {
        if(a.score[i] > b.score[i]) return true;
        else return false;
    }
    return a.id < b.id;
}

bool cmpM(Student &a, Student &b)
{
    if(a.score[M] > b.score[M]) return true;
    for(int i = 1; i < 4; i++) 
    {
        if(a.score[i] > b.score[i]) return true;
        else return false;
    }
    return a.id < b.id;
}

bool cmpE(Student &a, Student &b)
{
    if(a.score[E] > b.score[E]) return true;
    for(int i = 1; i < 4; i++) 
    {
        if(a.score[i] > b.score[i]) return true;
        else return false;
    }
    return a.id < b.id;
}


int main()
{
    int n, m, id;
    Student S[2005];

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> S[i].id >> S[i].score[C] >> S[i].score[M] >> S[i].score[E];
        S[i].score[A] = (S[i].score[C] + S[i].score[M] + S[i].score[E]) / 3;
    }

    sort(S, S+n, cmpA);
    for(int i = 0; i < n; i++) S[i].rank[A] = i+1;
    sort(S, S+n, cmpC);
    for(int i = 0; i < n; i++) S[i].rank[C] = i+1;
    sort(S, S+n, cmpM);
    for(int i = 0; i < n; i++) S[i].rank[M] = i+1;
    sort(S, S+n, cmpE);
    for(int i = 0; i < n; i++) S[i].rank[E] = i+1;

    //for(int i = 0; i < n; i++) printf("%06d score: %d %d %d %d rank: %d %d %d %d\n", S[i].id, S[i].score[A], S[i].score[C], S[i].score[M], S[i].score[E], S[i].rank[A], S[i].rank[C], S[i].rank[M], S[i].rank[E]);   
    map<int, tuple<int, char>> book;
    char code[] = "CMEA";
    for(int i = 0; i < n; i++)
    {
        int top = 0;
        for(int j = 1; j <= 3; j++) 
        {
            if(S[i].rank[j] < S[i].rank[top]) top = j;
        }
        book[S[i].id] = tuple<int, char>(S[i].rank[top], code[top]);
    }

    while(m-- > 0)
    {
        cin >> id;
        auto ite = book.find(id);
        if(ite == book.end()) cout << "N/A\n";
        else cout << get<0>(ite->second) << " " << get<1>(ite->second) << endl;
    }

    return 0;
}
