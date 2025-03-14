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
node *buildtree(node *&root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter for right of " << data << endl;
    root->right = buildtree(root->right);
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
void leftTraversal(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        leftTraversal(root->left, ans);
    }
    else
    {
        leftTraversal(root->right, ans);
    }
}
void leafTraversal(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}
void rightTraversal(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        rightTraversal(root->right, ans);
    }
    else
    {
        rightTraversal(root->left, ans);
    }
    ans.push_back(root->data);
}
void boundaryTraversal(node *&root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);

    leftTraversal(root->left, ans);
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
    rightTraversal(root->right, ans);
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    vector<int> ans;
    boundaryTraversal(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
} // 1 2 4 -1 -1 5 7 -1 -1  8  -1 -1 3 -1 6 -1 9 10 -1 -1 11 -1 -1
// 1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1