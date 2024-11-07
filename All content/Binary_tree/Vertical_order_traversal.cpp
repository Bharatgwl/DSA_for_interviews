#include <iostream>
#include <queue>
#include <map>
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
void vertical(node *root, vector<int> &ans)
{
    map<int, map<int, vector<int>>> m;
    queue<pair<node *, pair<int, int>>> q;
    if (root == NULL)
    {
        return;
    }

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        m[hd][lvl].push_back(frontnode->data);
        if (frontnode->left)
        {
            q.push({frontnode->left, {hd - 1, lvl + 1}});
        }
        if (frontnode->right)
        {
            q.push({frontnode->right, {hd + 1, lvl + 1}});
        }
    }
    for (auto i : m)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);

    vector<int> ans;
    vertical(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
} // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1