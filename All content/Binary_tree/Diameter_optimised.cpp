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
 * @brief Performs a level order traversal of the binary tree rooted at the given node.
 *
 * This function prints the data of all the nodes in the binary tree in level order.
 * A level order traversal visits all the nodes at a given depth before moving on to the next depth.
 * The traversal starts at the root of the tree, prints the root's data, and then visits the nodes in
 * order from left to right at each depth level.
 *
 * @param root The root of the binary tree to traverse.
 */
void Level_order_traversal(node *root)
{
    // Create a queue to keep track of nodes to be visited
    queue<node *> q;

    // Push the root node onto the queue
    q.push(root);

    // Push a NULL marker to denote the end of the current level
    q.push(NULL);

    // While there are nodes left to process in the queue
    while (!q.empty())
    {
        // Extract the front node from the queue
        node *temp = q.front();
        q.pop();

        // Check if the extracted node is a NULL marker
        if (temp == NULL)
        {
            // Print a newline to indicate the end of a level
            cout << endl;

            // If the queue is not empty, push another NULL marker for the next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // Print the data of the current node
            cout << temp->data << " ";

            // If the current node has a left child, push it onto the queue
            if (temp->left)
            {
                q.push(temp->left);
            }

            // If the current node has a right child, push it onto the queue
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
/**
 * @brief Finds the diameter of a binary tree.
 *
 * This function takes a pointer to the root of a binary tree as input and returns
 * a pair of integers. The first element of the pair is the diameter of the binary
 * tree, and the second element is the height of the binary tree.
 *
 * @param root Pointer to the root of the binary tree.
 * 
 * @return A pair of integers, where the first element is the diameter and the
 * second element is the height.
 */
pair<int, int> fDiameter(node *root)
{
    // Handle the base case where the root is NULL
    if (root == NULL)
    {
        // Return a pair with 0 as the diameter and height
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // Recursively find the diameter and height of the left subtree
    pair<int, int> leftside = fDiameter(root->left);

    // Recursively find the diameter and height of the right subtree
    pair<int, int> rightside = fDiameter(root->right);

    // Calculate the three possible diameters that can be formed by the current node
    // and its subtrees
    int a = leftside.first;
    int b = rightside.first;
    int h = leftside.second + rightside.second + 1;

    // Calculate the maximum of the three possible diameters
    int diameter = max(a, max(b, h));

    // Calculate the maximum height of the left and right subtrees
    int height = max(leftside.second, rightside.second) + 1;

    // Return a pair with the diameter and height
    pair<int, int> ans;
    ans.first = diameter;
    ans.second = height;
    return ans;
}
int main()
{
    node *root;
    root = buildtree(root);
    Level_order_traversal(root);
    cout << fDiameter(root).first << endl;
}//1 2 3 -1 -1 4 -1 -1 5 -1 6 7 -1 -1 8 -1 -1