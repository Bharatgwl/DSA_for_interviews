
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 1 2 4 -1 -1 5  7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1
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
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << " enter the for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lefth = height(root->left);
    int righth = height(root->right);
    int ans = (max(lefth, righth) + 1);
    return ans;
}
int diameter(node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    int ans = max(op1, max(op2, op3));
    return ans;
}

int main()
{
    node *root;
    root = buildtree(root);
    cout << "height is: " << height(root) << endl;
    cout << "diameter is: " << diameter(root) << endl;
}