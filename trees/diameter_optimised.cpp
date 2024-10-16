
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
pair<int, int> diameter(node *&root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> leftheight = diameter(root->left);
    pair<int, int> rightheight = diameter(root->right);
    int op1 = leftheight.first;
    int op2 = rightheight.first;
    int op3 = leftheight.second + rightheight.second + 1;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(leftheight.second, rightheight.second) + 1;
    return ans;
}

int main()
{
    node *root;
    root = buildtree(root);
    cout << "height is: " << diameter(root).second << endl;
    cout << "diameter is: " << diameter(root).first << endl;
}