#include <bits/stdc++.h>
using namespace std;

void matrix_addition(vector<vector<int>> a, vector<vector<int>> b, vector<vector<int>> &c, int r, int col)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (auto i : c)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> b = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> c = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    int r = a.size();
    int col = a[0].size();
    matrix_addition(a, b, c, r, col);

    return 0;
}