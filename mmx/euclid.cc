#include <iostream>
#include <vector>
using namespace std;

int euclid(int a, int b)
{
    if(b == 0) return a;
    return euclid(b, a%b);
}

int gcd(int n, int k)
{
    if(k == 0) return n;
    if(n == 0) return k;
    return gcd(k, n%k);
}

void get_gcd(int n)
{
    vector<int> v;
    for(int i = 1; i < n; i++)
    {
        if(gcd(n, i) == 1)
        {
            v.push_back(i);
        }
    }
    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int a, b;
    int n;
    while(cin >> n)
    {
        cout << n << " : ";
        get_gcd(n);
    }

    return 0;
}


