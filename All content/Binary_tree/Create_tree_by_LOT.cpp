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
void create_tree_by_LOT(node *&root)
{
    queue<node *> q;
    cout << "enter the data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter the left node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "enter the right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
/**
 * Level order traversal of a tree.
 *
 * This function takes in a node pointer to the root of the tree and prints out the tree in level order.
 *
 * Level order traversal is a traversal technique where the nodes are visited one level at a time, from left to right.
 * The algorithm works by using a queue to store the nodes to visit, and a loop to visit each node in the queue.
 *
 * The loop starts by popping the first node from the queue, and printing its data.
 * It then pushes the left and right children of the node onto the queue, if they exist.
 * If the node is NULL, it prints a newline and pushes NULL onto the queue again, to indicate that it has finished visiting the current level.
 * The loop continues until the queue is empty, at which point all the nodes have been visited.
 */
void Level_order_traversal(node *root)
{
    // Create an empty queue to store the nodes to visit
    queue<node *> q;

    // Push the root node onto the queue
    q.push(root);

    // Push NULL onto the queue to indicate that we have finished visiting the first level
    q.push(NULL);

    // Loop until all the nodes have been visited
    while (!q.empty())
    {
        // Pop the first node from the queue
        node *temp = q.front();
        q.pop();

        // If the node is NULL, print a newline and push NULL onto the queue again to indicate that we have finished visiting the current level
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
            // Print the data of the current node
            cout << temp->data << " ";

            // If the left child of the current node exists, push it onto the queue
            if (temp->left)
            {
                q.push(temp->left);
            }

            // If the right child of the current node exists, push it onto the queue
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root;
    create_tree_by_LOT(root);

    Level_order_traversal(root);
    cout<<endl;
    cout<<root->left->left->data<<endl;
}