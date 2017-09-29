#include <iostream>
using namespace std;

int main()
{
    int a1, a2, a2_n, a3, a4_s, a4_n, a5;
    bool b1, b2, b3, b4, b5;
    b1 = b2 = b3 = b4 = b5 = false;
    double a4;
    
    int N, num;
    cin >> N;
    a1 = 0; a2 = 0; a3 = 0; a4 = 0; a5 = 0;
    a4_s = a4_n = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        switch(num % 5)
        {
        case 0:
            if(num % 2 == 0){
                b1 = true;
                a1 += num;
            }
            break;
        case 1:
            b2 = true;
            if(a2_n % 2 == 0) a2 += num;
            else a2 -= num;
            a2_n++;
            break;
        case 2:
            b3 = true;
            a3++;
            break;
        case 3:
            b4 = true;
            a4_s += num;
            a4_n++;
            break;
        case 4:
            b5 = true;
            if(a5 < num) a5 = num;
            break;
        }
    }
    a4 = ((double)a4_s) / a4_n;
    if(b1) cout << a1 << " ";
    else cout << "N ";
    if(b2) cout << a2 << " ";
    else cout << "N ";
    if(b3) cout << a3 << " ";
    else cout << "N ";
    if(b4) printf("%.1f ", a4);
    else cout << "N ";
    if(b5) cout << a5 << endl;
    else cout << "N\n";

    return 0;
}
