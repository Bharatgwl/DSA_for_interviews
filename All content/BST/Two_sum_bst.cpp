#include <iostream>
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
node *BuildBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = BuildBST(root->left, data);
    }
    else
    {
        root->right = BuildBST(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        BuildBST(root, data);
        cin >> data;
    }
}
void Inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}
/**
 * @brief Determines if there exists a pair of elements in a sorted vector that sum up to a given key.
 *
 * This function takes a sorted vector of integers and a key as input, and returns true if there exists a pair
 * of elements in the vector that sum up to the key, and false otherwise.
 *
 * The algorithm works by setting two pointers, one at the beginning of the vector and one at the end of the vector.
 * It then checks if the sum of the elements at the two pointers is equal to the key. If it is, it returns true.
 * If the sum is less than the key, it moves the left pointer to the right. If the sum is greater than the key, it
 * moves the right pointer to the left. It continues this process until the pointers meet or cross each other.
 * If the pointers meet or cross each other, it means that there is no pair of elements that sum up to the key, so it
 * returns false.
 *
 * @param key The key to check if there exists a pair of elements in the vector that sum up to.
 * @param Inorder The sorted vector of integers to check in.
 * @return True if there exists a pair of elements in the vector that sum up to the key, false otherwise.
 */
bool Twosum(int key, vector<int> Inorder)
{
    int sum = 0;
    int i = 0; // Left pointer
    int j = Inorder.size() - 1; // Right pointer
    while (i < j)
    {
        // Calculate the sum of the elements at the left and right pointers
        sum = Inorder[i] + Inorder[j];

        // If the sum is equal to the key, return true
        if (sum == key)
        {
            return true;
        }
        // If the sum is less than the key, move the left pointer to the right
        else if (sum < key)
        {
            i++;
        }
        // If the sum is greater than the key, move the right pointer to the left
        else
        {
            j--;
        }
    }
    // If the pointers meet or cross each other, return false
    return false;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    int a = 50;
    vector<int> inorder;
    Inorder(root, inorder);
    if (Twosum(a, inorder))
    {
        cout << "sum exist : " << endl;
    }
    else
    {
        cout << "sum doesn't exist : " << endl;
    }
} // 10 6 12 2 8 11 15 -1