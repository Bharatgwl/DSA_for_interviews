#include <iostream>
#include <unordered_map>
#include <set> //to store in a sorted order
#include <vector>
#include <queue>
using namespace std;

class graph
{
public:
    unordered_map<int, set<int>> adj;
    void addEdge(int x, int y, int directed)
    {
        adj[x].insert(y);
        if (directed == 0)
        {
            adj[y].insert(x);
        }
    }
    void printAdjset()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

void traverse(int node, unordered_map<int, set<int>> &adjset, unordered_map<int, bool> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto i : adjset[temp])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> BFS(int nodes, unordered_map<int, set<int>> &adjset)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            traverse(i, adjset, visited, ans);
        }
    }
    return ans;
}
int main()
{
    graph g1;
    int n;
    cout << "enter the number of nodes" << endl;
    cin >> n;
    int m;
    cout << "enter the number of edges" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y, 0);
    }
    g1.printAdjset();

    vector<int> ans = BFS(n, g1.adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    /* Sample Input
    6
    A B
    B C
    C D
    D E
    E F
    F A
    */
}
