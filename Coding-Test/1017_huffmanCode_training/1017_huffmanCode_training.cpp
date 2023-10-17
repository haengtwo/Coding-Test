#include <stdio.h>
#include <stdlib.h>

// �� ��� ����ü
typedef struct HeapNode {
    char data;
    unsigned freq;
    struct HeapNode* left;
    struct HeapNode* right;
} HeapNode;

// �ּ� �� ����ü
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    HeapNode** array;
} MinHeap;

// ���ο� �� ��� ���� �Լ�
HeapNode* newNode(char data, unsigned freq) {
    HeapNode* temp = (HeapNode*)malloc(sizeof(HeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// �� �� ��� ��ȯ �Լ�
void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// ���ο� �ּ� �� ���� �Լ�
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return minHeap;
}

// �ּ� ���� �����ϴ� �Լ�
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    // ���� �ڽ� ��尡 ����, �󵵼��� �� ������ smallest ����
    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    // ������ �ڽ� ��尡 ����, �󵵼��� �� ������ smallest ����
    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    // ���� ���� smallest ��� ��ȯ, smallest ��ġ���� ��� ȣ��
    if (smallest != idx) {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// �ּ� ������ �ּҰ��� �����ϴ� �Լ�
HeapNode* extractMin(MinHeap* minHeap) {
    HeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// ���ο� ��带 �����ϴ� �Լ�
void insertMinHeap(MinHeap* minHeap, HeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// �����Ϳ� �󵵼��κ��� �ּ� ���� �����ϴ� �Լ�
MinHeap* buildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    int n = size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

    return minHeap;
}

// ������ Ʈ�� ���� �Լ�
HeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    HeapNode* left, * right, * top;

    MinHeap* minHeap = buildMinHeap(data, freq, size);

    while (minHeap->size > 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// ������ �ڵ� ��� �Լ�
void printCodes(HeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// �� ��� �Լ�
void printHeap(MinHeap* minHeap) {
    for (int i = 0; i < minHeap->size; i++) {
        printf("%u ", minHeap->array[i]->freq);
    }
    printf("\n");
}

int main() {
    char data[] = { 'a', 'e', 'i', 'o', 'u', 's', 't' };
    int freq[] = { 10, 15, 12, 3, 4, 13, 1 };
    int size = sizeof(data) / sizeof(data[0]);

    MinHeap* minHeap = buildMinHeap(data, freq, size);

    while (minHeap->size > 1) {
        HeapNode* left = extractMin(minHeap);
        HeapNode* right = extractMin(minHeap);

        HeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);

        printHeap(minHeap);
    }
    // ���������� ���� ��尡 Ʈ���� ��Ʈ ���
    HeapNode* root = extractMin(minHeap);

    int arr[100], top = 0;
    printCodes(root, arr, top);

    return 0;
}

