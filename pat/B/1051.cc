#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double r1, p1, r2, p2, a, b;

    cin >> r1 >> p1 >> r2 >> p2;
    a = r1*r2*(cos(p1)*cos(p2)-sin(p1)*sin(p2));
    b = r1*r2*(cos(p1)*sin(p2)+cos(p2)*sin(p1));

	if(a < 0 && a >= -0.005) a += 0.005;    // 精度问题
	if(b < 0 && b >= -0.005) b += 0.005;
	
    if(a != 0.0) printf("%.2f", a);
    if(b != 0.0)
    {
        if(b < 0) printf("%.2fi\n", b);
        else printf("+%.2fi\n", b);
    }

    return 0;
}
