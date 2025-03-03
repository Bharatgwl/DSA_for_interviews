#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &sudoku, int row, int cols, char val)
{
    for (int k = 0; k < 9; k++)
    {
        if (sudoku[row][k] == val)
        {
            return false;
        }
        if (sudoku[k][cols] == val)
        {
            return false;
        }
        int boxRow = 3 * (row / 3) + k / 3;
        int boxCol = 3 * (cols / 3) + k % 3;
        if (sudoku[boxRow][boxCol] == val)
        {
            return false;
        }
    }
    return true;
}
bool solvesudoku(vector<vector<char>> &sudoku, vector<vector<char>> &ans)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == '.')
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isSafe(sudoku, i, j, char(k)))
                    {
                        ans[i][j] = char(k);
                        sudoku[i][j] = char(k);
                        if (solvesudoku(sudoku, ans))
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    vector<vector<char>> ans;
    solvesudoku(board, ans);
    board.clear();
    board = ans;
    ans.clear();
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}