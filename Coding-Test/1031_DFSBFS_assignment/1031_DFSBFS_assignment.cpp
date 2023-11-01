#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

bool visited[MAX_VERTICES];

// 그래프 초기화 함수
void init_graph(Graph* g, int n) {
    g->num_vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = 0;
        }
        visited[i] = false; // 방문 여부 초기화
    }
}

// 간선 추가 함수
void insert_edge(Graph* g, int start, int end) {
    g->matrix[start][end] = 1; // 방향 그래프일 경우 1로 설정
    g->matrix[end][start] = 1; // 무방향 그래프일 경우 다 1로 설정
}

// 깊이 우선 탐색
void dfs_iterative(Graph* g, int start, int target) {
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }

    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = start; // 시작 노드를 스택에 추가

    while (top >= 0) {
        int current = stack[top--]; // 스택에서 노드 꺼냄
        if (!visited[current]) {
            visited[current] = true;
            printf("%d ", current); // 노드 출력
        }

        if (current == target) {
            printf("\n탐색 성공: %d\n", target);
            int visited_count = 0;
            for (int i = 0; i < g->num_vertices; i++) {
                if (visited[i]) {
                    visited_count++;
                }
            }
            printf("방문한 노드의 수: %d\n\n\n", visited_count);
            return;
        }

        for (int i = g->num_vertices - 1; i >= 0; i--) {
            if (g->matrix[current][i] == 1 && !visited[i]) {
                stack[++top] = i; // 스택에 추가
            }
        }
    }
}

// 너비 우선 탐색
void bfs(Graph* g, int start, int target) {
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = -1;
    bool enqueued[MAX_VERTICES] = { false };

    queue[++rear] = start; // 시작 노드를 큐에 추가

    while (front <= rear) {
        int current = queue[front++]; // 큐에서 노드 꺼냄
        if (!visited[current]) {
            visited[current] = true;
            printf("%d ", current);
        }

        if (current == target) {
            printf("\n탐색 성공: %d\n", target);
            int visited_count = 0;
            for (int i = 0; i < g->num_vertices; i++) {
                if (visited[i]) {
                    visited_count++;
                }
            }
            printf("방문한 노드의 수: %d\n\n\n", visited_count);
            return;
        }

        for (int i = 0; i < g->num_vertices; i++) {
            if (g->matrix[current][i] == 1 && !enqueued[i]) {
                queue[++rear] = i; // 큐에 추가
                enqueued[i] = true; // 큐에 추가했음을 표시
            }
        }
    }
}

int main() {
    Graph g;
    init_graph(&g, 11);

    // 간선 추가
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

    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("1     : 깊이 우선 탐색           ㅣ\n");
    printf("2     : 너비 우선 탐색           ㅣ\n");
    printf("3     : 종료                     ㅣ\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n\n");

    while (1) {
        int choice;
        printf("메뉴 입력: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            int start, target;
            printf("시작 번호와 탐색할 값 입력: ");
            scanf_s("%d %d", &start, &target);
            dfs_iterative(&g, start, target);
        }
        else if (choice == 2) {
            int start, target;
            printf("시작 번호와 탐색할 값 입력: ");
            scanf_s("%d %d", &start, &target);
            bfs(&g, start, target);
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
