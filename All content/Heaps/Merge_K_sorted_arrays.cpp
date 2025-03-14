#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
Merge k Sorted Arrays

Given k sorted arrays of size n each, merge them and print the sorted output.
Input:
k = 3 
arr[][] = { {1, 2, 3}, 
            {4, 5, 6}, 
            {7, 8, 9} } 
Output: 
{1, 2, 3, 4, 5, 6, 7, 8, 9}

https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
*/

class node
{
public:
    int data;
    int i;
    int j;
    node(int d, int x, int y)
    {
        this->data = d;
        this->i = x;
        this->j = y;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> res;
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        pq.push(temp);
    }
    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();
        res.push_back(temp->data);
        if (temp->j + 1 < arr[temp->i].size())
        {
            node *temp1 = new node(arr[temp->i][temp->j + 1], temp->i, temp->j + 1);
            pq.push(temp1);
        }
    }
    return res;
}
int main()
{
    int k;
    cin >> k;
    vector<vector<int>> v;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    vector<int> res = mergeKArrays(v, k);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}