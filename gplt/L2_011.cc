#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL)
    {}
};

void create(TreeNode *root, int *pre, int *in, int n)
{
    if(n == 1) return ;

    int left_len, right_len;
    for(left_len = 0; left_len < n; left_len++)
    {
        if(in[left_len] == pre[0]) break;
    }
    right_len = n - 1 - left_len;

    if(left_len > 0)
    {
        TreeNode *left = new TreeNode(pre[1]);
        root->left = left;
        create(left, pre+1, in, left_len);
    }
    if(right_len > 0)
    {
        TreeNode *right = new TreeNode(pre[left_len+1]);
        root->right = right;
        create(right, pre+left_len+1, in+left_len+1, right_len);
    }
}

void layerTraver(TreeNode *root)
{
    TreeNode *q[35], *p;
    int tail = 1;
    q[0] = root;

    for(int head = 0; head < tail; head++)
    {
        p = q[head];
        if(p->right) q[tail++] = p->right;
        if(p->left) q[tail++] = p->left;
    }

    cout << q[0]->val;
    for(int i = 1; i < tail; i++)
    {
        cout << " " << q[i]->val;
    }
    cout << endl;
}

int main()
{
    int n, pre[35], in[35];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> pre[i];

    TreeNode *root = new TreeNode(pre[0]);
    create(root, pre, in, n);

    layerTraver(root);

    return 0;
}
