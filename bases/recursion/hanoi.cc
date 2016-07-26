#include <iostream>

using namespace std;

void move(char src, char dst)
{
    cout << src << "-->" << dst << endl;
}

void hanoi(int n, char src, char mid, char dst)
{
    if(1 == n)
    {
        move(src, dst);
        return;
    }
    hanoi(n-1, src, dst, mid);
    move(src, dst);
    hanoi(n-1, mid, src, dst);
}

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        hanoi(n, 'A', 'B', 'C');
    }

    return 0;
}

