#include <iostream>
#include <algorithm>

using namespace std;

struct Comp
{
    double a;
    double b;
};

Comp ret;

Comp *add(const Comp &x, const Comp &y)
{
    ret.a = x.a + y.a;
    ret.b = x.b + y.b;
    return &ret;
}

Comp *sub(const Comp &x, const Comp &y)
{
    ret.a = x.a - y.a;
    ret.b = x.b - y.b;
    return &ret;
}

Comp *mul(const Comp &x, const Comp &y)
{
    ret.a = x.a * y.a - x.b * y.b;
    ret.b = x.a * y.b + x.b * y.a;
    return &ret;
}

Comp *div(const Comp &x, const Comp &y)
{
    ret.a = (x.a * y.a + x.b * y.b)/(y.a * y.a + y.b * y.b);
    ret.b = (x.b * y.a - x.a * y.b)/(y.a * y.a + y.b * y.b);
    return &ret;
}

int main()
{
    char ch;
    Comp x, y;
    Comp *p;
    cin >> ch;
    cin >> x.a >> x.b >> y.a >> y.b;

    switch(ch)
    {
    case '+': p = add(x, y); break;
    case '-': p = sub(x, y); break;
    case '*': p = mul(x, y); break;
    case '/': p = div(x, y); break;
    default: break;
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << p->a << "+" << p->b << "i" << endl;

    return 0;
}

