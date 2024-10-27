#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "enter for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void Top_view(node *&root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    map<int, int> topnodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        if (root == NULL)
        {
            return;
        }
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int HD = temp.second;
        if (topnodes.find(HD) == topnodes.end())
        {
            topnodes[HD] = frontnode->data;
        }
        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, HD - 1));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, HD + 1));
        }
    }
    for (auto i : topnodes)
    {
        ans.push_back(i.second);
    }
    return;
}
int main()
{
    node *root = NULL;
    vector<int> ans;
    root = buildtree(root);
    Top_view(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
// 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1