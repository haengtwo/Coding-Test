#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 999999

// �׷��� ����ü
typedef struct {
    int n; // ������ ��
    int weight[MAX_VERTICES + 1][MAX_VERTICES + 1]; // ������ ����ġ�� ��Ÿ���� ���
} Graph;

// �׷��� �ʱ�ȭ �Լ�
void init_graph(Graph* g, int n) {
    g->n = n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            g->weight[i][j] = INF;
        }
    }
}

// ���� �߰� �Լ�
void insert_edge(Graph* g, int start, int end, int weight) {
    g->weight[start][end] = weight;
    g->weight[end][start] = weight;
}

void prim(Graph* g) {
    int selected[MAX_VERTICES + 1];
    int min_distance[MAX_VERTICES + 1];
    int parent[MAX_VERTICES + 1];

    // �ʱ�ȭ
    for (int i = 1; i <= g->n; i++) {
        min_distance[i] = INF;
        selected[i] = false;
    }

    min_distance[1] = 0; // ���� ���� ����
    parent[1] = -1;

    printf("Prim MST Algorithm\n");
    for (int i = 1; i <= g->n; i++) {
        int u = -1; // ���� ���õ� ����
        for (int j = 1; j <= g->n; j++) {
            if (!selected[j] && (u == -1 || min_distance[j] < min_distance[u])) {
                u = j;
            }
        }

        selected[u] = true;

        if (min_distance[u] != INF) {
            printf("���� %d �߰�\n", u);
        }

        for (int v = 1; v <= g->n; v++) {
            if (g->weight[u][v] != INF && !selected[v] && g->weight[u][v] < min_distance[v]) {
                parent[v] = u;
                min_distance[v] = g->weight[u][v];
            }
        }
    }
}

int main() {
    Graph g;
    init_graph(&g, 10);

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

    prim(&g);

    return 0;
}




