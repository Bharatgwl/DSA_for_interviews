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
void Level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
/**
 * @brief This function takes a binary tree and returns a pair.
 * The first element of the pair is a boolean indicating whether or not
 * the tree is balanced. The second element of the pair is the height of the tree.
 *
 * A binary tree is considered balanced if the difference between the height of
 * its left subtree and the height of its right subtree is not greater than 1.
 *
 * @param root The root of the binary tree.
 * @return A pair where the first element is a boolean indicating whether or not
 * the tree is balanced and the second element is the height of the tree.
 */
pair<bool, int> is_balance(node *root)
{
    if (root == NULL)
    {
        // If the tree is empty, it is balanced and its height is 0.
        pair<bool, int> p = make_pair(true, 0);

        return p;
    }
    // Find out if the left subtree is balanced and what its height is.
    pair<bool, int> leftside = is_balance(root->left);
    // Find out if the right subtree is balanced and what its height is.
    pair<bool, int> rightside = is_balance(root->right);

    // Check if the left subtree is balanced.
    bool leftans = leftside.first;
    // Check if the right subtree is balanced.
    bool rightans = rightside.first;
    // Check if the difference between the height of the left subtree and the
    // height of the right subtree is not greater than 1.
    bool diff = abs(leftside.second - rightside.second) <= 1;

    // Create a pair to store the result of whether or not the tree is balanced
    // and the height of the tree.
    pair<bool, int> ans;
    // Calculate the height of the tree as the maximum of the height of the
    // left subtree and the height of the right subtree plus 1.
    ans.second = max(leftside.second, rightside.second) + 1;
    // Check if the tree is balanced by checking if the left subtree is balanced
    // and the right subtree is balanced and the difference between the height of
    // the left subtree and the height of the right subtree is not greater than 1.
    if (leftans && rightans && diff)
    {
        // If the tree is balanced, set the first element of the pair to true.
        ans.first = true;
    }
    else
    {
        // If the tree is not balanced, set the first element of the pair to false.
        ans.first = false;
    }
    // Return the pair.
    return ans;
}
int main()
{
    node *root;
    root = buildtree(root);
    Level_order_traversal(root);
    if (is_balance(root).first)
    {
        cout << "Tree is balanced";
    }
    else
    {
        cout << "Tree is not balanced";
    }
}