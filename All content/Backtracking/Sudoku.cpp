/**
 * Question link: https://www.geeksforgeeks.org/sudoku/
 * Complexity: O(9^n) where n is the number of empty cells in the Sudoku puzzle.
 */
#include <iostream>
#include <vector>
using namespace std;
/**
 * Checks if the given value is safe to place in the given position in the
 * Sudoku puzzle.
 *
 * @param sudoku The Sudoku puzzle.
 * @param row The row in which to place the value.
 * @param cols The column in which to place the value.
 * @param val The value to place.
 * @return true if it is safe to place the value in the given position, false
 *         otherwise.
 */
bool isSafe(vector<vector<int>> &sudoku, int row, int cols, int val)
{
    for (int k = 0; k < 9; k++)
    {
        // Check the row
        // If the value already exists in the row, it is not safe to place it
        // there.
        if (sudoku[row][k] == val)
        {
            return false;
        }

        // Check the column
        if (sudoku[k][cols] == val)
        {
            return false;
        }
        // Calculate the row and column of the 3x3 box containing the given
        // position.
        int boxRow = 3 * (row / 3) + k / 3;
        int boxCol = 3 * (cols / 3) + k % 3;
        // Check the 3x3 box

        // If the value already exists in the box, it is not safe to place it
        // there.
        if (sudoku[boxRow][boxCol] == val)
        {
            return false;
        }
    }

    // If the value does not exist in the row, column, or box, it is safe to place it there.
    return true;
}
/**
 * @brief Recursively solves a Sudoku puzzle.
 *
 * This function takes a partially filled Sudoku puzzle and attempts to fill it in
 * completely. It works by iterating over each cell of the Sudoku puzzle, and if a
 * cell is empty, it iterates over all possible values (from 1 to 9) and checks if
 * it can be placed in the cell using the 'isSafe' function. If a value can be
 * placed, it is placed and the function is recursively called on the Sudoku
 * puzzle. If the recursive call returns true, then the Sudoku puzzle has been
 * solved and the function returns true. If the recursive call returns false, then
 * the Sudoku puzzle has not been solved and the value is removed and the next
 * value is tried. If no values can be placed in the cell, then the Sudoku puzzle
 * has not been solved and the function returns false.
 *
 * @param sudoku The Sudoku puzzle to be solved.
 * @param ans The partially filled Sudoku puzzle.
 * @return true if the Sudoku puzzle has been solved, false otherwise.
 */
bool solvesudoku(vector<vector<int>> &sudoku, vector<vector<int>> &ans)
{
    // Iterate over each cell of the Sudoku puzzle
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // If the cell is empty, try to fill it in
            if (sudoku[i][j] == 0)
            {
                // Iterate over all possible values from 1 to 9
                for (int k = 1; k <= 9; k++)
                {
                    // Check if the value can be placed in the cell using the 'isSafe' function
                    if (isSafe(sudoku, i, j, k))
                    {
                        // Place the value in the cell
                        ans[i][j] = k;
                        sudoku[i][j] = k;

                        // Recursively call the 'solvesudoku' function on the Sudoku puzzle
                        if (solvesudoku(sudoku, ans))
                        {
                            // If the recursive call returns true, then the Sudoku puzzle has been solved
                            // and the function returns true.
                            return true;
                        }
                        else
                        {
                            // If the recursive call returns false, then the Sudoku puzzle has not been
                            // solved and the value is removed and the next value is tried.
                            sudoku[i][j] = 0;
                        }
                    }
                }

                // If no values can be placed in the cell, then the Sudoku puzzle has not been solved
                // and the function returns false.
                return false;
            }
        }
    }

    // If all cells have been filled in, then the Sudoku puzzle has been solved and the function returns true.
    return true;
}
int main()
{
    vector<vector<int>> sudoku = {{3, NULL, 6, 5, NULL, 8, 4, NULL, NULL},
                                  {5, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                                  {NULL, 8, 7, NULL, NULL, NULL, NULL, 3, 1},
                                  {NULL, NULL, 3, NULL, 1, NULL, NULL, 8, NULL},
                                  {9, NULL, NULL, 8, 6, 3, NULL, NULL, 5},
                                  {NULL, 5, NULL, NULL, 9, NULL, 6, NULL, NULL},
                                  {1, 3, NULL, NULL, NULL, NULL, 2, 5, NULL},
                                  {NULL, NULL, NULL, NULL, NULL, NULL, NULL, 7, 4},
                                  {NULL, NULL, 5, 2, NULL, 6, 3, NULL, NULL}};
    vector<vector<int>> ans = sudoku;

    if (solvesudoku(sudoku, ans))
    {
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "answer is not possible " << endl;
    }

    return 0;
}
