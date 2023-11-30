#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �迭���� �� ��Ҹ� ��ȯ�ϴ� �Լ�
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �迭�� �����ϰ� pivot �ε����� ��ȯ�ϴ� �Լ�
int partition(int arr[], int low, int high, int* compCount, int* swapCount) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*compCount)++;
        if (arr[j] < pivot) {
            i++;
            (*swapCount)++;
            swap(&arr[i], &arr[j]);
        }
    }
    (*swapCount)++;
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// �߰� �ܰ踦 ����ϴ� ����Ʈ �˰���
void quickSortIntermediate(int arr[], int low, int high, int* compCount, int* swapCount) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, compCount, swapCount);

        // �߰� �迭 ���
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSortIntermediate(arr, low, pivotIndex - 1, compCount, swapCount);
        quickSortIntermediate(arr, pivotIndex + 1, high, compCount, swapCount);
    }
}

int main() {
    // ���� ������ ���� �õ� ����
    srand(time(NULL));

    int arr[20];
    int compTotal = 0, swapTotal = 0;

    // 20�� �ݺ��ϸ� ��� ���
    for (int i = 0; i < 20; i++) {
        // 20���� ���� ����
        printf("Original List\n");
        for (int j = 0; j < 20; j++) {
            arr[j] = rand() % 100;
            printf("%d ", arr[j]);
        }
        printf("\n\n");

        int compCount = 0, swapCount = 0;

        printf("Quick Sort\n");

        // �߰� ������ ����ϸ� �� ���� ����
        quickSortIntermediate(arr, 0, 19, &compCount, &swapCount);

        // ���� ���ĵ� �迭 ���
        for (int j = 0; j < 20; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        compTotal += compCount;
        swapTotal += swapCount;

        printf("\n");
    }

    // ��� �� �� ��ȯ Ƚ�� ���
    printf("Average Move Count: %.6f\n", (float)swapTotal / 20);
    printf("Average Comp Count: %.6f\n", (float)compTotal / 20);


    return 0;
}
