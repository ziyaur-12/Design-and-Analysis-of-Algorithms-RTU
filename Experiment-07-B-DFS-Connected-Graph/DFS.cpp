#include <iostream>
using namespace std;

int visit[20], n, adj[20][20], countNodes = 0;

void dfs(int v) {
    visit[v] = 1;
    countNodes++;
    for (int w = 1; w <= n; w++) {
        if (adj[v][w] == 1 && visit[w] == 0)
            dfs(w);
    }
}

int main() {
    int v, w;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (v = 1; v <= n; v++) {
        for (w = 1; w <= n; w++) {
            cin >> adj[v][w];
        }
    }

    // Initialize all vertices as unvisited
    for (v = 1; v <= n; v++)
        visit[v] = 0;

    // Perform DFS starting from vertex 1
    dfs(1);

    if (countNodes == n)
        cout << "\nThe graph is connected\n";
    else
        cout << "\nThe graph is not connected\n";

    return 0;
}
