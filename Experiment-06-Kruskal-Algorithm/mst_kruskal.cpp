#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n+1), r(n+1,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Number of vertices (edit this if your graph has a different size)
    int n = 6;

    // TODO: Replace with YOUR graph's edges (u, v, weight).
    // Example placeholder edges:
    vector<Edge> edges = {
        // u, v, w
        {1, 2, 2}, {1, 5, 4}, {1, 4, 1},
        {2, 3, 3}, {2, 6, 7},
    
        
    };

    sort(edges.begin(), edges.end());     // sort by weight
    DSU dsu(n);

    vector<Edge> mst;
    long long totalWeight = 0;

    for(const auto& e : edges){
        if(dsu.unite(e.u, e.v)){
            mst.push_back(e);
            totalWeight += e.w;
            if((int)mst.size() == n-1) break; // MST complete
        }
    }

    if((int)mst.size() != n-1){
        cout << "Graph is not connected. MST doesn't exist.\n";
        return 0;
    }

    cout << "MST edges (u - v : w)\n";
    for(const auto& e : mst){
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    }
    cout << "Total weight = " << totalWeight << "\n";
    return 0;
}
