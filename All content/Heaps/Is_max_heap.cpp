#include <iostream>
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
int countnodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}
bool isCBT(node *root, int index, int count)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= count)
    {
        return false;
    }
    return isCBT(root->left, 2 * index + 1, count) && isCBT(root->right, 2 * index + 2, count);
}
bool ismaxorder(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->right == NULL)
    {
        return root->data > root->left->data;
    }
    else
    {
        bool left = ismaxorder(root->left);
        bool right = ismaxorder(root->right);

        return root->data > root->left->data && root->data > root->right->data && left && right;
    }
}

bool is_max_heap(node *root)
{
    if (isCBT(root, 0, countnodes(root)) && ismaxorder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    if (is_max_heap(root))
    {
        cout << "its a heap" << endl;
    }
    else
    {
        cout << "its not a heap" << endl;
    }
}