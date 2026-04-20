#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} AdjList;

AdjList graph[MAX];
int dist[MAX];
int visited[MAX];

int minDistance(int n) {
    int min = INT_MAX, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int n, int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(n);
        if (u == -1) break;
        visited[u] = 1;

        for (int j = 0; j < graph[u].size; j++) {
            int v = graph[u].edges[j].v;
            int w = graph[u].edges[j].weight;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        graph[i].size = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].edges[graph[u].size++] = (Edge){v, w};
        graph[v].edges[graph[v].size++] = (Edge){u, w}; // undirected
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
