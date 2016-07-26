#include <iostream>

using namespace std;

int ZeroOnePack(int val[], int weight[], int N, int V)
{
    int f[1005] = {0};
    for(int i = 1; i <= N; i++)
    {
        for(int v = V; v >= weight[i]; v--)
        {
            if(f[v] < f[v-weight[i]] + val[i])
            {
                f[v] = f[v-weight[i]] + val[i];
            }
        }
    }
    return f[V];
}

int main(int argc, char *argv[])
{
    int T, N, V;
    int val[1005], weight[1005];

    cin >> T;
    while(T-- > 0)
    {
        cin >> N >> V;
        for(int i = 1; i <= N; i++) cin >> val[i];
        for(int i = 1; i <= N; i++) cin >> weight[i];
        cout << ZeroOnePack(val, weight, N, V) << endl;
    }

    return 0;
}
