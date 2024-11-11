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
/**
 * Prints out the elements of the binary tree in an inorder traversal
 * 
 * An inorder traversal visits the left subtree, then the root, then the
 * right subtree.
 * 
 * @param root the root of the tree to traverse
 */
void Inorder(node *root)
{
    // if the root is NULL, then there's nothing to do
    if (root == NULL)
    {
        return;
    }

    // traverse the left subtree
    Inorder(root->left);

    // print out the value of the root
    cout << root->data << " ";

    // traverse the right subtree
    Inorder(root->right);
}
int main()
{
    node *root;
    root = buildtree(root);
    Inorder(root);
}