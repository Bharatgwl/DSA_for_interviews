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
        root->right - BuildBST(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = BuildBST(root, data);
        cin >> data;
    }
}
void Preoder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preoder(root->left);
    Preoder(root->right);
}
int main()
{
    node *root = NULL;
    cout << " Enter the data: ";
    takeinput(root);
    cout << endl
         << "Preoder of following BST: ";
    Preoder(root);
}
