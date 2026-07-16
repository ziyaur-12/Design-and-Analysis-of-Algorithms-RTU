#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, Rank;

    DSU(int n) {
        parent.resize(n);
        Rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (Rank[a] < Rank[b])
            swap(a, b);

        parent[b] = a;

        if (Rank[a] == Rank[b])
            Rank[a]++;

        return true;
    }
};

int main() {

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges;

    cout << "\nEnter edges (u v weight)\n";

    for (int i = 0; i < e; i++) {
        Edge x;
        cin >> x.u >> x.v >> x.w;
        edges.push_back(x);
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    vector<Edge> mst;
    int totalWeight = 0;

    for (auto edge : edges) {

        if (dsu.unite(edge.u, edge.v)) {

            mst.push_back(edge);
            totalWeight += edge.w;

            if ((int)mst.size() == n - 1)
                break;
        }
    }

    if ((int)mst.size() != n - 1) {
        cout << "\nGraph is not connected.\n";
        return 0;
    }

    cout << "\nEdges in Minimum Spanning Tree\n\n";

    for (auto edge : mst) {
        cout << edge.u << " -- "
             << edge.v << " == "
             << edge.w << endl;
    }

    cout << "\nMinimum Cost = " << totalWeight << endl;

    return 0;
}