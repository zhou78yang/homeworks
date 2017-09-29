#include <iostream>
using namespace std;

int main()
{
    char words[40][81];
    int len;
    while(cin >> words[len]) len++;
    while(len > 1) cout << words[--len] << " ";
    cout << words[0] << endl;

    return 0;
}
