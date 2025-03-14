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
void inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);

}

/**
 * @brief Merge two sorted vectors into one sorted vector.
 *
 * @param v1 The first sorted vector to be merged.
 * @param v2 The second sorted vector to be merged.
 * @return A sorted vector containing all the elements of v1 and v2.
 *
 * @details
 *      This function merges two sorted vectors into one sorted vector. It works by
 *      iterating through both vectors simultaneously and comparing the elements at
 *      the current indices. The smaller element is added to the resulting vector and
 *      the index of the corresponding vector is incremented. This process is repeated
 *      until all the elements of both vectors have been added to the resulting vector.
 */
vector<int> merge(vector<int> v1, vector<int> v2)
{
    int i = 0; // The index of the first vector
    int j = 0; // The index of the second vector
    int k = 0; // The index of the resulting vector
    vector<int> ans(v1.size() + v2.size()); // The resulting vector
    
    // Iterate through both vectors and add the smaller element to the resulting vector
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            ans[k] = v1[i++]; // Add the smaller element from the first vector
            k++; // Increment the index of the resulting vector
        }
        else
        {
            ans[k] = v2[j++]; // Add the smaller element from the second vector
            k++; // Increment the index of the resulting vector
        }
    }

    // Add any remaining elements from the first vector
    while (i < v1.size())
    {
        ans[k] = v1[i++];
        k++;
    }

    // Add any remaining elements from the second vector
    while (j < v2.size())
    {
        ans[k] = v2[j++];
        k++;
    }

    return ans; // Return the resulting sorted vector
}
/**
 * @brief Creates a balanced Binary Search Tree from a sorted vector.
 *
 * @param ans The sorted vector from which the tree should be built.
 * @param s The start index of the vector. This is the index of the first element that should be considered
 *          when building the tree.
 * @param e The end index of the vector. This is the index of the last element that should be considered
 *          when building the tree.
 * @return The root of the Binary Search Tree.
 * 
 * @details
 *      This function builds a balanced Binary Search Tree from the given sorted vector. It works by finding
 *      the middle element of the vector and making it the root of the tree. It then recursively builds the
 *      left and right sub-trees of the root.
 */
node *TREE_from_Inorder(vector<int> ans, int s, int e)
{
    if (s > e)
    {
        // If the start index is greater than the end index, it means that there are no more elements
        // in the vector to consider. In this case, we simply return NULL as the root of the tree.
        return NULL;
    }

    int mid = (s + e) / 2;
    // The middle element of the vector is the root of the tree.
    node *root = new node(ans[mid]);

    // The left sub-tree of the root should contain all the elements in the vector with indices less than mid.
    // To build the left sub-tree, we recursively call this function with the start index as s and the end index as mid-1.
    root->left = TREE_from_Inorder(ans, s, mid - 1);

    // The right sub-tree of the root should contain all the elements in the vector with indices greater than mid.
    // To build the right sub-tree, we recursively call this function with the start index as mid+1 and the end index as e.
    root->right = TREE_from_Inorder(ans, mid + 1, e);

    // Finally, we return the root of the tree.
    return root;
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    takeinput(root1);
    takeinput(root2);
    vector<int> v1;
    vector<int> v2;
    inorder(root1, v1);
    inorder(root2, v2);
    vector<int> mergedvector = merge(v1, v2);
    node *root3 = TREE_from_Inorder(mergedvector, 0, mergedvector.size() - 1);
    v1.clear();
    inorder(root3, v1);
    for (auto i : v1)
    {
        cout << i << " ";
    }
}
 // 40 50 60 70 -1 65 45 35 47 75 -1