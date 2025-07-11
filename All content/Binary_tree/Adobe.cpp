#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;
const int LOG = 17;

vector<int> tree[MAXN];
int depth[MAXN], parent[MAXN][LOG];
int N, Q;

void bfs(int root = 1) {
    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(root);
    visited[root] = true;
    depth[root] = 0;
    parent[root][0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (!visited[v]) {
                visited[v] = true;
                depth[v] = depth[u] + 1;
                parent[v][0] = u;
                q.push(v);
            }
        }
    }
}

void preprocess() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            if (parent[i][j - 1])
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = LOG - 1; i >= 0; i--) {
        if ((diff >> i) & 1)
            u = parent[u][i];
    }
    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

int main() {
    cin >> N >> Q;
    vector<int> from(N - 1), to(N - 1);

    for (int i = 0; i < N - 1; i++) cin >> from[i];
    for (int i = 0; i < N - 1; i++) cin >> to[i];

    for (int i = 0; i < N - 1; i++) {
        tree[from[i]].push_back(to[i]);
        tree[to[i]].push_back(from[i]);
    }

    bfs();
    preprocess();

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b); // mini-station
        int cost = distance(a, c) + distance(b, c) + distance(c, 1);
        cout << cost << endl;
    }

    return 0;
}
