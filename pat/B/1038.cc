#include <iostream>
using namespace std;

int main()
{
    int book[105] = {0};
    int n, score, k;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> score;
        book[score]++;
    }
    cin >> k;
    while(k-- > 0)
    {
        cin >> score;
        cout << book[score];
        if(k) cout << " ";
        else cout << endl;
    }

    return 0;
}
