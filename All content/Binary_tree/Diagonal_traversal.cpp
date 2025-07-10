#include <bits/stdc++.h>
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
void Diagonal_traversal(node *root)
{
    if (!root)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        while (curr)
        {
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            curr = curr->right;
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    Diagonal_traversal(root);
// 8 3 10 1 6 -1 14 -1 -1 4 7 13
    return 0;
}