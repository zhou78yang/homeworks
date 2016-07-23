#include <iostream>
using namespace std;

int main()
{
    int n;
    int H, W;
    double B;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> H >> W;
        B = (H-100)*0.9*2;

        if(W <= B - B/10)
        {
            cout << "You are tai shou le!" << endl;
        }
        else if(W >= B + B/10)
        {
            cout << "You are tai pang le!" << endl;
        }
        else
        {
            cout << "You are wan mei!" << endl;
        }
    }

    return 0;
}
