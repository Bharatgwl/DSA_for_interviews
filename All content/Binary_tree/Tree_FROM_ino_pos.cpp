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

void createmapping(int INO[], map<int, int> &mp, int n)
{
    for (int i = 0; i < n; i++)
    {
        mp[INO[i]] = i;
    }
}
node *BUILD_tree(int INO[], int POST[], int &PostorderIindex, int startindex, int endindex, int n, map<int, int> &mp)
{
    if (PostorderIindex < 0 || startindex > endindex)
    {
        return NULL;
    }

    int element = POST[PostorderIindex--];
    node *root = new node(element);
    int position = mp[element];
    root->right = BUILD_tree(INO, POST, PostorderIindex, position + 1, endindex, n, mp);

    root->left = BUILD_tree(INO, POST, PostorderIindex, startindex, position - 1, n, mp);

    return root;
}

void Level_order_traversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

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

int main()
{
    int INO[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int POST[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(INO) / sizeof(INO[0]);
    int PostorderIindex = n - 1;
    map<int, int> mapping;
    createmapping(INO, mapping, n);
    node *root = BUILD_tree(INO, POST, PostorderIindex, 0, n - 1, n, mapping);
    Level_order_traversal(root);

    return 0;
}
