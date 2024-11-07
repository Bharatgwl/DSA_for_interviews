#include <iostream>
#include <limits.h>
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
node *TREE_from_PREORDER(vector<int> PRE, int mini, int maxi, int &i)
{
    if (i >= PRE.size())
    {
        return NULL;
    }
    if (PRE[i] < mini || PRE[i] > maxi)
    {
        return NULL;
    }
    node *root = new node(PRE[i++]);
    root->left = TREE_from_PREORDER(PRE, mini, root->data, i);
    root->right = TREE_from_PREORDER(PRE, root->data, maxi, i);
    return root;
}
int main()
{
    vector<int> PRE = {20, 10, 5, 15, 13, 35, 30, 42};
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    node *root = TREE_from_PREORDER(PRE, min, max, i);
}