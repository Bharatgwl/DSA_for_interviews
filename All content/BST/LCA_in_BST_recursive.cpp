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
 * @brief Finds the lowest common ancestor (LCA) of two nodes in a binary search
 *        tree (BST). The LCA of two nodes is the node furthest from the root
 *        which is the ancestor of both nodes.
 *
 * @param root the root of the BST
 * @param a the first node
 * @param b the second node
 *
 * @returns the LCA of a and b, or NULL if either a or b are not in the tree
 * This function finds the lowest common ancestor (LCA) of two nodes (a and b) in a binary search tree (BST). 
 * It recursively traverses the tree, moving right if both nodes are greater than the current node, 
 * left if both nodes are smaller, and returns the current node if it's the LCA. If the tree is empty, it returns NULL.
 */
node *LCA(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < a && root->data < b)
    {
        return LCA(root->right, a, b);
    }
    else if (root->data > a && root->data > b)
    {
        return LCA(root->left, a, b);
    }
    return root;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    int a = 2, b = 6;

    node *ans = LCA(root, a, b);
    cout << "LCA of BST for " << a << " and " << b << " is : " << ans->data;
} // 5 4 8 2 6 10 3 7 -1