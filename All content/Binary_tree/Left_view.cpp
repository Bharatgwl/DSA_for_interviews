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
void Left_view(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    Left_view(root->left, ans, level + 1);
    Left_view(root->right, ans, level + 1);
}
int main()
{
    vector<int> ans;
    int level = 0;
    node *root = NULL;
    root = buildtree(root);
    Left_view(root, ans, level);
    for (auto i : ans)
    {
        cout << i << " ";
    }
} // 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1