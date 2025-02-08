#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;
    void addEdge(T x, T y, int directed)
    {
        adj[x].push_back(y);
        if (directed == 0)
        {
            adj[y].push_back(x);
        }
    }
    void printAdjList()
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
    }
};

int main()
{
    graph<char> g1;
    int n;
    cout << "enter the number of nodes" << endl;
    cin >> n;
    int m;
    cout << "enter the number of edges" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char x, y;
        cin >> x >> y;
        g1.addEdge(x, y, 0);
    }
    /* Sample Input
    6
    A B
    B C
    C D
    D E
    E F
    F A
    */
    g1.printAdjList();
}
