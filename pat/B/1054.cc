#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

bool equal(string a, string b)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) return false;
        if(i >= b.size()) return false;
    }
    return true;
}

int main()
{
    int T, count = 0;
    double sum = 0.0;
    string word;

    cin >> T;
    while(T-- > 0)
    {
        cin >> word;
        istringstream istr(word);
        ostringstream ostr;
        double tmp;

        istr >> tmp;
        ostr << setiosflags(ios::fixed) << setprecision(2) << tmp;
        if(!equal(word, ostr.str()))
        {
            cout << "ERROR: " << word << " is not a legal number\n";
        }
        else if(tmp < -1000 || tmp > 1000)
        {
            cout << "ERROR: " << word << " is not a legal number\n";
        }
        else 
        {
            count++;
            sum += tmp;
        }
    }
    if(count > 1) printf("The average of %d numbers is %.2lf\n", count, sum/count);
    else if(count == 1) printf("The average of 1 number is %.2lf\n", sum);
    else cout << "The average of 0 numbers is Undefined" << endl;

    return 0;
}

