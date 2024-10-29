#include <iostream>
#include <algorithm>
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
pair<int, int> Sum_of_adjacent_node(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }
    pair<int, int> left = Sum_of_adjacent_node(root->left);
    pair<int, int> right = Sum_of_adjacent_node(root->right);
    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    pair<int, int> ans = Sum_of_adjacent_node(root);
    // cout << ans.first << " " << ans.second << endl;
    int x = max(ans.first, ans.second);
    cout << x << endl;
}