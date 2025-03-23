#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, minPathCost;

    int findRoot(int node) {
        if (parent[node] != node) {
            parent[node] = findRoot(parent[node]); // Path compression
        }
        return parent[node];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Print the number of nodes
        cout << "Number of nodes: " << n << endl;
        
        // Print all edges
        cout << "Edges: ";
        for (auto& edge : edges) {
            cout << "(" << edge[0] << ", " << edge[1] << ", " << edge[2] << ") ";
        }
        cout << endl;
        
        // Print all queries
        cout << "Queries: ";
        for (auto& q : queries) {
            cout << "(" << q[0] << ", " << q[1] << ") ";
        }
        cout << endl;

        // Initialize the parent vector where each node is its own parent initially
        // Initialize the minPathCost vector with -1, indicating no path calculated yet
        parent.resize(n);
        minPathCost.assign(n, -1);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Process each edge
        for (auto& edge : edges) {
            int source = edge[0], target = edge[1], weight = edge[2];
            int sourceRoot = findRoot(source); // Find root of source node
            int targetRoot = findRoot(target); // Find root of target node

            // Update minPathCost for the source root using bitwise AND operation
            if (minPathCost[sourceRoot] == -1) minPathCost[sourceRoot] = weight;
            else minPathCost[sourceRoot] &= weight;

            // Update minPathCost for the target root using bitwise AND operation
            if (minPathCost[targetRoot] == -1) minPathCost[targetRoot] = weight;
            else minPathCost[targetRoot] &= weight;

            // If roots are different, perform union operation and update minPathCost
            if (sourceRoot != targetRoot) {
                parent[sourceRoot] = targetRoot; // Union operation
                minPathCost[targetRoot] &= minPathCost[sourceRoot]; // Update minPathCost
            }
        }

        vector<int> result;
        // Process each query to find the minimum cost path between nodes
        for (auto& q : queries) {
            int start = q[0], end = q[1];

            // If start and end are the same, cost is 0
            if (start == end) result.push_back(0);
            // If start and end do not have the same root, no path exists, return -1
            else if (findRoot(start) != findRoot(end)) result.push_back(-1);
            // Else, return the minPathCost for the root of the start node
            else result.push_back(minPathCost[findRoot(start)]);
        }

        return result; // Return the result vector containing minimum costs for each query
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 4}, {2, 3, 5}, {3, 4, 6}};
    vector<vector<int>> queries = {{0, 4}, {4, 0}, {1, 3}, {3, 1}};
    vector<int> result = s.minimumCost(5, edges, queries);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}