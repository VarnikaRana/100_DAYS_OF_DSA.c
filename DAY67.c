#include <stdio.h>
#include <stdbool.h>

#define MAXN 100

int adj[MAXN][MAXN];
bool visited[MAXN];
int stack[MAXN];
int top = -1;
int V;

// Push into stack
void push(int node) {
    stack[++top] = node;
}

// DFS function
void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological sort
void topoSort() {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (topological order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int edges, u, v;

    scanf("%d", &V);
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Input edges (directed)
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort();

    return 0;
}
