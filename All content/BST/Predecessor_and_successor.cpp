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
        BuildBST(root, data);
        cin >> data;
    }
}
/**
 * @brief Finds the predecessor and successor of a given key in a Binary Search Tree (BST).
 *
 * This function takes a pointer to the root of a BST and a key as input and returns a pair of integers.
 * The first element of the pair is the predecessor of the key in the BST, and the second element is the successor.
 * If the key is not found in the BST, the function returns a pair where both elements are -1.
 *
 * @param root Pointer to the root of the BST.
 * @param key The key for which to find the predecessor and successor.
 * 
 * @return A pair of integers, where the first element is the predecessor and the second element is the successor.
 */
pair<int, int> Predecessor_and_successor(node *root, int key)
{
    // start at the root of the tree
    node *temp = root;
    int pred = -1; // predecessor
    int succ = -1; // successor

    // find the key
    while (temp->data != key)
    {
        // if the key is less than the current node, go left
        if (temp->data < key)
        {
            // the current node is the predecessor
            pred = temp->data;
            temp = temp->right;
        }
        // if the key is greater than the current node, go right
        else
        {
            // the current node is the successor
            succ = temp->data;
            temp = temp->left;
        }
    }
    
    // find the predecessor and successor after finding the key
    // find the maximum of the left subtree
    node *left = temp->left;
    while (left != NULL)
    {
        // the maximum of the left subtree is the predecessor
        pred = left->data;
        left = left->right;
    }
    // find the minimum of the right subtree
    node *right = temp->right;
    while (right != NULL)
    {
        // the minimum of the right subtree is the successor
        succ = right->data;
        right = right->left;
    }

    // return the predecessor and successor
    return {pred, succ};
}

int main()
{
    node *root = NULL;
    takeinput(root);
    int key = 8;
    pair<int, int> ans = Predecessor_and_successor(root, key);
    cout << ans.first << " " << ans.second << endl;
}