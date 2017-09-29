#include <iostream>
using namespace std;

int main()
{
    char sell[1005], need[1005];
    char color[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ#";
    int book_s[256] = {0}, book_n[256] = {0}, len_s = 0, len_n = 0, no = 0;

    cin.getline(sell, 1005);
    cin.getline(need, 1005);
    for(int i = 0; sell[i] != '\0'; i++)
    {
        book_s[sell[i]]++;
    }
    for(int i = 0; need[i] != '\0'; i++)
    {
        book_n[need[i]]++;
    }
    for(int i = 0; color[i] != '#'; i++)
    {
        if(book_s[color[i]] < book_n[color[i]])
        {
            no += book_n[color[i]] - book_s[color[i]];
        }
        len_n += book_n[color[i]];
        len_s += book_s[color[i]];
    }
    if(no)
    {
        cout << "No " << no << endl;
    }
    else
    {
        cout << "Yes " << len_s - len_n << endl;
    }

    return 0;
}

