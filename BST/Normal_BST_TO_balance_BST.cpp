#include <iostream>
#include <vector>
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
void Inorder(node *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, vec);
    vec.push_back(root->data);
    Inorder(root->right, vec);
}
node *Normal_BST_TO_balance_BST(vector<int> ans, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(ans[mid]);
    root->left = Normal_BST_TO_balance_BST(ans, s, mid - 1);
    root->right = Normal_BST_TO_balance_BST(ans, mid + 1, e);
    return root;
}
void Level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node *root = NULL;
    takeinput(root);
    vector<int> ans;
    Inorder(root, ans);
    Level_order_traversal(root);

    cout << endl;
    root = Normal_BST_TO_balance_BST(ans, 0, ans.size() - 1);

    Level_order_traversal(root);
    return 0;
}