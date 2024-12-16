#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
class node
{
public:
    int data;
    int row;
    int cols;
    node(int data, int row, int cols)
    {
        this->data = data;
        this->row = row;
        this->cols = cols;
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
int Smallest_range_in_KsortredList(vector<vector<int>> &arr, int k)
{
    int mini = INT_MAX, maxi = INT_MIN;
    int n = arr.size();
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        pq.push(temp);
        mini = min(mini, arr[i][0]);
        maxi = max(maxi, arr[i][0]);
    }
    int start = mini, end = maxi;
    int range = (maxi - mini) + 1;
    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();
        mini = temp->data;
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
            range = (maxi - mini) + 1;
        }
        if (temp->cols + 1 < arr[temp->row].size())
        {
            maxi = max(maxi, arr[temp->row][temp->cols + 1]);
            node *temp2 = new node(arr[temp->row][temp->cols + 1], temp->row, temp->cols + 1);
            pq.push(temp2);
        }
        else
        {
            break;
        }
    }
    return range;
}
int main()
{
    vector<vector<int>> arr = {{10, 20, 30, 40}, {15, 25, 35, 45}, {28, 29, 37, 48}, {32, 33, 39, 50}};
    int k = 4;
    cout << Smallest_range_in_KsortredList(arr, k);
}