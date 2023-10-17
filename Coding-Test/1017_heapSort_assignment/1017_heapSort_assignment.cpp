#include <stdio.h>

// �迭 ��� ��ȯ �Լ�
void swap(int* a, int* b) {
    int temp = *a; // �ӽ� ������ ���� �� ������ ���� ��ȯ
    *a = *b; // a�� b���� �Ҵ�
    *b = temp; // b�� �ӽ� ���� ���� �Ҵ�
}

// �ִ� �� ���� �Լ�
void maxHeap(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left; // ���� �ڽ� ��带 ���� ū ������ ����

    if (right < n && arr[right] > arr[largest])
        largest = right; // ������ �ڽ� ��带 ���� ū ������ ����

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);
    }
}

// �� ���� ���� �Լ�
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // �ִ밪�� �迭 ���� ��ȯ
        maxHeap(arr, i, 0); // ����� ���¿��� �ٽ� �ִ� ���� ����

        // �ش� ������ �� ���� ���
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                printf("%d ", arr[j]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int arr[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 34, 85, 29, 78, 41, 56, 86 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}