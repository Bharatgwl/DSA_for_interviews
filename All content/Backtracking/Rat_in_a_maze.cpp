#include <iostream>
#include <vector>
using namespace std;
bool issafe(vector<vector<int>> v1, int x, int y, vector<vector<int>> v2)
{
    if (x >= 0 && x < v1.size() && y >= 0 && y < v1[0].size() && v1[x][y] == 1 && v2[x][y] == 0)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> v1, vector<vector<int>> v2, int x, int y, vector<string> &ans, string path)
{
    if (x == v1.size() - 1 && y == v1[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }
    if (issafe(v1, x + 1, y, v2))
    {
        v2[x][y] = 1;
        solve(v1, v2, x + 1, y, ans, path + "D");
        v2[x][y] = 0;
    }
    if (issafe(v1, x, y - 1, v2))
    {
        v2[x][y] = 1;
        solve(v1, v2, x, y - 1, ans, path + "L");
        v2[x][y] = 0;
    }
    if (issafe(v1, x, y + 1, v2))
    {
        v2[x][y] = 1;
        solve(v1, v2, x, y + 1, ans, path + "R");
        v2[x][y] = 0;
    }
    if (issafe(v1, x - 1, y, v2))
    {
        v2[x][y] = 1;
        solve(v1, v2, x - 1, y, ans, path + "U");
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
