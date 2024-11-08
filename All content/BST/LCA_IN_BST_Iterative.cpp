#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    explicit node(int data) noexcept
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
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
 * @brief Calculates the lowest common ancestor between two nodes in a binary search tree
 * @param root pointer to the root of the binary search tree
 * @param a value of the first node
 * @param b value of the second node
 * @return pointer to the lowest common ancestor of the two nodes
 */
node *LCA(node *root, int a, int b)
{
    while (root != NULL)
    {
        if (root->data < a && root->data < b)
        {
            root = root->right;
        }
        else if (root->data > a && root->data > b)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
}
// [LeetCode Problem - Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

/**
 * @brief Entry point of the program.
 *
 * This function constructs a Binary Search Tree (BST) by taking input from the user
 * until -1 is entered. It then calculates and outputs the Lowest Common Ancestor (LCA)
 * of two given nodes in the BST, specifically for nodes with values 2 and 6.
 */
int main()
{
    node *root = NULL;
    takeinput(root);
    int a = 2, b = 6;

    node *ans = LCA(root, a, b);
    cout << "LCA of BST for " << a << " and " << b << " is : " << ans->data;
} // 5 4 8 2 6 10 3 7 -1