#include <bits/stdc++.h>
using namespace std;

vector<int> jobSequencing(vector<int> &id,
                          vector<int> &deadline, vector<int> &profit)
{
    int n = id.size();
    vector<int> ans = {0, 0};

    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++)
    {
        jobs.push_back({profit[i], deadline[i]});
    }
    cout << "Jobs: ";
    for (auto j : jobs)
    {
        cout << "(" << j.first << "," << j.second << ") ";
    }
    cout << endl;

    sort(jobs.begin(), jobs.end(),
         greater<pair<int, int>>());
    cout << "Sorted Jobs: ";
    for (auto j : jobs)
    {
        cout << "(" << j.first << "," << j.second << ") ";
    }
    cout << endl;

    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        int start = min(n, jobs[i].second) - 1;
        cout << "Processing Job " << i << endl;
        for (int j = start; j >= 0; j--)
        {
            cout << "Trying slot " << j << endl;
            if (result[j] == -1)
            {
                cout << "Found a slot" << endl;
                result[j] = i;
                break;
            }
        }
    }
    cout << "Result: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            ans[1] += jobs[result[i]].first;
            ans[0]++;
        }
    }
    return ans;
}
int main()
{
    vector<int> id = {1, 2, 3, 4, 5};
    vector<int> deadline = {2, 2,1,3,3};
    vector<int> profit = {20,15,100,5,1};
    vector<int> ans = jobSequencing(id, deadline, profit);
    cout << ans[0] << " " << ans[1];
    return 0;
}
