#include <stdio.h>
#include <limits.h>

#define V 10

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // 각 노드까지의 최단 거리를 저장하는 배열
    int found[V]; // 해당 노드를 이미 방문했는지를 나타내는 배열

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // 무한대로 초기화
        found[i] = 0;
    }

    dist[src] = 0; // 출발 노드의 최단 거리를 0으로 설정

    for (int i = 0; i < V - 1; i++) {
        int min_dist = INT_MAX; // 최소 거리를 찾기 위한 변수
        int u; // 현재 선택된 노드

        for (int v = 0; v < V; v++) {
            if (!found[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        found[u] = 1;

        // u를 경유하여 v로 가는 거리가 더 짧으면 업데이트
        for (int v = 0; v < V; v++) {
            if (!found[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }

        printf("Distance: ");
        for (int j = 0; j < V; j++) {
            if (dist[j] == INT_MAX) {
                printf("* ");
            }
            else {
                printf("%d ", dist[j]);
            }
        }
        printf("\nFound: ");
        for (int j = 0; j < V; j++) {
            printf("%d ", found[j]);
        }
        printf("\n\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 11, 12, 0, 0, 0},
        {3, 0, 5, 4, 1, 7, 8, 3, 4, 0},
        {0, 5, 0, 2, 0, 0, 6, 0, 0, 5},
        {0, 4, 2, 0, 13, 0, 0, 6, 0, 16},
        {0, 1, 0, 13, 0, 9, 0, 0, 18, 17},
        {11, 7, 0, 0, 9, 0, 0, 0, 0, 0},
        {12, 8, 6, 0, 0, 0, 0, 13, 13, 0},
        {0, 3, 0, 6, 0, 0, 13, 0, 5, 15},
        {0, 4, 0, 0, 18, 0, 13, 5, 0, 10},
        {0, 0, 5, 16, 17, 0, 0, 15, 10, 0}
    };

    printf("Dijkstra Algorithm\n");

    dijkstra(graph, 0);

    return 0;
}