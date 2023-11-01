#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

bool visited[MAX_VERTICES];

// �׷��� �ʱ�ȭ �Լ�
void init_graph(Graph* g, int n) {
    g->num_vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = 0;
        }
        visited[i] = false; // �湮 ���� �ʱ�ȭ
    }
}

// ���� �߰� �Լ�
void insert_edge(Graph* g, int start, int end) {
    g->matrix[start][end] = 1; // ���� �׷����� ��� 1�� ����
    g->matrix[end][start] = 1; // ������ �׷����� ��� �� 1�� ����
}

// ���� �켱 Ž��
void dfs_iterative(Graph* g, int start, int target) {
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }

    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = start; // ���� ��带 ���ÿ� �߰�

    while (top >= 0) {
        int current = stack[top--]; // ���ÿ��� ��� ����
        if (!visited[current]) {
            visited[current] = true;
            printf("%d ", current); // ��� ���
        }

        if (current == target) {
            printf("\nŽ�� ����: %d\n", target);
            int visited_count = 0;
            for (int i = 0; i < g->num_vertices; i++) {
                if (visited[i]) {
                    visited_count++;
                }
            }
            printf("�湮�� ����� ��: %d\n\n\n", visited_count);
            return;
        }

        for (int i = g->num_vertices - 1; i >= 0; i--) {
            if (g->matrix[current][i] == 1 && !visited[i]) {
                stack[++top] = i; // ���ÿ� �߰�
            }
        }
    }
}

// �ʺ� �켱 Ž��
void bfs(Graph* g, int start, int target) {
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = -1;
    bool enqueued[MAX_VERTICES] = { false };

    queue[++rear] = start; // ���� ��带 ť�� �߰�

    while (front <= rear) {
        int current = queue[front++]; // ť���� ��� ����
        if (!visited[current]) {
            visited[current] = true;
            printf("%d ", current);
        }

        if (current == target) {
            printf("\nŽ�� ����: %d\n", target);
            int visited_count = 0;
            for (int i = 0; i < g->num_vertices; i++) {
                if (visited[i]) {
                    visited_count++;
                }
            }
            printf("�湮�� ����� ��: %d\n\n\n", visited_count);
            return;
        }

        for (int i = 0; i < g->num_vertices; i++) {
            if (g->matrix[current][i] == 1 && !enqueued[i]) {
                queue[++rear] = i; // ť�� �߰�
                enqueued[i] = true; // ť�� �߰������� ǥ��
            }
        }
    }
}

int main() {
    Graph g;
    init_graph(&g, 11);

    // ���� �߰�
    insert_edge(&g, 0, 9);
    insert_edge(&g, 0, 6);
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 4);
    insert_edge(&g, 0, 5);
    insert_edge(&g, 2, 4);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 4);
    insert_edge(&g, 3, 4);
    insert_edge(&g, 6, 4);
    insert_edge(&g, 6, 8);
    insert_edge(&g, 6, 7);
    insert_edge(&g, 3, 5);
    insert_edge(&g, 5, 4);
    insert_edge(&g, 1, 5);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 7, 4);
    insert_edge(&g, 1, 7);
    insert_edge(&g, 1, 10);
    insert_edge(&g, 7, 10);
    insert_edge(&g, 8, 9);
    insert_edge(&g, 8, 10);

    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("1     : ���� �켱 Ž��           ��\n");
    printf("2     : �ʺ� �켱 Ž��           ��\n");
    printf("3     : ����                     ��\n");
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n\n");

    while (1) {
        int choice;
        printf("�޴� �Է�: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            int start, target;
            printf("���� ��ȣ�� Ž���� �� �Է�: ");
            scanf_s("%d %d", &start, &target);
            dfs_iterative(&g, start, target);
        }
        else if (choice == 2) {
            int start, target;
            printf("���� ��ȣ�� Ž���� �� �Է�: ");
            scanf_s("%d %d", &start, &target);
            bfs(&g, start, target);
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
