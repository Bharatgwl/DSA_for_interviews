#include <iostream>
#include <limits.h>
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
 * @brief Finds the kth ancestor of a node with value n in a tree
 *
 * @param root the root of the tree
 * @param k the number of ancestors to go up
 * @param n the value of the node to find ancestors of
 *
 * @returns the kth ancestor of the node with value n, or NULL if it doesn't exist
 */
node *Kth_ancestor(node *root, int &k, int n)
{
    // If the tree is empty, return NULL
    if (root == NULL)
    {
        return NULL;
    }

    // If the current node is the node we're looking for, return it
    if (root->data == n)
    {
        return root;
    }

    // Search for the node in the left and right subtrees
    node *leftans = Kth_ancestor(root->left, k, n);
    node *rightans = Kth_ancestor(root->right, k, n);

    // If the node is found in the left subtree, move up the tree by one level
    if (leftans != NULL && rightans == NULL)
    {
        // Decrement the number of ancestors to go up
        k--;

        // If we've reached the kth ancestor, return the current node
        if (k <= 0)
        {
            k = INT_MAX; // to lock the answer once we got it so after n numbers of k Cant reaches to zero to disrreupt ans with the help of this we can return the found node to its ancestor
            return root;
        }

        // Otherwise, return the left subtree
        return leftans;
    }

    // If the node is found in the right subtree, move up the tree by one level
    if (rightans != NULL && leftans == NULL)
    {
        // Decrement the number of ancestors to go up
        k--;

        // If we've reached the kth ancestor, return the current node
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        // Otherwise, return the right subtree
        return rightans;
    }

    // If the node is not found in either subtree, return NULL
    return NULL;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    int k = 3;
    int n = 7;
    node *ans;
    ans = Kth_ancestor(root, k, n);
    if (ans == NULL || root->data == n) // root->data == n  to check whether the data of node is not the root node,  because we cant find ancestor of root node
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans->data;
    }
} // 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1