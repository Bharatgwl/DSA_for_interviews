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
        root = BuildBST(root, data);
        cin >> data;
    }
}
bool Search_in_Bst(node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
        {
            return true;
        }
        if (x < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    int x = 3 ;
    if (Search_in_Bst(root, x))
    {
        cout << "Found in TREE :" << x << endl;
    }
    else
    {
        cout << "Not Found :" << endl;
    }
}