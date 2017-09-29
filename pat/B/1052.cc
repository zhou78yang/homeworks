#include <iostream>
#include <sstream>
using namespace std;

#define HAND    0
#define EYE     1
#define MOUTH   2

int main()
{
    char set[3][12][5];
    int len[3] = {0};
    string line;

    for(int i = 0; i < 3; i++)
    {
        getline(cin, line);
        istringstream in(line);
        char term;
        int index = 1;
        while(in >> term)
        {
            if(term == '[')
            {
                int l = 0;
                do
                {
                    in >> term;
                    set[i][index][l++] = term;
                } while(term != ']');
                set[i][index][l-1] = '\0';
                index++;
            }
        }
        len[i] = index-1;
    }
    
    int T, lhand, rhand, leye, reye, mouth;
    cin >> T;
    while(T-- > 0)
    {
        cin >> lhand >> leye >> mouth >> reye >> rhand;
        if(lhand > len[HAND] || rhand > len[HAND] || lhand < 1 || rhand < 1 ||
            leye > len[EYE] || reye > len[EYE] || leye < 1 || reye < 1 ||
            mouth > len[MOUTH] || mouth < 1)
        {
            cout << "Are you kidding me? @\\/@" << endl;
        }
        else
        {
            cout << set[HAND][lhand] << "(" << set[EYE][leye] << set[MOUTH][mouth] 
                 << set[EYE][reye] << ")" << set[HAND][rhand] << endl;
        }
    }

    return 0;
}
