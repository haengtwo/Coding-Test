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

// ���� ���� �Լ�
void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    int moveCount = 0, compareCount = 0;

    printf("Selection Sort\n");

    for (i = 0; i < size - 1; i++) {
        // ���� �ε����� �ּҰ����� ����
        minIndex = i;

        // ���� �ε����� ������ ���� ���Ͽ� �ּҰ��� �ε��� ã��
        for (j = i + 1; j < size; j++) {
            compareCount++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // �ּҰ��� ���� �ε����� ���� ��ȯ
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        moveCount++;
        printArray(arr, size);
    }

    printf("Move Count: %d\n", moveCount);
    printf("Compare Count: %d\n\n", compareCount);
}

// ���� ���� �Լ�
void insertionSort(int arr[], int size) {
    int i, key, j;
    int moveCount = 0, compareCount = 0;

    printf("Insertion Sort\n");

    for (i = 1; i < size; i++) {
        // ���� ���� key�� ����
        key = arr[i];
        j = i - 1;

        // key���� ū ���� ���������� �̵�
        while (j >= 0 && arr[j] > key) {
            compareCount++;
            arr[j + 1] = arr[j];
            j = j - 1;
            moveCount++;
        }

        // key�� ������ ��ġ�� ����
        arr[j + 1] = key;
        printArray(arr, size);
    }

    printf("Move Count: %d\n", moveCount);
    printf("Compare Count: %d\n\n", compareCount);
}

// ���� ���� �Լ�
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    int moveCount = 0, compareCount = 0;

    printf("Bubble Sort\n");

    for (i = 0; i < size - 1; i++) {
        // �� ���� �н����� ���ϸ� ��ȯ
        for (j = 0; j < size - i - 1; j++) {
            compareCount++;
            if (arr[j] > arr[j + 1]) {
                // ������ ���� ũ�� ������ ���� ������ ��ȯ
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount++;
            }
        }
        printArray(arr, size);
    }

    printf("Move Count: %d\n", moveCount);
    printf("Compare Count: %d\n\n", compareCount);
}

int main() {
    // ���� ���� �õ� ����
    srand(time(NULL));

    int arr[SIZE];

    // 0 ~ 99 ���� ����
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // ���� �迭 ���
    printf("Original List\n");
    printArray(arr, SIZE);
    printf("\n");

    // ���� ���� ����
    selectionSort(arr, SIZE);

    // �ʱ� ���·� �迭 �缳��
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // ���� ���� ����
    insertionSort(arr, SIZE);

    // �ʱ� ���·� �迭 �缳��
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // ���� ���� ����
    bubbleSort(arr, SIZE);

    return 0;
}