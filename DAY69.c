#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Structure for Min Heap Node
struct MinHeapNode {
    int v;
    int dist;
};

// Structure for Min Heap
struct MinHeap {
    int size;
    struct MinHeapNode* heap[MAX];
};

// Create new node
struct Node* newNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = newNode(v, w);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

// Swap heap nodes
void swap(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->heap[left]->dist < heap->heap[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->heap[right]->dist < heap->heap[smallest]->dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->heap[i], &heap->heap[smallest]);
        heapify(heap, smallest);
    }
}

// Extract minimum
struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct MinHeapNode* root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;

    int i = heap->size++;
    heap->heap[i] = node;

    while (i && heap->heap[(i - 1) / 2]->dist > heap->heap[i]->dist) {
        swap(&heap->heap[i], &heap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra Algorithm
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    insertHeap(heap, src, 0);

    while (heap->size > 0) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Driver
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 1);

    dijkstra(graph, 0);

    return 0;
}
