
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool util(vector<vector<int>> &arr)
    {

        int count = 0;
        int backcoordinate = arr[0][1];

        for (auto range : arr)
        {
            int s = range[0];
            int e = range[1];

            if (s >= backcoordinate)
            {
                count++;
            }
            if (e > backcoordinate)
            {
                backcoordinate = e;
            }
        }

        return count >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<vector<int>> xsample;
        vector<vector<int>> ysample;
        for (auto row : rectangles)
        {
            xsample.push_back({row[0], row[2]});
            ysample.push_back({row[1], row[3]});
        }
        sort(xsample.begin(), xsample.end());
        sort(ysample.begin(), ysample.end());
        if (util(xsample) || util(ysample))
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    cout << s.checkValidCuts(4, rectangles);

    return 0;
}