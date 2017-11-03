#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char num[105];
    int sum = 0, book[10] = {0};
    string str[10] = {"zero", "one", "two", "three", "four",
                      "five", "six", "seven", "eight", "night"};
    vector<int> stack;

    cin >> num;
    for(int i = 0; num[i] != '\0'; i++) sum += num[i]-'0';
    do{
        stack.push_back(sum%10);
        sum /= 10;
    } while(sum > 0);
    
    while(stack.size() > 1)
    {
        cout << str[stack.back()] << " ";
        stack.pop_back();
    }
    cout << str[stack.back()] << endl;

    return 0;
}
