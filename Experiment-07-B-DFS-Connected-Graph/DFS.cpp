#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;

    for (int next : adj[node])
    {
        if (!visited[next])
            DFS(next, adj, visited);
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "\nEnter edges (u v)\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    DFS(0, adj, visited);

    bool connected = true;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "\nGraph is Connected.\n";
    else
        cout << "\nGraph is NOT Connected.\n";

    return 0;
}