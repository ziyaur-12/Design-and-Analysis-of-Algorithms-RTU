#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cout << "Enter the no.of vertices: " << flush;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    cout << "Enter adjacency matrix:\n";
    for (int v = 1; v <= n; ++v) {
        for (int w = 1; w <= n; ++w) {
            cin >> adj[v][w];
        }
    }

    cout << "Enter the start vertex: " << flush;
    cin >> s;

    vector<int> visit(n + 1, 0);
    queue<int> q;

    cout << "Reachability of vertex " << s << "\n";
    visit[s] = 1;
    q.push(s);

    bool found = false;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w = 1; w <= n; ++w) {
            if (adj[v][w] == 1 && visit[w] == 0) {
                visit[w] = 1;
                found = true;
                cout << "v" << w << "\t";
                q.push(w);
            }
        }
    }

    if (!found)
        cout << "No path found!!\n";
    else
        cout << "\n";

    return 0;
}
