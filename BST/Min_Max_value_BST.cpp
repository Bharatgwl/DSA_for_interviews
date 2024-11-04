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

void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
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
int min_value(node *root)
{
    node *curr = root;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr->data;
}
int max_value(node *root)
{
    node *curr = root;
    while (curr->right)
    {
        curr = curr->right;
    }
    return curr->data;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    Inorder(root);
    cout << "min value: " << min_value(root) << endl;
    cout << "max value: " << max_value(root) << endl;
}