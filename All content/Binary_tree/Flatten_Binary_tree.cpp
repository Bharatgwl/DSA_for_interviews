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
node *Flatten_tree(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            node *temp = curr->left;
            curr->right = temp;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    root = Flatten_tree(root);
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}