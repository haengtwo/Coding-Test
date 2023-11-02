#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; // �� ������ �θ� ������ �迭

void set_init(int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

int set_find(int curr)
{
    if (parent[curr] == -1)
        return curr; // ���� ������ ��Ʈ�� ���, �ڱ� �ڽ��� ��ȯ
    while (parent[curr] != -1)
        curr = parent[curr]; // ��Ʈ���� �ö󰡸鼭 �θ� ã��
    return curr; // ��Ʈ ��ȣ��
}

void set_union(int a, int b)
{
    int root1 = set_find(a); // a�� ��Ʈ ã��
    int root2 = set_find(b); // b�� ��Ʈ ã��
    if (root1 != root2)
        parent[root1] = root2;
}

struct Edge { // ������ ��Ÿ���� ����ü
    int start, end, weight;
};

typedef struct GraphType {
    int n; // ������ ����
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) // �׷��� �ʱ�ȭ
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType* g, int start, int end, int w) // ���� ���� ����
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void* a, const void* b) // qsort()�� ���Ǵ� �Լ�
{
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType* g) // kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
{
    int edge_accepted = 0; // ������� ���õ� ������ ��
    int uset, vset; // ���� u�� ���� v�� ���� ��ȣ
    struct Edge e;

    set_init(g->n); // ���� �ʱ�ȭ
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("Kruskal MST Algorithm\n");
    int i = 0;
    while (edge_accepted < (g->n - 1)) { // ������ �� < (n-1)
        e = g->edges[i];
        uset = set_find(e.start); // ���� ������ ��Ʈ�� ã��
        vset = set_find(e.end); // �� ������ ��Ʈ�� ã��
        if (uset != vset) {
            printf("Edge (%d, %d) Select %d\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset); // �ΰ��� ������ ��ħ
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

    // ���� �߰�
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

    // ũ�罺Į �˰��� ȣ��
    kruskal(&g);
    kruskal_with_heap(&g);

    return 0;
}