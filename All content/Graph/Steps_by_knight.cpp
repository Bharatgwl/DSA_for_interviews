#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> steps = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

int minStepToReachTarget(vector<int> &knightPos,
                         vector<int> &targetPos, int n)
{

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    int sx = knightPos[0];
    int sy = knightPos[1];
    int tx = targetPos[0];
    int ty = targetPos[1];

    q.push({sx, sy});
    visited[sx][sy] = true;

    int stepsCount = 0;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto front = q.front();
            int x = front.first;
            int y = front.second;
            q.pop();

            if (x == tx && y == ty)
                return stepsCount;

            for (auto step : steps)
            {
                int nx = x + step.first;
                int ny = y + step.second;

                if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        stepsCount++;
    }
    return -1;
}
int main()
{

    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};

    int n = 6;
    cout << minStepToReachTarget(knightPos, targetPos, n);
    return 0;
}