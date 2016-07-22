#include <iostream>
using namespace std;

int main()
{
  int n;
  int H, W;
  double B, R;
  
  for(int i = 0; i < n; i++)
  {
    cin >> H >> W;
    B = (H-100)*0.9*2;
    R = B / 10;
    if(W - B >= R){
      cout << "You are tai pang le!" << endl;
      continue;
    }
    if(B - W >= R){
      cout << "You are tai shou le!" << endl;
      continue;
    }
    cout << "You are wan mei!" << endl;
  }
  return 0;
}
