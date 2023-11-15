#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 구조체 정의: 각 노드의 인접한 노드를 나타내는 구조체
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// 구조체 정의: 각 노드를 나타내는 구조체
struct AdjList {
    struct AdjListNode* head;
};

// 구조체 정의: 그래프를 나타내는 구조체
struct Graph {
    int V;
    struct AdjList* array;
};

// 새로운 노드를 생성하는 함수
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode =
        (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 그래프를 생성하는 함수
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// 간선을 추가하는 함수
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// 최단 경로를 출력하는 함수
void printDijkstra(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(struct Graph* graph, int src) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    int* found = (int*)malloc(graph->V * sizeof(int));

    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX; // 무한대로 초기화
        found[i] = 0;
    }

    dist[src] = 0; // 출발 노드의 최단 거리를 0으로 설정

    for (int i = 0; i < graph->V - 1; i++) {
        int min_dist = INT_MAX; // 최소 거리를 찾기 위한 변수
        int u; // 현재 선택된 노드

        for (int v = 0; v < graph->V; v++) {
            if (!found[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        found[u] = 1;

        // u를 경유하여 v로 가는 거리가 더 짧으면 업데이트
        struct AdjListNode* node = graph->array[u].head;
        while (node != NULL) {
            int v = node->dest;
            int weight = node->weight;

            if (!found[v] && dist[u] != INT_MAX &&
                dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;

            node = node->next;
        }

        printf("Distance: ");
        for (int j = 0; j < graph->V; j++) {
            if (dist[j] == INT_MAX) {
                printf("* ");
            }
            else {
                printf("%d ", dist[j]);
            }
        }
        printf("\nFound: ");
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", found[j]);
        }
        printf("\n\n");
    }

    printDijkstra(dist, graph->V);

    free(dist);
    free(found);
}

int main() {
    int V = 10;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 5, 11);
    addEdge(graph, 1, 6, 11);
    addEdge(graph, 1, 7, 12);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 2, 6, 7);
    addEdge(graph, 2, 5, 1);
    addEdge(graph, 5, 6, 9);
    addEdge(graph, 2, 7, 8);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 4, 5, 13);
    addEdge(graph, 3, 7, 6);
    addEdge(graph, 3, 8, 5);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 8, 14);
    addEdge(graph, 7, 8, 13);
    addEdge(graph, 4, 10, 16);
    addEdge(graph, 8, 10, 15);
    addEdge(graph, 5, 10, 17);
    addEdge(graph, 5, 9, 18);
    addEdge(graph, 9, 10, 10);

    printf("Dijkstra Algorithm\n");

    dijkstra(graph, 0);

    return 0;
}