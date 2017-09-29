#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> table1;
    map<string, int> table2;
    string digit1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                                 "jly", "aug", "sep", "oct", "nov", "dec"};
    string digit2[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes",
                             "hei", "elo", "syy", "lok", "mer", "jou"};
    for(int i = 0; i < 13; i++)
    {
        table1.insert(pair<string, int>(digit1[i], i));
        table2.insert(pair<string, int>(digit2[i], i));
    }

    int T;
    string line;
    cin >> T;
    getline(cin, line);
    while(T-- > 0)
    {
        getline(cin, line);
        if(line[0] <= '9' && line[0] >= '0')
        {
            int num = 0;
            for(int i = 0; i < line.size(); i++)
            {
                num = 10*num + (line[i]-'0');
            }

            if(num < 13) cout << digit1[num] << endl;
            else
            {
                cout << digit2[num/13];
                if(num % 13 == 0) cout << endl;
                else cout << " " << digit1[num%13] << endl;
            }
        }
        else if(line.size() == 3)
        {
            if(table1.find(line) == table1.end()) cout << 13*table2[line] << endl;
            else cout << table1[line] << endl;
        }
        else
        {
            string tmp = line.substr(0, 3);
            int num = table2[tmp] * 13;
            tmp = line.substr(4, 7);
            num += table1[tmp];
            cout << num << endl;
        }
    }


    return 0;
}
