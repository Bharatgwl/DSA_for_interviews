#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    // Constructor for creating a new node
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
/**
 * @brief Builds a Binary Search Tree (BST) by inserting a given integer into an
 *        existing tree.
 *
 * @param root The root of the current tree.
 * @param data The integer to insert into the tree.
 *
 * @return The root of the updated tree.
 */
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
/**
 * @brief Continuously takes integer input from the user and inserts each 
 *        value into the existing Binary Search Tree (BST) until -1 is entered.
 *
 * @param root Reference to the root pointer of the BST.
 *
 * @note Input -1 signifies the end of input and is not inserted into the BST.
 */
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
 * @brief Checks if a binary search tree (BST) is balanced and computes its height.
 *
 * This function determines if a given BST is balanced by recursively 
 * checking the balance condition on each subtree. A balanced BST is 
 * defined as a tree where the height difference between the left and 
 * right subtrees of any node is at most 1. The function returns a 
 * pair where the first element is a boolean indicating if the tree 
 * is balanced, and the second element is an integer representing the 
 * height of the tree.
 *
 * @param root Pointer to the root node of the BST.
 * 
 * @return A pair consisting of a boolean and an integer. The boolean 
 *         indicates if the tree is balanced, and the integer represents 
 *         the height of the tree.
 */
pair<bool, int> check_for_balance_bst(node *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }
    pair<bool, int> leftans = check_for_balance_bst(root->left);
    pair<bool, int> rightans = check_for_balance_bst(root->right);
    bool condition = leftans.first && rightans.first && abs(leftans.second - rightans.second) <= 1;
    pair<bool, int> p;
    p.first = condition;
    p.second = max(leftans.second, rightans.second) + 1;
    return p;
}
/**
 * @brief Checks if a binary search tree (BST) is balanced.
 *
 * This program reads a sequence of integers as input and constructs a BST. 
 * It then checks if the BST is balanced by calling the check_for_balance_bst function. 
 * If the BST is balanced, it prints out "yes", otherwise it prints out "no".
 **/
int main()
{
    node *root = NULL;
    takeinput(root);
    if (check_for_balance_bst(root).first)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}