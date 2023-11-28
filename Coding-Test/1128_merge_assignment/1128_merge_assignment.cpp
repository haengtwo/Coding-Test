#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// �迭 ��� �Լ�
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �պ� �Լ�
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ���ʰ� ������ �κ� �迭�� ���� ������ ����
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // ���� �κ� �迭 ����
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // ������ �κ� �迭 ����
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �ӽ� �迭�� �պ��Ͽ� ���ĵ� ��� ����
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ���� ��ҵ� ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // �������� �Ҵ��� �޸� ����
    free(L);
    free(R);
}

// �պ� ���� �Լ�
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // �߰� ���� ���
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // �պ� ����
        merge(arr, left, mid, right);

        // �κ� �迭 ���
        printArray(arr + left, right - left + 1);
    }
}

int main() {
    // ���� ���� �õ� ����
    srand(time(NULL));

    int arr[SIZE];

    // 0 ~ 99 ������ ���� ����
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // ���� �迭 ���
    printf("Original List\n");
    printArray(arr, SIZE);
    printf("\n");

    // �պ� ���� ����
    printf("Merge Sort\n");
    mergeSort(arr, 0, SIZE - 1);

    return 0;
}