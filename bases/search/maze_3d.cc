#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

#define N   35

char map[N][N][N];
bool vis[N][N][N];
const int dir[6][3] = {
    { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 },
    {-1, 0, 0 }, { 0,-1, 0 }, { 0, 0,-1 }
};
int L, R, C;
struct Pace
{
    int l, r, c;
    int step;
};

bool go(int l, int r, int c)
{
    if(l < 1 || r < 1 || c < 1 || l > L || r > R || c > C) return false;
    if(map[l][r][c] == '#' || vis[l][r][c]) return false;
    return true;
}

void bfs(int l, int r, int c)
{
    deque<Pace> q;
    Pace cur;
    cur.l = l; cur.r = r; cur.c = c;
    cur.step = 0;
    vis[l][r][c] = true;
    q.push_back(cur);

    while(!q.empty())
    {
        cur = q.front();
        if(map[cur.l][cur.r][cur.c] == 'E')
        {
            cout << "Escaped in " << cur.step << " minute(s)" << endl;
            return ;
        }

        for(int i = 0; i < 6; i++)
        {
            int ll = cur.l + dir[i][0];
            int rr = cur.r + dir[i][1];
            int cc = cur.c + dir[i][2];
            if(go(ll, rr, cc))
            {
                vis[ll][rr][cc] = true;
                Pace tmp;
                tmp.l = ll; tmp.r = rr; tmp.c = cc;
                tmp.step = cur.step + 1;
                q.push_back(tmp);
            }
        }
        q.pop_front();
    }
    cout << "Trapped!" << endl;
}

int main()
{
    int l, r, c;
    while(cin >> L >> R >> C)
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= L; i++)
        {
            for(int j = 1; j <= R; j++)
            {
                for(int k = 1; k <= C; k++)
                {
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S')
                    {
                        l = i; r = j; c = k;
                    }
                }
            }
        }// for input

        bfs(l, r, c);
    }

    return 0;
}

