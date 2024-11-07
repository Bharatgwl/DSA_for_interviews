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
void Level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
pair<bool, int> is_balance(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);

        return p;
    }
    pair<bool, int> leftside = is_balance(root->left);
    pair<bool, int> rightside = is_balance(root->right);
    bool leftans = leftside.first;
    bool rightans = rightside.first;
    bool diff = abs(leftside.second - rightside.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(leftside.second, rightside.second) + 1;
    if (leftans && rightans && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
int main()
{
    node *root;
    root = buildtree(root);
    Level_order_traversal(root);
    if (is_balance(root).first)
    {
        cout << "Tree is balanced";
    }
    else
    {
        cout << "Tree is not balanced";
    }
}