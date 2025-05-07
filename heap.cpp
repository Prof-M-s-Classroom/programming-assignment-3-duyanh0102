#include "heap.h"
#include <iostream>
#include <climits>
using namespace std;

MinHeap::MinHeap(int cap) {
    capacity = cap;
    size = 0;
    heapArray = new int[cap];
    keyArray = new int[cap];
    position = new int[cap];

    for (int i = 0; i < cap; i++) {
        heapArray[i] = i;
        keyArray[i] = INT_MAX;
        position[i] = i;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

void MinHeap::insert(int vertex, int key) {
    keyArray[vertex] = key;
    heapArray[size] = vertex;
    position[vertex] = size;
    int i = size++;

    while (i > 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    keyArray[vertex] = newKey;
    int i = position[vertex];

    while (i > 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

int MinHeap::extractMin() {
    if (size == 0) return -1;

    int minVertex = heapArray[0];
    heapArray[0] = heapArray[size - 1];
    position[heapArray[0]] = 0;
    size--;
    minHeapify(0);

    return minVertex;
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size;
}

void MinHeap::minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;

    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    if (smallest != i) {
        swap(heapArray[i], heapArray[smallest]);
        position[heapArray[i]] = i;
        position[heapArray[smallest]] = smallest;
        minHeapify(smallest);
    }
}

