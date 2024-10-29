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
node *LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftans = LCA(root->left, n1, n2);
    node *rightans = LCA(root->right, n1, n2);
    if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
    else if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    node *root = NULL;
    int n1 = 8;
    int n2 = 27;
    root = buildtree(root);
    cout << LCA(root, n1, n2)->data << endl;
}