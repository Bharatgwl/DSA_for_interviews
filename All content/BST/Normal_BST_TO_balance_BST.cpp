#include <iostream>
#include <vector>
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
void Inorder(node *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, vec);
    vec.push_back(root->data);
    Inorder(root->right, vec);
}
/**
 * @brief Takes a sorted vector of integers and creates a balanced BST from it.
 *
 * This function takes a sorted vector of integers and creates a balanced BST from it.
 * It works by finding the middle element of the vector and making it the root of the tree.
 * It then recursively calls itself on the left and right sub-arrays of the vector.
 * The left sub-array is from the start of the vector to the middle element -1 and the right sub-array is from the middle element +1 to the end of the vector.
 * The recursion continues until the start index is greater than the end index, at which point the function returns NULL.
 * The function then returns the root of the balanced BST.
 *
 * @param ans The sorted vector of integers.
 * @param s The start index of the vector.
 * @param e The end index of the vector.
 * @return The root of the balanced BST.
 */
node *Normal_BST_TO_balance_BST(vector<int> ans, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    // The middle element of the vector is the root of the tree.
    node *root = new node(ans[mid]);
    // The left sub-tree of the root should contain all the elements in the vector with indices less than mid.
    // To build the left sub-tree, we recursively call this function with the start index as s and the end index as mid-1.
    root->left = Normal_BST_TO_balance_BST(ans, s, mid - 1);
    // The right sub-tree of the root should contain all the elements in the vector with indices greater than mid.
    // To build the right sub-tree, we recursively call this function with the start index as mid+1 and the end index as e.
    root->right = Normal_BST_TO_balance_BST(ans, mid + 1, e);
    // Finally, we return the root of the tree.
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
int main()
{
    node *root = NULL;
    takeinput(root);
    vector<int> ans;
    Inorder(root, ans);
    Level_order_traversal(root);

    cout << endl;
    root = Normal_BST_TO_balance_BST(ans, 0, ans.size() - 1);

    Level_order_traversal(root);
    return 0;
}