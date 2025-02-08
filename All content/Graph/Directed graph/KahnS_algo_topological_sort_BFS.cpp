#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

class graph {
public:
    unordered_map<int, set<int>> adj;
    void addEdge(int x, int y, int directed) {
        adj[x].insert(y);
        if (directed == 0) {
            adj[y].insert(x);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

void Kahns(int n, unordered_map<int, set<int>> &adj, vector<int> &ans) {
    unordered_map<int, int> indegree;
    // Initialize indegree of all nodes to 0
    for (auto &node : adj) {
        indegree[node.first] = 0;
    }

    // Calculate indegree
    for (auto &node : adj) {
        for (auto &neighbor : node.second) {
            indegree[neighbor]++;
        }
    }

    // Push nodes with indegree 0 into the queue
    queue<int> q;
    for (auto &node : indegree) {
        if (node.second == 0) {
            q.push(node.first);
        }
    }

    // Perform Kahn's algorithm
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for (auto neighbor : adj[temp]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for a cycle
    if (ans.size() < adj.size()) {
        cout << "There is a cycle in the graph" << endl;
        ans.clear(); // Clear the result if there's a cycle
        return;
    }
}
int main() {
    graph g1;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (format: x y): " << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y, 1);
    }

    vector<int> ans;
    Kahns(n, g1.adj, ans);

    if (!ans.empty()) {
        cout << "Topological Sort: ";
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}