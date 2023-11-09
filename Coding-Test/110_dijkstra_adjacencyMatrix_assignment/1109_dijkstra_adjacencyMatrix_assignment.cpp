#include <stdio.h>
#include <limits.h>

#define V 10

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // �� �������� �ִ� �Ÿ��� �����ϴ� �迭
    int found[V]; // �ش� ��带 �̹� �湮�ߴ����� ��Ÿ���� �迭

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // ���Ѵ�� �ʱ�ȭ
        found[i] = 0;
    }

    dist[src] = 0; // ��� ����� �ִ� �Ÿ��� 0���� ����

    for (int i = 0; i < V - 1; i++) {
        int min_dist = INT_MAX; // �ּ� �Ÿ��� ã�� ���� ����
        int u; // ���� ���õ� ���

        for (int v = 0; v < V; v++) {
            if (!found[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        found[u] = 1;

        // u�� �����Ͽ� v�� ���� �Ÿ��� �� ª���� ������Ʈ
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