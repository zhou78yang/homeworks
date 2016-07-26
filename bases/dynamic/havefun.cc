/*
 * 考虑一个三参数的函数w(x, y, z)
 *  if x <= 0 or y <= 0 or z <= 0, then w(x, y, z)return 1
 *  if x > 20 or y > 20 or z > 20, then w(x, y, z) return w(20, 20, 20)
 *  if x < y and y < z, then w(x, y, z) return w(x, y, z-1) + w(x, y-1, z-1) - w(x, y-1, z)
 *  else return w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1) - w(x-1, y-1, z-1)
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

#define N 25
int W[N][N][N];

int w(int x, int y, int z)
{
    if(x <= 0 || y <= 0 || z <= 0) return 1;
    if(x > 20 || y > 20 || z > 20) return w(20, 20, 20);
    if(W[x][y][z] > 0) return W[x][y][z];
    if(x < y && y < z)
    {
        W[x][y][z] = w(x, y, z-1) + w(x, y-1, z-1) - w(x, y-1, z);
    }
    else
    {
        W[x][y][z] = w(x-1, y, z) + w(x-1, y-1, z) 
            + w(x-1, y, z-1) - w(x-1, y-1, z-1);
    }

    return W[x][y][z];
}

int main(int argc, char *argv[])
{
    int x, y, z;
    memset(W, 0, sizeof(W));

    while(cin >> x >> y >> z)
    {
        cout << w(x, y, z) << endl;
    }

    return 0;
}
