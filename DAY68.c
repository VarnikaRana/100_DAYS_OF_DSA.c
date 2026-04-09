#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;
int result[MAX];

int main() {
    int V, E, u, v;

    scanf("%d", &V);   // number of vertices
    scanf("%d", &E);   // number of edges

    // Initialize
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    // Kahn's Algorithm
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Check cycle
    if (count != V) {
        printf("Cycle exists. Topological sort not possible\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < V; i++)
            printf("%d ", result[i]);
    }

    return 0;
}
