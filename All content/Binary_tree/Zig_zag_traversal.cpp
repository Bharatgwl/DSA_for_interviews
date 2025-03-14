#include <iostream>
#include <queue>
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
void Zig_zag(node *&root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    bool LtoR = true;
    while (!q.empty())
    {

        int size = q.size();
        vector<int> vec(size);
        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();
            int index = LtoR ? i : size - i - 1;
            vec[index] = frontnode->data;
            if (frontnode->left)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }
        LtoR = !LtoR;
        for (auto i : vec)
        {
            ans.push_back(i);
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);

    vector<int> ans;
    Zig_zag(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
// 1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1