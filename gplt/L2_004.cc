#include <iostream>
using namespace std;

#define N   1005

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL)
    {}
};

bool comp(int a, int b)
{
    return a > b;
}

bool compMirror(int a, int b)
{
    return a <= b;
}

bool create(TreeNode *root, int *pre, int n, bool (*comp)(int, int))
{
    if(n == 1) return true;

    int rbegin;

    for(rbegin = 1; rbegin < n; rbegin++)
    {
        if(!comp(pre[0], pre[rbegin])) break;
    }
    for(int i = rbegin+1; i < n; i++)
    {
        if(comp(pre[0], pre[i])) return false;
    }

    int left_len = rbegin-1;
    int right_len = n - 1 - left_len;
    bool ret = true;
    
    if(left_len > 0)
    {
        TreeNode *left = new TreeNode(pre[1]);
        root->left = left;
        ret &= create(left, pre+1, left_len, comp);
    }
    if(right_len > 0)
    {
        TreeNode *right = new TreeNode(pre[rbegin]);
        root->right = right;
        ret &= create(right, pre+rbegin, right_len, comp);
    }

    return ret;
}

void traver(TreeNode *root)
{
    if(root->left)
    {
        traver(root->left);
        cout << " ";
    }
    if(root->right)
    {
        traver(root->right);
        cout << " ";
    }
    cout << root->val;
}

int main()
{
    int n, pre[N];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> pre[i];

    TreeNode *root = new TreeNode(pre[0]);

    if(create(root, pre, n, comp) || create(root, pre, n, compMirror))
    {
        cout << "YES" << endl;
        traver(root);
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
