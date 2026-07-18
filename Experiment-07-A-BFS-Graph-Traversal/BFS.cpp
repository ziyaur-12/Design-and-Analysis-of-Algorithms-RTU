#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "\nEnter directed edges (u v)\n";

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    int start;

    cout<<"\nEnter starting vertex: ";
    cin>>start;

    vector<bool> visited(V,false);

    queue<int> q;

    visited[start]=true;
    q.push(start);

    cout<<"\nNodes reachable using BFS:\n";

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int next:adj[node])
        {
            if(!visited[next])
            {
                visited[next]=true;
                q.push(next);
            }
        }
    }

    cout<<endl;

    return 0;
}