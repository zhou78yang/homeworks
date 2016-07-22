#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  char s[10005];
  int n;
  char c;
  cin >> n >> c;
  gets(s); gets(s);
  
  int len = strlen(s);
  int l = n - len;
  if(l > 0){
    for(int i = 0; i < l; i++) cout << c;
    cout << s << endl;
  }
  else{
    for(int i = len - n; s[i] != '\0'; i++) cout << s[i];
    
    cout << endl;
  }
  return 0;
}
