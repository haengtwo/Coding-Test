#include <stdio.h>

#define INF 99999
#define V 10

// �׷����� ǥ���ϴ� ����ü
typedef struct {
    int vertices;
    int edges[V][V];
} Graph;

// �׷��� �ʱ�ȭ �Լ�
void initializeGraph(Graph* g, int vertices) {
    g->vertices = vertices;

    // �׷��� �ʱ�ȭ
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                g->edges[i][j] = 0; // �ڱ� �ڽű����� �Ÿ��� 0
            }
            else {
                g->edges[i][j] = INF; // ���Ѵ�� �ʱ�ȭ
            }
        }
    }
}

// ���� �߰� �Լ�
void insert_edge(Graph* g, int start, int end, int weight) {
    g->edges[start - 1][end - 1] = weight;
}

// Floyd �˰��� �Լ�
void floyd(Graph* g, int start, int end) {
    int i, j, k;

    // ���İ��� ���
    for (k = 0; k < g->vertices; k++) {
        // ��� ���
        for (i = 0; i < g->vertices; i++) {
            // ���� ���
            for (j = 0; j < g->vertices; j++) {
                // �� ª�� ��θ� ã���� ������Ʈ
                if (g->edges[i][k] + g->edges[k][j] < g->edges[i][j]) {
                    g->edges[i][j] = g->edges[i][k] + g->edges[k][j];
                }
            }
        }
    }

    printf("Start Node: %d\n", start);
    printf("End Node: %d\n", end);
    printf("Shortest Distance: %d\n", g->edges[start - 1][end - 1]);
    printf("\n");
}

int main() {
    Graph g;
    initializeGraph(&g, V);

    // �׷����� ���� �߰�
    insert_edge(&g, 1, 6, 11);
    insert_edge(&g, 1, 7, 12);
    insert_edge(&g, 1, 2, 3);
    insert_edge(&g, 2, 6, 7);
    insert_edge(&g, 2, 5, 1);
    insert_edge(&g, 5, 6, 9);
    insert_edge(&g, 2, 7, 8);
    insert_edge(&g, 2, 3, 5);
    insert_edge(&g, 2, 4, 4);
    insert_edge(&g, 4, 5, 13);
    insert_edge(&g, 3, 7, 6);
    insert_edge(&g, 3, 8, 5);
    insert_edge(&g, 3, 4, 2);
    insert_edge(&g, 4, 8, 14);
    insert_edge(&g, 7, 8, 13);
    insert_edge(&g, 4, 10, 16);
    insert_edge(&g, 8, 10, 15);
    insert_edge(&g, 5, 10, 17);
    insert_edge(&g, 5, 9, 18);
    insert_edge(&g, 9, 10, 10);

    printf("Floyd-Warshall Algorithm\n");

    // �ִ� �Ÿ� ��� �� ���
    floyd(&g, 1, 2);
    floyd(&g, 1, 3);
    floyd(&g, 1, 4);
    floyd(&g, 1, 5);
    floyd(&g, 1, 10);
    floyd(&g, 1, 9);

    return 0;
}
