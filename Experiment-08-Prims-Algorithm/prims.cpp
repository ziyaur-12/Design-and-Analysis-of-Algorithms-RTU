#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "\nEnter edges (u v weight)\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> mst(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        int minimum = INT_MAX;

        for (int i = 0; i < V; i++)
        {
            if (!mst[i] && key[i] < minimum)
            {
                minimum = key[i];
                u = i;
            }
        }

        mst[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0;

    cout << "\nEdges in Minimum Spanning Tree\n\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << graph[parent[i]][i] << endl;

        cost += graph[parent[i]][i];
    }

    cout << "\nMinimum Cost = " << cost << endl;

    return 0;
}