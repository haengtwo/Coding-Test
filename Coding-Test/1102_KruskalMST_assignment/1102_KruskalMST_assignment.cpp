#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; // 각 정점의 부모를 저장할 배열

void set_init(int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

int set_find(int curr)
{
    if (parent[curr] == -1)
        return curr; // 현재 정점이 루트인 경우, 자기 자신을 반환
    while (parent[curr] != -1)
        curr = parent[curr]; // 루트까지 올라가면서 부모를 찾음
    return curr; // 루트 반호나
}

void set_union(int a, int b)
{
    int root1 = set_find(a); // a의 루트 찾음
    int root2 = set_find(b); // b의 루트 찾음
    if (root1 != root2)
        parent[root1] = root2;
}

struct Edge { // 간선을 나타내는 구조체
    int start, end, weight;
};

typedef struct GraphType {
    int n; // 간선의 개수
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) // 그래프 초기화
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType* g, int start, int end, int w) // 간선 삽입 연산
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void* a, const void* b) // qsort()에 사용되는 함수
{
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType* g) // kruskal의 최소 비용 신장 트리 프로그램
{
    int edge_accepted = 0; // 현재까지 선택된 간선의 수
    int uset, vset; // 정점 u와 정점 v의 집합 번호
    struct Edge e;

    set_init(g->n); // 집합 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("Kruskal MST Algorithm\n");
    int i = 0;
    while (edge_accepted < (g->n - 1)) { // 간선의 수 < (n-1)
        e = g->edges[i];
        uset = set_find(e.start); // 시작 정점의 루트를 찾음
        vset = set_find(e.end); // 끝 정점의 루트를 찾음
        if (uset != vset) {
            printf("Edge (%d, %d) Select %d\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset); // 두개의 집합을 합침
        }
        i++;
    }
}

typedef struct HeapType {
    struct Edge heap[MAX_VERTICES * 2];
    int heap_size;
} HeapType;

void insert_heap(HeapType* h, struct Edge e) {
    int i = ++(h->heap_size);

    while ((i != 1) && (e.weight < h->heap[i / 2].weight)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = e;
}

struct Edge delete_heap(HeapType* h) {
    struct Edge deleted = h->heap[1];
    struct Edge last = h->heap[h->heap_size--];

    int parent = 1, child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].weight > h->heap[child + 1].weight)) {
            child++;
        }
        if (last.weight <= h->heap[child].weight) {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = last;

    return deleted;
}

void kruskal_with_heap(GraphType* g) {
    int edge_accepted = 0;
    int uset, vset;
    struct Edge e;
    HeapType heap;
    heap.heap_size = 0;

    set_init(g->n);
    for (int i = 0; i < g->n; i++) {
        insert_heap(&heap, g->edges[i]);
    }

    printf("kruskal MST algorithm\n");

    while (edge_accepted < (g->n - 1)) {
        e = delete_heap(&heap);
        uset = set_find(e.start);
        vset = set_find(e.end);

        if (uset != vset) {
            printf("edge (%d, %d) select %d\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);
        }
    }
}

int main() {
    GraphType g;
    graph_init(&g);

    // 간선 추가
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

    // 크루스칼 알고리즘 호출
    kruskal(&g);
    kruskal_with_heap(&g);

    return 0;
}