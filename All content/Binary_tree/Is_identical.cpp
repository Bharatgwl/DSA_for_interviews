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
/**
 * Performs a level order traversal of a binary tree, printing the data of each node
 * on a new line for each level of the tree.
 *
 * @param root The root of the tree to traverse.
 */
void Level_order_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    // Push a NULL marker onto the queue to indicate the end of the current level
    q.push(NULL);

    // Continue traversing the tree until all nodes have been processed
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // Check if the current node is a NULL marker, indicating the end of the current level
        if (temp == NULL)
        {
            cout << endl;

            // If the queue is not empty, push another NULL marker onto the queue to indicate the start of the next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // Print the data of the current node
            cout << temp->data << " ";

            // Push the left and right children of the current node onto the queue if they exist
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
 * Checks if two binary trees are identical.
 *
 * @param r1 The root of the first binary tree.
 * @param r2 The root of the second binary tree.
 * @return True if the two binary trees are identical, false otherwise.
 */
bool is_identical(node *r1, node *r2)
{
    // If both trees are empty, then they are identical
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    // If one tree is empty and the other is not, then they are not identical
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    // If one tree is empty and the other is not, then they are not identical
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    // Recursively check if the left and right subtrees of the two trees are identical
    bool left = is_identical(r1->left, r2->left);
    bool right = is_identical(r1->right, r2->right);

    // Check if the data in the two trees is the same
    bool value = r1->data == r2->data;

    // If all of the above conditions are true, then the two trees are identical
    if (left && right && value)
    {

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root;
    node *root2;
    root = buildtree(root);
    root2 = buildtree(root2);
    Level_order_traversal(root);
    Level_order_traversal(root2);
    if (is_identical(root, root2))
    {
        cout << "trees are identical" << endl;
    }
    else
    {
        cout << "trees are not identical" << endl;
    }
}
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 7 -1 -1 8 -1 -1