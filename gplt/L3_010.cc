#include <iostream>
using namespace std;

#define N   30

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL)
    {}
};

void create(TreeNode *root, int *arr, int n)
{
    TreeNode *p;

    for(int i = 1; i < n; i++)
    {
        p = root;
        while(p)
        {
            if(p->val < arr[i])
            {
                if(p->left) p = p->left;
                else
                {
                    TreeNode *left = new TreeNode(arr[i]);
                    p->left = left;
                    break;
                }
            }
            else
            {
                if(p->right) p = p->right;
                else
                {
                    TreeNode *right = new TreeNode(arr[i]);
                    p->right = right;
                    break;
                }
            }
        }// search position
    }// insert a node
}

bool traver(TreeNode *root, int n)
{
    TreeNode *q[N], *p;
    int tail = 1;
    bool flag = false, ret = true;
    q[0] = root;

    for(int head = 0; head < tail; head++)
    {
        p = q[head];
        if(p->left) q[tail++] = p->left;
        else
        {
            if(tail == n) break;
            else ret = false;
        }
        if(p->right) q[tail++] = p->right;
        else
        {
            if(tail == n) break;
            else ret = false;
        }
    }

    cout << q[0]->val;
    for(int i = 1; i < tail; i++)
    {
        cout << " " << q[i]->val;
    }
    cout << endl;

    return ret;
}

int main()
{
    int n, arr[N];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    TreeNode *root = new TreeNode(arr[0]);
    create(root, arr, n);

    if(traver(root, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
