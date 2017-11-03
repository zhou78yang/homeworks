#include <iostream>
#include <queue>
using namespace std;
#define N   50

struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
    TreeNode(int d)
        : data(d), left(NULL), right(NULL)
    {}
};

void getChild(TreeNode *root, int *in, int *post, int len)
{
    if(len < 2) return ;
    
    int j;
    for(j = 0; j < len; j++)
    {
        if(in[j] == root->data) break;
    }

    if(j > 0) root->left = new TreeNode(post[j-1]);
    if(j < len-1) root->right = new TreeNode(post[len-2]);
    if(root->left) getChild(root->left, in, post, j);
    if(root->right) getChild(root->right, in+j+1, post+j, len-j-1);
}

void travel(TreeNode *root)
{
    queue<TreeNode*> Q;
    Q.push(root);
    cout << root->data;
    while(!Q.empty())
    {
        auto node = Q.front();
        if(node->left){
            cout << " " << node->left->data;
            Q.push(node->left);
        }
        if(node->right){
            cout << " " << node->right->data;
            Q.push(node->right);
        }
        Q.pop();
    }
    cout << endl;
}

int main()
{
    int post[N], in[N], n;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> post[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    
    TreeNode *root = new TreeNode(post[n-1]);
    getChild(root, in, post, n);
    travel(root);

    return 0;
}
