#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited, st);
        }
    }

    st.push(node);
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    cout << "\nTopological Ordering:\n";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    return 0;
}