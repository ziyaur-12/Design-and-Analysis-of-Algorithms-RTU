#include <stdio.h>
#include <limits.h>

#define N 6
#define INF 9999

int main() {
    int cost[N+1][N+1] = {0}; // 1-based
    // fill adjacency matrix (0 = no direct edge)
    // symmetric matrix
    cost[1][2] = cost[2][1] = 2;
    cost[1][4] = cost[4][1] = 1;
    cost[2][3] = cost[3][2] = 3;
    cost[3][6] = cost[6][3] = 8;
    cost[4][5] = cost[5][4] = 9;
    cost[3][4] = cost[4][3] = 5;
    // extra edges with larger weights (will not be chosen)
    
   
    cost[2][4] = cost[4][2] = 3;
    cost[1][5] = cost[5][1] = 4;
    
    cost[2][6] = cost[6][2] = 7;

    int selected[N+1] = {0}, parent[N+1];
    int key[N+1], i, u, v;

    for (i = 1; i <= N; ++i) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[1] = 0; // start from vertex 1

    for (int count = 1; count <= N; ++count) {
        int min = INF; u = -1;
        for (i = 1; i <= N; ++i)
            if (!selected[i] && key[i] < min) { min = key[i]; u = i; }
        if (u == -1) break;
        selected[u] = 1;

        for (v = 1; v <= N; ++v) {
            if (!selected[v] && cost[u][v] != 0 && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    printf("Edges in MST (u - v : w):\n");
    for (i = 2; i <= N; ++i) {
        if (parent[i] != -1) {
            printf("%d - %d : %d\n", parent[i], i, key[i]);
            total += key[i];
        }
    }
    printf("Total cost = %d\n", total);
    return 0;
}
