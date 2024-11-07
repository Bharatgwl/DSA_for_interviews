#include <iostream>
#include <limits.h>
#include <vector>
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
void Inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}
bool valid_BST(node *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= mini && root->data <= maxi)
    {
        bool left = valid_BST(root->left, mini, root->data);
        bool right = valid_BST(root->right, root->data, maxi);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool is_valid( vector<int> &ans)
{
    for (int i = 0; i < ans.size()-1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    node *root = NULL;
    vector<int> ans;
    takeinput(root);
    swap(root->left->data, root->right->data);
    if (valid_BST(root, INT_MIN, INT_MAX))
    {
        cout << "It's a valid bst";
    }
    else
    {
        cout << "It's not a valid bst";
    }
    Inorder(root, ans);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout<<endl;
    if (is_valid(ans))
    {
        cout << "It's a valid bst";
    }
    else
    {
        cout << "It's not a valid bst";
    }
  

}