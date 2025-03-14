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
void Inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}
/*************  ✨ Codeium Command 🌟  *************/
/**
 * @brief Determines if a given binary search tree is valid.
 *
 * A binary search tree is valid if the following conditions are met for each node:
 *  - The value of the node is greater than all the values in its left subtree.
 *  - The value of the node is less than all the values in its right subtree.
 *
 * This function works by recursively checking the left and right subtrees of the given node.
 * It keeps track of the minimum and maximum allowed values for each subtree as it recurses.
 *
 * @param root The node to check.
 * @param mini The minimum allowed value for the current subtree.
 * @param maxi The maximum allowed value for the current subtree.
 * @return true if the tree is valid, false otherwise.
 */
bool valid_BST(node *root, int mini, int maxi)
{
    // If the tree is empty, then it is valid.
    if (root == NULL)
    {
        return true;
    }

    // Check if the value of the current node is within the allowed range.
    if (root->data >= mini && root->data <= maxi)
    {
        // Recursively check the left subtree, making sure that all its values are less than the current node's value.
        bool left = valid_BST(root->left, mini, root->data);
        // Recursively check the right subtree, making sure that all its values are greater than the current node's value.
        bool right = valid_BST(root->right, root->data, maxi);

        // If both the left and right subtrees are valid, then this tree is valid.
        return left && right;
    }
    else
    {
        // If the value of the current node is outside the allowed range, then this tree is not valid.
        return false;
    }
}
/******  b59b7f32-2199-495f-9cb3-87c4d229a753  *******/

bool is_valid( vector<int> &ans)
{
    for (int i = 0; i < ans.size()-1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    node *root = NULL;
    vector<int> ans;
    takeinput(root);
    swap(root->left->data, root->right->data);
    if (valid_BST(root, INT_MIN, INT_MAX))
    {
        cout << "It's a valid bst";
    }
    else
    {
        cout << "It's not a valid bst";
    }
    Inorder(root, ans);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout<<endl;
    if (is_valid(ans))
    {
        cout << "It's a valid bst";
    }
    else
    {
        cout << "It's not a valid bst";
    }
  

}