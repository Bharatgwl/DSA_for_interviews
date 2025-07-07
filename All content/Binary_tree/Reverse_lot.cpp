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

node *buildtree(node *root)
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
void reverse_level_order(node *root)
{
    queue<node *> q;
    stack<node *> st;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        st.push(temp);
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }
    while (!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    reverse_level_order(root);
}