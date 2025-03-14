#include <iostream>
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
 * @brief Find the kth sum path in a tree.
 *
 * @param root The root of the tree.
 * @param k The sum we are looking for.
 * @param count The number of paths with the given sum.
 * @param path The current path we are exploring.
 *
 * @details
 *      This function finds the kth sum path in a tree. It works by recursively
 *      exploring the tree and keeping track of the current path. The path is
 *      stored in the 'path' vector and the sum of the path is calculated at each
 *      recursive call. If the sum of the path is equal to 'k', the count is
 *      incremented. Finally, the path is popped back and the function returns.
 */
void Kth_Sum_tree(node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        // If the root is NULL, there is no more tree to explore, so we return.
        return;
    }

    // Add the current node's data to the path.
    path.push_back(root->data);

    // Recursively explore the left subtree.
    Kth_Sum_tree(root->left, k, count, path);

    // Recursively explore the right subtree.
    Kth_Sum_tree(root->right, k, count, path);

    // Calculate the sum of the path.
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];

        // If the sum is equal to k, increment the count.
        if (sum == k)
        {
            count++;
        }
    }

    // Pop the current node's data from the path.
    path.pop_back();
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    vector<int> path;
    int k = 4;
    int count = 0;
    Kth_Sum_tree(root, k, count, path);
    cout << count << endl;
}