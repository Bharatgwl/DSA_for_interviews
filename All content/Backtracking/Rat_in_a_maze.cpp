#include <iostream>
#include <vector>
using namespace std;
/**
 * Checks if a given position (x, y) is safe to move to in the rat-in-a-maze problem.
 *
 * @param v1 The original maze.
 * @param x The row of the position to check.
 * @param y The column of the position to check.
 * @param v2 A 2D array that keeps track of all the positions that have been visited.
 * @return true if the position is safe to move to, false otherwise.
 *
 * A position is considered safe if it is within the bounds of the maze, if the
 * value at that position in the maze is 1, and if the position has not been
 * visited before (i.e., the value at that position in v2 is 0).
 */
bool issafe(vector<vector<int>> v1, int x, int y, vector<vector<int>> v2)
{
    // Check if the position is within the bounds of the maze.
    if (x >= 0 && x < v1.size() && y >= 0 && y < v1[0].size())
    {
        // Check if the value at the position in the maze is 1.
        if (v1[x][y] == 1)
        {
            // Check if the position has not been visited before.
            if (v2[x][y] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
/**
 * Recursively solves the rat-in-a-maze problem by checking all possible paths and
 * storing the paths that lead to the destination in a vector of strings.
 *
 * @param v1 The original maze.
 * @param v2 A 2D array that keeps track of all the positions that have been visited.
 * @param x The current row.
 * @param y The current column.
 * @param ans A vector of strings that stores all the paths that lead to the destination.
 * @param path The current path being explored.
 *
 * The function works by first checking if the current position is the destination.
 * If it is, the current path is added to the vector of paths and the function returns.
 *
 * Otherwise, the function checks all four directions (up, down, left, right) to see
 * if the position in that direction is safe to move to. If it is, the function
 * recursively calls itself with the new position and the current path plus the
 * direction of movement (U, D, L, R). If the recursive call returns true, then
 * the path is added to the vector of paths and the function returns true.
 *
 * If none of the directions are safe to move to, then the function returns false.
 */
void solve(vector<vector<int>> v1, vector<vector<int>> v2, int x, int y, vector<string> &ans, string path)
{
    // Check if the current position is the destination.
    if (x == v1.size() - 1 && y == v1[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }

    // Check all four directions to see if the position in that direction is safe to move to.
    if (issafe(v1, x + 1, y, v2))
    {
        // Mark the current position as visited.
        v2[x][y] = 1;

        // Recursively call the function with the new position and the current path plus the
        // direction of movement (D).
        solve(v1, v2, x + 1, y, ans, path + "D");

        // Unmark the current position as visited.
        v2[x][y] = 0;
    }

    if (issafe(v1, x, y - 1, v2))
    {
        // Mark the current position as visited.
        v2[x][y] = 1;

        // Recursively call the function with the new position and the current path plus the
        // direction of movement (L).
        solve(v1, v2, x, y - 1, ans, path + "L");

        // Unmark the current position as visited.
        v2[x][y] = 0;
    }

    if (issafe(v1, x, y + 1, v2))
    {
        // Mark the current position as visited.
        v2[x][y] = 1;

        // Recursively call the function with the new position and the current path plus the
        // direction of movement (R).
        solve(v1, v2, x, y + 1, ans, path + "R");

        // Unmark the current position as visited.
        v2[x][y] = 0;
    }

    if (issafe(v1, x - 1, y, v2))
    {
        // Mark the current position as visited.
        v2[x][y] = 1;

        // Recursively call the function with the new position and the current path plus the
        // direction of movement (U).
        solve(v1, v2, x - 1, y, ans, path + "U");

        // Unmark the current position as visited.
        v2[x][y] = 0;
    }
    return;
}
vector<string> rat_in_maze(vector<vector<int>> &v1, vector<vector<int>> v2, int x, int y)
{
    vector<string> ans = {};
    string path = "";
    if (v1[x][y] == 0)
    {
        return ans;
    }

    solve(v1, v2, x, y, ans, path);
    return ans;
}
int main()
{
    vector<vector<int>> v1 = {{1, 0, 0, 0},
                              {1, 1, 0, 0},
                              {1, 1, 0, 0},
                              {1, 1, 1, 1}};
    vector<vector<int>> v2(v1.size(), vector<int>(v1[0].size(), 0));
    vector<string> ans = rat_in_maze(v1, v2, 0, 0);
    for (auto path : ans)
    {
        cout << path << endl;
    }
    return 0;
}

