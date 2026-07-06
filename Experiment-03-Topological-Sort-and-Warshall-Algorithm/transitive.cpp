#include <iostream>
#include <vector>

using namespace std;

void warshall(vector<vector<int>> &reach, int V)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> reach(V, vector<int>(V, 0));

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        reach[u][v] = 1;
    }

    for (int i = 0; i < V; i++)
        reach[i][i] = 1;

    warshall(reach, V);

    cout << "\nTransitive Closure Matrix:\n\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}