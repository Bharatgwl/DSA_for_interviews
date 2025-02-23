#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k)
{
    priority_queue<int> pq;
    int n = grid.size();
    for (int i = 0; i < n; ++i)
    {
        sort(grid[i].rbegin(), grid[i].rend());
        for (int j = 0; j < min((int)grid[i].size(), limits[i]); ++j)
        {
            pq.push(grid[i][j]);
        }
    }
    long long sum = 0;
    while (k-- > 0 && !pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}
int main()
{
    vector<vector<int>> grid = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

    vector<int> limits = {2, 2, 3};
    int k = 3;
    cout << maxSum(grid, limits, k) << endl;
    return 0;
}