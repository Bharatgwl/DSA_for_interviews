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
/**
 * Finds the minimum value in a binary search tree.
 *
 * This function takes a pointer to the root node of a binary search tree and
 * returns the minimum value in the tree. The minimum value is the value of the
 * leftmost node in the tree, which is the node with the smallest key.
 *
 * @param root the root of the binary search tree
 * @return the minimum value in the tree
 */
int min_value(node *root)
{
    // Start at the root of the tree
    node *curr = root;

    // While there is a left child, move to the left child
    while (curr->left)
    {
        // Move to the left child
        curr = curr->left;
    }

    // When there is no left child, the current node is the minimum
    // Return the value of the minimum node
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