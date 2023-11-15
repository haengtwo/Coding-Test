#include <stdio.h>

#define INF 99999
#define V 10

// 그래프를 표현하는 구조체
typedef struct {
    int vertices;
    int edges[V][V];
} Graph;

// 그래프 초기화 함수
void initializeGraph(Graph* g, int vertices) {
    g->vertices = vertices;

    // 그래프 초기화
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                g->edges[i][j] = 0; // 자기 자신까지의 거리는 0
            }
            else {
                g->edges[i][j] = INF; // 무한대로 초기화
            }
        }
    }
}

// 간선 추가 함수
void insert_edge(Graph* g, int start, int end, int weight) {
    g->edges[start - 1][end - 1] = weight;
}

// Floyd 알고리즘 함수
void floyd(Graph* g, int start, int end) {
    int i, j, k;

    // 거쳐가는 노드
    for (k = 0; k < g->vertices; k++) {
        // 출발 노드
        for (i = 0; i < g->vertices; i++) {
            // 도착 노드
            for (j = 0; j < g->vertices; j++) {
                // 더 짧은 경로를 찾으면 업데이트
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

    // 그래프에 간선 추가
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

    // 최단 거리 계산 및 출력
    floyd(&g, 1, 2);
    floyd(&g, 1, 3);
    floyd(&g, 1, 4);
    floyd(&g, 1, 5);
    floyd(&g, 1, 10);
    floyd(&g, 1, 9);

    return 0;
}
