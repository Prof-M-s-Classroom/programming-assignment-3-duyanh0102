#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>
using namespace std;

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* key = new int[numVertices];
    int* parent = new int[numVertices];

    MinHeap heap(numVertices);

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        heap.insert(i, key[i]);
    }

    key[0] = 0;
    heap.decreaseKey(0, 0);

    while (!heap.isEmpty()) {
        int u = heap.extractMin();

        for (int v = 0; v < numVertices; v++) {
            int weight = adjMatrix[u][v];
            if (weight > 0 && heap.isInMinHeap(v) && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                heap.decreaseKey(v, weight);
            }
        }
    }

    int totalCost = 0;
    cout << "Minimum Spanning Tree (Prim's):\n";
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " -- " << i << " (" << adjMatrix[i][parent[i]] << ")\n";
        totalCost += adjMatrix[i][parent[i]];
    }
    cout << "Total Cost: " << totalCost << endl;

    delete[] key;
    delete[] parent;
}

