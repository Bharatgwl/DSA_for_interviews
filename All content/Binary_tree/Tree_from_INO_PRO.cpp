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
    // Base case: if the current index in preorder exceeds the size of the array
    // or if the start index is greater than the end index, return NULL.
    if (Preorderindex >= n || startindex > endindex)
    {
        return NULL;
    }

    // Get the current element from the preorder array using Preorderindex
    // and increment Preorderindex for the next recursive call.
    int element = PRO[Preorderindex++];

    // Create a new node with the current element.
    node *root = new node(element);

    // Find the position of the current element in the inorder array.
    int position = find_position(INO, element, n);

    // Recursively build the left subtree with the elements before the current
    // element in the inorder array.
    root->left = BUILD_tree(INO, PRO, Preorderindex, startindex, position - 1, n);

    // Recursively build the right subtree with the elements after the current
    // element in the inorder array.
    root->right = BUILD_tree(INO, PRO, Preorderindex, position + 1, endindex, n);

    // Return the root of the constructed subtree.
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
