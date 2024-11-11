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
/**
 * @brief Finds the lowest common ancestor (LCA) of two nodes in a binary tree.
 *
 * This function takes in the root of a binary tree and two integers, n1 and n2.
 * It then returns the LCA of the two nodes represented by n1 and n2 in the tree.
 *
 * The LCA of two nodes is the node furthest from the root which is the ancestor
 * of both nodes. If either n1 or n2 is not in the tree, the function returns NULL.
 *
 * @param root the root of the binary tree
 * @param n1 the first integer
 * @param n2 the second integer
 *
 * @returns the LCA of n1 and n2, or NULL if either n1 or n2 are not in the tree
 */
node *LCA(node *root, int n1, int n2)
{
    // If the tree is empty, return NULL
    if (root == NULL)
    {
        return NULL;
    }
    // If the current node is one of the two nodes we're looking for,
    // return the current node
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    // Recursively search for the two nodes in the left and right
    // subtrees
    node *leftans = LCA(root->left, n1, n2);
    node *rightans = LCA(root->right, n1, n2);
    // If we found one of the nodes in the left subtree and not in
    // the right subtree, return the left subtree's answer
    if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    // If we found one of the nodes in the right subtree and not in
    // the left subtree, return the right subtree's answer
    else if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
    // If we found both nodes in the left and right subtrees, return
    // the current node
    else if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    // If we didn't find either node, return NULL
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