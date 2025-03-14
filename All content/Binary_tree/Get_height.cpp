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
int getheight(node *root)
{
    // Base case: if the tree is empty, return 0
    if (root == NULL)
    {
        return 0;
    }

    // Recursively calculate the height of the left subtree
    int leftheight = getheight(root->left);

    // Recursively calculate the height of the right subtree
    int rightheight = getheight(root->right);

    // The height of the tree is the maximum of the heights of the two
    // subtrees, plus one (for the root node)
    int ans = (max(leftheight, rightheight) + 1);

    // Return the calculated height
    return ans;
}

int main()
{
    node *root;
    root=buildtree(root);
    cout << getheight(root);
}//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 