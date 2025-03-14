#include <iostream>
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

node *createmapping(node *root, int target, map<node *, node *> &mapping)
{
    queue<node *> q;
    q.push(root);
    node *res = NULL;
    mapping[root] = NULL;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->data == target)
        {
            res = temp;
        }
        if (temp->left)
        {
            mapping[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mapping[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}
int burnTree(node *targetnode, map<node *, node *> mapping)
{
    int ans = 0;
    map<node *, bool> visited;
    queue<node *> q;
    q.push(targetnode);
    visited[targetnode] = true;
    while (!q.empty())
    {

        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            if (front->left && !(visited[front->left]))
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !(visited[front->right]))
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (mapping[front] && !(visited[mapping[front]]))
            {
                flag = true;
                q.push(mapping[front]);
                visited[mapping[front]] = true;
            }
        }
        if (flag == true)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);

    int target = 8;
    map<node *, node *> nodeTOparent;

    node *targetNode = createmapping(root, target, nodeTOparent);

    int ans = burnTree(targetNode, nodeTOparent);

    cout << "min time to  burn a binary tree: " << ans << " sec" << endl;
} // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
