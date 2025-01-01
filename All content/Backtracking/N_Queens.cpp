#include <iostream>
#include <vector>
using namespace std;
void add(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, int n, vector<vector<int>> &board)
{
    int x = row;
    int y = col;

    //    checking for the same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    //  checking for the diagnol
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve(int col, int n, vector<vector<int>> &ans, vector<vector<int>> &board)
{
    if (col == n)
    {
        add(ans, board, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 1;
            solve(col + 1, n, ans, board);
            board[row][col] = 0;
        }
    }
}
void N_Queens(int n, vector<vector<int>> &ans)
{
    vector<int> path;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, n, ans, board);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    N_Queens(n, ans);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}