#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    char c, tmp = 0;
    string s;

    cin >> n >> c;
    while(tmp != '\n') tmp = cin.get();
    getline(cin, s);

    int len = s.size();
    if(n > len)
    {
        for(int i = 0; i < n-len; i++) cout << c;
        cout << s << endl;
    }
    else
    {
        n = len - n;
        cout << s.substr(n, len) << endl;
    }

    return 0;
}
  
