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

// �� ���� �Լ�
void shellSort(int arr[], int size) {
    int i, j, temp, gap;
    int moveCount = 0, compareCount = 0;

    printf("Shell Sort\n");

    // �� ������ �� ����
    for (gap = size / 2; gap > 0; gap /= 2) {
        // ���� ���� ���� ���� ����
        for (i = gap; i < size; i++) {
            temp = arr[i];
            j = i;

            while (j >= gap && arr[j - gap] > temp) {
                compareCount++;
                arr[j] = arr[j - gap];
                j -= gap;
                moveCount++;
            }

            arr[j] = temp;
        }
        printArray(arr, size);
    }

    // ��� ���
    printf("Average Move Count: %d\n", moveCount);
    printf("Average Compare Count: %d\n\n", compareCount);
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

    // �� ���� ����
    shellSort(arr, SIZE);

    return 0;
}