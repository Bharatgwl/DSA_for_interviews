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
void Right_view(node *root, vector<int> &ans, int level)
{
    // Base case: If the current node is NULL, return immediately as there's nothing to process
    if (root == NULL)
    {
        return;
    }

    // If this is the first node of its level, add it to the answer
    // The size of the 'ans' vector represents the number of levels processed so far
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // Recursively call the right subtree first to ensure rightmost nodes are processed first
    Right_view(root->right, ans, level + 1);

    // Recursively call the left subtree to continue processing other nodes at the current level
    Right_view(root->left, ans, level + 1);
}
int main()
{
    vector<int> ans;
    int level = 0;
    node *root = NULL;
    root = buildtree(root);
    Right_view(root, ans, level);
    for (auto i : ans)
    {
        cout << i << " ";
    }
} // 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1