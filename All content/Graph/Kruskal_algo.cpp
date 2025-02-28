#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, set<pair<int, int>>> adj;
    void addedge(int x, int y, int weight)
    {
        adj[x].insert(make_pair(y, weight));
        adj[y].insert(make_pair(x, weight));
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "]";
            }
            cout << endl;
        }
    }
};
vector<vector<int>> prepareEdgeList(unordered_map<int, set<pair<int, int>>> &adj)
{
    vector<vector<int>> edgeList;
    set<pair<int, int>> seenEdges;
    for (auto &i : adj)
    {
        int u = i.first;
        for (auto &j : i.second)
        {
            int v = j.first;
            int weight = j.second;

            if (seenEdges.find({min(u, v), max(u, v)}) == seenEdges.end())
            {
                edgeList.push_back({u, v, weight});
                seenEdges.insert({min(u, v), max(u, v)});
            }
        }
    }
    return edgeList;
}
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent, parent[node]);
}
void unionOp(vector<int> &parent, int u, int v)
{
    parent[u] = v;
}
void SetDatastructres(vector<int> &parent, vector<int> &rank)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int kruskal(vector<vector<int>> &edgeList, vector<int> &parent, vector<int> &rank)
{
    int cost = 0;
    for (auto i : edgeList)
    {
        int u = i[0]; // 
        int v = i[1];
        int weight = i[2]; // weight of the edge 
        int x = find(parent, u);
        int y = find(parent, v);
        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                unionOp(parent, x, y);
            }
            else if (rank[x] > rank[y])
            {
                unionOp(parent, y, x);
            }
            else
            {
                unionOp(parent, y, x);
                rank[y]++;
            }
            cost += weight;
        }
    }
    return cost;
}
int main()
{
    Graph g;
    g.addedge(1, 2, 1);
    g.addedge(1, 3, 7);
    g.addedge(2, 4, 5);
    g.addedge(3, 4, 2);
    g.addedge(2, 5, 6);
    g.addedge(5, 7, 9);
    g.addedge(5, 6, 3);
    g.addedge(6, 8, 8);
    g.addedge(7, 8, 4);

    // g.printAdjList();
    vector<vector<int>> edgeList = prepareEdgeList(g.adj);
    sort(edgeList.begin(), edgeList.end(), cmp);
    vector<int> parent(edgeList.size());
    vector<int> rank(edgeList.size());
    SetDatastructres(parent, rank);
    int cost = kruskal(edgeList, parent, rank);
    cout << cost << endl;
    return 0;
}