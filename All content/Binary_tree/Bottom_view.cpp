#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildtree(Node *&root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
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
 * This function prints the bottom view of a binary tree.
 * The bottom view of a binary tree is the set of nodes that are visible when the tree is viewed from the bottom.
 * The function takes the root of the tree as the first argument and an empty vector as the second argument.
 * The function returns the vector which contains the bottom view of the tree.
 * The approach used is to perform a level order traversal of the tree and store the nodes of the tree in a map.
 * The key of the map is the horizontal distance of the node from the root and the value is the node itself.
 * The horizontal distance of the root is 0 and the horizontal distance of the left child of a node is the horizontal distance of the node - 1 and the horizontal distance of the right child of a node is the horizontal distance of the node + 1.
 * At the end of the function, the map is traversed and the nodes are pushed into the vector in the order they were inserted into the map.
 */
void Bottom_view(Node *&root, vector<int> &ans)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // Create a map to store the nodes of the tree
    map<int, int> BottomNodes;

    // Create a queue to store the nodes to visit
    queue<pair<Node *, int>> q;

    // Push the root node onto the queue with horizontal distance 0
    q.push(make_pair(root, 0));

    // Loop until all the nodes have been visited
    while (!q.empty())
    {
        // Pop the first node from the queue
        pair<Node *, int> temp = q.front();
        q.pop();

        // Get the node and its horizontal distance
        Node *frontNode = temp.first;
        int HD = temp.second;

        // Store the node in the map with its horizontal distance as the key
        BottomNodes[HD] = frontNode->data;

        // Push the left child of the node onto the queue with horizontal distance HD - 1
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, HD - 1));
        }

        // Push the right child of the node onto the queue with horizontal distance HD + 1
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, HD + 1));
        }
    }

    // Loop through the map and push the nodes into the vector in the order they were inserted
    for (auto i : BottomNodes)
    {
        ans.push_back(i.second);
    }

    // Return the vector
    return;
}
int main()
{
    Node *root = NULL;
    vector<int> ans;
    root = buildtree(root);
    Bottom_view(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}// 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1
