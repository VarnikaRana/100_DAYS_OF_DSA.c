#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Queue structure
struct Queue {
    int items[SIZE];
    int front, rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {
    if (q->rear == SIZE - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q))
        return -1;

    item = q->items[q->front];
    q->front++;

    if (q->front > q->rear)
        q->front = q->rear = -1;

    return item;
}

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS function
void BFS(struct Graph* graph, int startVertex) {
    int visited[SIZE] = {0};

    struct Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }

            temp = temp->next;
        }
    }
}

// Main
int main() {
    int n, m, s;

    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(graph, s);

    return 0;
}
