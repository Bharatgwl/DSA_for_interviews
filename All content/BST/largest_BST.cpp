#include <iostream>
#include <limits.h>
using namespace std;
//  followup question link: (https://www.geeksforgeeks.org/largest-bst-binary-tree-set-2/)
class info
{
public:
    int size;
    int maxi;
    int mini;
    bool isValidBST;
};

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
 * This function returns an object of type 'info' which contains the
 * size of the largest BST subtree rooted at the given node, the maximum
 * value in that subtree, the minimum value in that subtree, and a boolean
 * indicating whether or not the subtree rooted at the given node is a
 * valid BST.
 *
 * @param root The node at which to start the search for the largest BST.
 * @param ans The maximum size of a BST subtree found so far.
 * @return An 'info' object containing the size of the largest BST subtree rooted
 * at the given node, the maximum value in that subtree, the minimum value in
 * that subtree, and a boolean indicating whether or not the subtree rooted at
 * the given node is a valid BST.
 */
info largestBST(node *root, int &ans)
{
    if (root == NULL)
    {
        // If the root is NULL, then the largest BST subtree is of size 0 and
        // has a maximum value of negative infinity and a minimum value of
        // positive infinity, and it is a valid BST.
        return {0, INT_MIN, INT_MAX, true};
    }

    // Recursively find the largest BST subtree in the left subtree of the root.
    info left = largestBST(root->left, ans);
    // Recursively find the largest BST subtree in the right subtree of the root.
    info right = largestBST(root->right, ans);

    // Create an 'info' object to store the size, maximum value, minimum value,
    // and validity of the subtree rooted at the current node.
    info currentnode;
    // The size of the subtree rooted at the current node is the sum of the
    // sizes of the left and right subtrees, plus 1.
    currentnode.size = left.size + right.size + 1;
    // The maximum value in the subtree rooted at the current node is the
    // maximum of the current node's value and the maximum value in the right
    // subtree.
    currentnode.maxi = max(root->data, right.maxi);
    // The minimum value in the subtree rooted at the current node is the
    // minimum of the current node's value and the minimum value in the left
    // subtree.
    currentnode.mini = min(root->data, left.mini);
    // If the left subtree is a valid BST, the right subtree is a valid BST, and
    // the current node's value is greater than the maximum value in the left
    // subtree and less than the minimum value in the right subtree, then the
    // subtree rooted at the current node is a valid BST.
    if (left.isValidBST && right.isValidBST &&
        (root->data > left.maxi && root->data < right.mini))
    {
        currentnode.isValidBST = true;
    }
    else
    {
        // Otherwise, the subtree rooted at the current node is not a valid BST.
        currentnode.isValidBST = false;
    }
    // If the subtree rooted at the current node is a valid BST, then update
    // the maximum size of a BST subtree found so far.
    if (currentnode.isValidBST)
    {
        ans = max(ans, currentnode.size);
    }
    // Return the 'info' object containing the size, maximum value, minimum value,
    // and validity of the subtree rooted at the current node.
    return currentnode;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    int ans;
    largestBST(root, ans);
    cout << ans;
}