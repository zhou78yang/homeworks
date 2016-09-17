#include <iostream>
#include <cstring>
using namespace std;

#define N   1005

struct Stack {
    char data[N];
    int top = 0;
    void push(char c);
    void pop();
    void dump();
    void init();
    bool check();
} stack;

void Stack::init()
{
    top = 0;
}

void Stack::push(char c)
{
    data[top++] = c;
}

void Stack::pop()
{
    if(check()) top--;
    while(data[top-1] != '/')
    {
        top--;
    }
}

void Stack::dump()
{
    if(check()) data[top-1] = '\0';
    else data[top] = '\0';
    cout << data << endl;
}

bool Stack::check()
{
    return top > 1 && data[top-1] == '/';
}


int main()
{
    int P;
    char origin[N], s[N];

    cin >> P >> origin;
    
    int l = 0;
    for(int i = 0; origin[i] != '\0'; i++)
    {
        if(origin[i] == '/')
        {
            origin[l++] = '/';
            while(origin[i+1] == '/') i++;
        }
        else if(origin[i] == '.' && origin[i+1] == '/') i++;
        else if(origin[i] == '.' && origin[i+1] == '.' && origin[i+2] == '/')
        {
            l--;
            while(origin[l-1] != '/') l--;
            i += 2;
        }
        else
        {
            origin[l++] = origin[i];
        }
        
    }
    origin[l] = '\0';
        
    while(P-- > 0)
    {
        cin >> s;

        stack.init();
        if(s[0] != '/')
        {
            for(int i = 0; origin[i] != '\0'; i++)
            {
                stack.push(origin[i]);
            }
            if(!stack.check())
            {
                stack.push('/');
            }
        }

        int i = 0;
        while(s[i] != '\0')
        {
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '/')
            {
                stack.pop();
                i += 3;
            }
            else if(s[i] == '.' && s[i+1] == '/')
            {
                i += 2;
            }
            else if(s[i] == '/' && stack.check())
            {
                i++;
            }
            else
            {
                stack.push(s[i]);
                i++;
            }
        }

        stack.dump();
    }

    return 0;
}
