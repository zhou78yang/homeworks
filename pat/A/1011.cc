#include <iostream>
using namespace std;

int main()
{
    char str[] = "#WTL";
    double table[5][5];
    int bet[5];

    for(int i = 1; i <= 3; i++)
    {
        bet[i] = 1;
        for(int j = 1; j <= 3; j++)
        {
            cin >> table[i][j];
            if(table[i][j] > table[i][bet[i]]) bet[i] = j;
        }
    }

    double earn = (table[1][bet[1]]*table[2][bet[2]]*table[3][bet[3]]*0.65-1)*2;
    for(int i = 1; i <= 3; i++) cout << str[bet[i]] << " ";
    printf("%.2lf\n", earn);

    return 0;
}
