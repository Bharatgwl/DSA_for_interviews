#include <iostream>
#include <limits.h>
#include <vector>
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
// This function constructs a binary search tree (BST) from a given preorder traversal.
// The function takes a vector of integers representing the preorder traversal (PRE),
// two integers 'mini' and 'maxi' representing the valid range of values for the current node,
// and a reference to an integer 'i' which keeps track of the current index in the preorder vector.

node *TREE_from_PREORDER(vector<int> PRE, int mini, int maxi, int &i) {
    // Base case: If the index 'i' is out of bounds, return NULL, indicating no node to be created.
    if (i >= PRE.size()) {
        return NULL;
    }
    
    // If the current element in the preorder vector falls outside the valid range,
    // it cannot be part of the current subtree, so return NULL.
    if (PRE[i] < mini || PRE[i] > maxi) {
        return NULL;
    }
    
    // Create a new node with the current value from the preorder traversal.
    node *root = new node(PRE[i++]);
    
    // Recursively build the left subtree. The valid range for the left child is updated
    // to have a maximum value of 'root->data', as all values in the left subtree must be less than the root.
    root->left = TREE_from_PREORDER(PRE, mini, root->data, i);
    
    // Recursively build the right subtree. The valid range for the right child is updated
    // to have a minimum value of 'root->data', as all values in the right subtree must be greater than the root.
    root->right = TREE_from_PREORDER(PRE, root->data, maxi, i);
    
    // Return the root of the newly created subtree.
    return root;
}
int main()
{
    vector<int> PRE = {20, 10, 5, 15, 13, 35, 30, 42};
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    node *root = TREE_from_PREORDER(PRE, min, max, i);
}