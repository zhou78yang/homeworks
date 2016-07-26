#include <iostream>
using namespace std;

struct Window {
    int id;
    int x1, y1, x2, y2;
    Window *next;

    bool contain(int x, int y);
    Window(int t_id, int xx1, int yy1, int xx2, int yy2)
        : id(t_id), x1(xx1), y1(yy1), x2(xx2), y2(yy2), next(NULL)
    {}
};

inline bool Window::contain(int x, int y)
{
    return x >= x1 && x <= x2
        && y >= y1 && y <= y2;
}

int main()
{
    int n, m;
    int x1, y1, x2, y2;
    Window *root = new Window(0, 0, 0, 0, 0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        Window *node = new Window(i, x1, y1, x2, y2);
        node->next = root->next;
        root->next = node;
    }

    for(int i = 0; i < m; i++)
    {
        bool ignored = true;
        cin >> x1 >> y1;
        for(Window *p = root; p->next; p = p->next)
        {
            if(p->next->contain(x1, y1))
            {
                Window *q = p->next;        // current window
                p->next = q->next;
                q->next = root->next;
                root->next = q;
                ignored = false;
                cout << q->id << endl;
                break;
            }
        }
        if(ignored) cout << "IGNORED" << endl;
    }

    return 0;
}

