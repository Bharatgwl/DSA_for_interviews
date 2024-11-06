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
node *BuildBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = BuildBST(root->left, data);
    }
    else
    {
        root->right = BuildBST(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        BuildBST(root, data);
        cin >> data;
    }
}
pair<bool, int> check_for_balance_bst(node *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }
    pair<bool, int> leftans = check_for_balance_bst(root->left);
    pair<bool, int> rightans = check_for_balance_bst(root->right);
    bool condition = leftans.first && rightans.first && abs(leftans.second - rightans.second) <= 1;
    pair<bool, int> p;
    p.first = condition;
    p.second = max(leftans.second, rightans.second) + 1;
    return p;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    if (check_for_balance_bst(root).first)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}