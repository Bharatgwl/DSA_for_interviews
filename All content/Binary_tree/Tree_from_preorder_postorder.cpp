#include <bits/stdc++.h>
using namespace std;

vector<int>
    preorederindex_array,
    postorderindex_array;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *util(vector<int> &preorder, vector<int> &postorder, int preindex, int postindexS, int postindexE)
{
    if (postindexS > postindexE)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preindex]);
    if (postindexS == postindexE)
        return root;

    int lRoot = preorder[preindex + 1];
    int leftrootpost = postorderindex_array[lRoot];
    root->left =
        util(preorder, postorder, preindex + 1, postindexS, leftrootpost);
    root->right = util(preorder, postorder,
                       preorederindex_array[postorder[postindexE - 1]],
                       leftrootpost + 1, postindexE - 1);

    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder,
                               vector<int> &postorder)
{
    const int n = preorder.size();
    preorederindex_array.assign(n + 1, -1);
    postorderindex_array.assign(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        preorederindex_array[preorder[i]] = i;
        postorderindex_array[postorder[i]] = i;
    }

    return util(preorder, postorder, 0, 0, n - 1);
}
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    const int n = preorder.size();
    preorederindex_array.assign(n + 1, -1);
    postorderindex_array.assign(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        preorederindex_array[preorder[i]] = i;
        postorderindex_array[postorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << preorederindex_array[i] << " ";
        }
    // TreeNode *root = constructFromPrePost(preorder, postorder);
    // inorder(root);
    return 0;
}