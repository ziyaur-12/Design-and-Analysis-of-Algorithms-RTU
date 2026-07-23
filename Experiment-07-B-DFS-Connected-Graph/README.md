# Experiment 07(b) - Check Graph Connectivity using DFS

## Aim

To check whether a given graph is connected or not using Depth First Search (DFS).

---

## Objective

Implement DFS traversal to determine whether every vertex in the graph is reachable from a starting vertex.

---

## Theory

Depth First Search (DFS) is a graph traversal algorithm that explores one branch completely before backtracking.

A graph is said to be connected if every vertex is reachable from any other vertex.

DFS uses recursion (or stack) to visit all reachable vertices.

---

## Algorithm

1. Read number of vertices and edges.
2. Create adjacency list.
3. Perform DFS from vertex 0.
4. Mark every visited vertex.
5. After DFS finishes, check every vertex.
6. If all vertices are visited, graph is connected.
7. Otherwise graph is not connected.

---

## Time Complexity

**O(V + E)**

---

## Space Complexity

**O(V)**

---

## Files Included

- dfs.cpp
- input.txt
- graph.png
- output_1.png
- README.md

---

## Sample Input

```text
6
6

0 1
0 2
1 3
2 4
3 5
4 5
```

---

## Sample Output

```text
Graph is Connected.
```

---

## Applications

- Network Connectivity
- Social Networks
- Computer Networks
- Connected Components
- Cycle Detection

---

## Advantages

- Simple implementation
- Requires less memory than BFS
- Useful for graph connectivity checking

---

## Limitations

- Recursive implementation may cause stack overflow for very large graphs.

---

## Result

Successfully checked whether the graph is connected using DFS.

---

## Keywords

DFS, Graph Connectivity, Depth First Search, DAA Lab, RTU, Graph Algorithm
