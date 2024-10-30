#include <iostream>
#include <vector>
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

int find_position(int INO[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (INO[i] == element)
        {
            return i;
        }
    }
    return -1;
}
node *BUILD_tree(int INO[], int PRO[], int &Preorderindex, int startindex, int endindex, int n)
{
    if (Preorderindex >= n || startindex > endindex)
    {
        return NULL;
    }

    int element = PRO[Preorderindex++];
    node *root = new node(element);
    int position = find_position(INO, element, n);

    root->left = BUILD_tree(INO, PRO, Preorderindex, startindex, position - 1, n);
    root->right = BUILD_tree(INO, PRO, Preorderindex, position + 1, endindex, n);

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
    int INO[] = {3, 2, 5, 1, 4, 7, 6, 8};
    int PRO[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int Preorderindex = 0;
    int n = sizeof(INO) / sizeof(INO[0]);

    node *root = BUILD_tree(INO, PRO, Preorderindex, 0, n - 1, n);
    Level_order_traversal(root);

    return 0;
}
