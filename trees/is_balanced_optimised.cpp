#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node() {}
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
void levelorderTraversal(node *root)
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
pair<bool, int> isbalancedfast(node *root)
{
    if (root == nullptr)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> leftside = isbalancedfast(root->left);
    pair<bool, int> rightside = isbalancedfast(root->right);
    bool leftans = leftside.first;
    bool rightans = rightside.first;
    bool diff = abs(leftside.second - rightside.first) <= 1;
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
    levelorderTraversal(root);
    if (isbalancedfast(root).first)
    {
        cout << "tree is balanced";
    }
    else
    {
        cout << "tree is unbalanced";
    }
} // 1 2 -1 -1 3 -1 -1 input 1
// 1 10 5 11 -1 -1 -1 -1 30 -1 -1 input 2