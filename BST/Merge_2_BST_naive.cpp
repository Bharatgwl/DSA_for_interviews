#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *BuildBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = BuildBST(root->left, data);
    }
    else
    {
        root->right = BuildBST(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        BuildBST(root, data);
        cin >> data;
    }
}
void inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> merge(vector<int> v1, vector<int> v2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> ans(v1.size() + v2.size());
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            ans[k] = v1[i++];
            k++;
        }
        else
        {
            ans[k] = v2[j++];
            k++;
        }
    }
    while (i < v1.size())
    {
        ans[k] = v1[i++];
        k++;
    }
    while (j < v2.size())
    {
        ans[k] = v2[j++];
        k++;
    }
    return ans;
}
node *TREE_from_Inorder(vector<int> ans, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(ans[mid]);
    root->left = TREE_from_Inorder(ans, s, mid - 1);
    root->right = TREE_from_Inorder(ans, mid + 1, e);
    return root;
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    takeinput(root1);
    takeinput(root2);
    vector<int> v1;
    vector<int> v2;
    inorder(root1, v1);
    inorder(root2, v2);
    vector<int> mergedvector = merge(v1, v2);
    node *root3 = TREE_from_Inorder(mergedvector, 0, mergedvector.size() - 1);
    v1.clear();
    inorder(root3, v1);
    for (auto i : v1)
    {
        cout << i << " ";
    }
}
 // 40 50 60 70 -1 65 45 35 47 75 -1