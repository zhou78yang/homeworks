#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, vector<int>> findByTitle;
map<string, vector<int>> findByAuthor;
map<string, vector<int>> findByKeyword;
map<string, vector<int>> findByPub;
map<string, vector<int>> findByYear;

int main()
{
    int n, id, m, t;
    string title, author, keywords, publisher, year, keyword, line;

    scanf("%d\n", &n);
    while(n-- > 0)
    {
        scanf("%d\n", &id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);

        findByTitle[title].push_back(id);
        findByAuthor[author].push_back(id);
        istringstream sin(keywords);
        while(sin >> keyword) findByKeyword[keyword].push_back(id);
        findByPub[publisher].push_back(id);
        findByYear[year].push_back(id);
    }

    /* debug
    cout << "++++++++++++++++++++++++Title++++++++++++++++++++++++" << endl;
    for(auto it : findByTitle)
    {
        cout << it.first << ":";
        for(auto e : it.second) cout << " " << e;
        cout << endl;
    }
    cout << "++++++++++++++++++++++++Author++++++++++++++++++++++++" << endl;
    for(auto it : findByAuthor)
    {
        cout << it.first << ":";
        for(auto e : it.second) cout << " " << e;
        cout << endl;
    }
    cout << "++++++++++++++++++++++++Keyword++++++++++++++++++++++++" << endl;
    for(auto it : findByKeyword)
    {
        cout << it.first << ":";
        for(auto e : it.second) cout << " " << e;
        cout << endl;
    }
    cout << "++++++++++++++++++++++++Pub++++++++++++++++++++++++" << endl;
    for(auto it : findByPub)
    {
        cout << it.first << ":";
        for(auto e : it.second) cout << " " << e;
        cout << endl;
    }
    cout << "++++++++++++++++++++++++Year++++++++++++++++++++++++" << endl;
    for(auto it : findByYear)
    {
        cout << it.first << ":";
        for(auto e : it.second) cout << " " << e;
        cout << endl;
    }
    */



    scanf("%d\n", &m);
    while(m-- > 0)
    {
        getline(cin, line);
        t = line[0] - '0';
        line = line.substr(3);
        cout << t << ": " << line << endl;
        switch(t)
        {
        case 1:
            if(findByTitle.find(line) != findByTitle.end())
            {
                sort(findByTitle[line].begin(), findByTitle[line].end());
                for(auto e : findByTitle[line]) printf("%07d\n", e);
            }
            else cout << "Not Found\n";
            break;
        case 2:
            if(findByAuthor.find(line) != findByAuthor.end())
            {
                sort(findByAuthor[line].begin(), findByAuthor[line].end());
                for(auto e : findByAuthor[line]) printf("%07d\n", e);
            }
            else cout << "Not Found\n";
            break;
        case 3:
            if(findByKeyword.find(line) != findByKeyword.end())
            {
                sort(findByKeyword[line].begin(), findByKeyword[line].end());
                for(auto e : findByKeyword[line]) printf("%07d\n", e);
            }
            else cout << "Not Found\n";
            break;
        case 4:
            if(findByPub.find(line) != findByPub.end())
            {
                sort(findByPub[line].begin(), findByPub[line].end());
                for(auto e : findByPub[line]) printf("%07d\n", e);
            }
            else cout << "Not Found\n";
            break;
        case 5:
            if(findByYear.find(line) != findByYear.end())
            {
                sort(findByYear[line].begin(), findByYear[line].end());
                for(auto e : findByYear[line]) printf("%07d\n", e);
            }
            else cout << "Not Found\n";
            break;
        default:
            break;
        }
    }

    return 0;
}
