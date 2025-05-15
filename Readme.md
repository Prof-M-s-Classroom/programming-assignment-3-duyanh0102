[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Duy Dao

## Description
This program finds the Minimum Spanning Tree (MST) of a connected, undirected graph using Prim's Algorithm. The graph is represented using an adjacency matrix, and a custom Min Heap is used to effectively select the next minimum edge.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log V)        |
| Extract Min          | O(log V)        |
| Decrease Key         | O(log V)        |
| Prim’s MST Overall   | O(V^2)          |

_Explain why your MST implementation has the above runtime._
Insert in MinHeap: When a new vertex is added, it may have to move up the heap to maintain the min-heap property. In the worst case, it travels from the bottom to the top, which is why it’s O(log V).

Extract Min: This removes the smallest key (the root of the heap). After removal, the heap has to reorganize itself, which also takes O(log V).

Decrease Key: If a vertex already in the heap gets a smaller key, it may need to move up to stay in the correct position. Just like insert, this takes up to log V steps.

Prim’s MST: Since we’re using an adjacency matrix, each vertex checks all other vertices to find the minimum edge. This makes the overall time complexity O(V²), even though the heap operations are fast.

## Assumption
The input graph is connected and undirected

Also, vertices are labeled from 0 to V-1.

## Test Case Description

Test 1 (Basic Connected Graph) input: Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);
g.primMST();

Expected output: Edge: 0 - 1 Weight: 2
Edge: 1 - 2 Weight: 3
Edge: 0 - 3 Weight: 6
Edge: 1 - 4 Weight: 5
Total weight of MST: 16

Test 2 (Disconnected Graph) input: Graph g(4);
g.addEdge(0, 1, 1);
g.addEdge(2, 3, 2);
g.primMST();

Expected output: 0 -- 1 (1)
2 -- 3 (2)
Total weight of MST: 3