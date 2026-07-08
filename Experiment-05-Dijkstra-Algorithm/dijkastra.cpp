#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int source)
{
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest Distance from Source Vertex " << source << ":\n\n";

    cout << "Vertex\tDistance\n";

    for(int i=0;i<V;i++)
        cout << i << "\t" << dist[i] << endl;
}

int main()
{
    int V,E;

    cout<<"Enter number of vertices: ";
    cin>>V;

    cout<<"Enter number of edges: ";
    cin>>E;

    vector<vector<pair<int,int>>> adj(V);

    cout<<"\nEnter edges (Source Destination Weight)\n";

    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int source;

    cout<<"\nEnter Source Vertex: ";
    cin>>source;

    dijkstra(V,adj,source);

    return 0;
}