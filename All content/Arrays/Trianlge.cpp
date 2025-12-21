#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        cout << "\nInitial Triangle:\n";
        printTriangle(triangle);

        // Bottom-up DP
        for (int i = n - 2; i >= 0; i--)
        {
            cout << "\nProcessing row " << i << ":\n";

            for (int j = 0; j < triangle[i].size(); j++)
            {
                cout << "triangle[" << i << "][" << j << "] = "
                     << triangle[i][j]
                     << " + min("
                     << triangle[i + 1][j] << ", "
                     << triangle[i + 1][j + 1] << ")";

                triangle[i][j] += min(triangle[i + 1][j],
                                      triangle[i + 1][j + 1]);

                cout << " = " << triangle[i][j] << endl;
            }

            cout << "Triangle after updating row " << i << ":\n";
            printTriangle(triangle);
        }

        return triangle[0][0];
    }

    void printTriangle(vector<vector<int>> &triangle)
    {
        for (auto &row : triangle)
        {
            for (int val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // 🔹 INPUT
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    Solution obj;
    int ans = obj.minimumTotal(triangle);

    // 🔹 OUTPUT
    cout << "\nMinimum Path Sum = " << ans << endl;

    return 0;
}
