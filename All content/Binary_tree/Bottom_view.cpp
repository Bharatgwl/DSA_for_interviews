#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildtree(Node *&root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
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
void Bottom_view(Node *&root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    map<int, int> BottomNodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        if (root == NULL)
        {
            return;
        }
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int HD = temp.second;

        BottomNodes[HD] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, HD - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, HD + 1));
        }
    }
    for (auto i : BottomNodes)
    {
        ans.push_back(i.second);
    }
    return;
}
int main()
{
    Node *root = NULL;
    vector<int> ans;
    root = buildtree(root);
    Bottom_view(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}// 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1
