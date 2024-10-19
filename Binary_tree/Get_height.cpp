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
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = getheight(root->left);
    int rightheight = getheight(root->right);
    int ans = (max(leftheight, rightheight) + 1);
    return ans;
}
int main()
{
    node *root;
    root=buildtree(root);
    cout << getheight(root);
}//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 