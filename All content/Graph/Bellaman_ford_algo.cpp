#include <bits/stdc++.h>
using namespace std;
int bellman_ford(int n, int m, vector<vector<int>> &edges, int src, int dest)

{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    for (int i = 1; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    if (dist[dest] == 1e9)
        return -1;
    return dist[dest];
}
int main()
{

    vector<vector<int>> edges{
        {1, 2, 2},
        {2, 3, -1},
        {1, 3, 2}};
    int n = 3;
    int src = 1;
    int dest = 3;
    int m = edges.size();
    int ans = bellman_ford(n, m, edges, src, dest);
    cout << ans << endl;
    return 0;
}