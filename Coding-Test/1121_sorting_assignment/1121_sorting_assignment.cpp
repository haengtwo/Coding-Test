#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// 배열 출력 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 선택 정렬 함수
void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    int moveCount = 0, compareCount = 0;

    printf("Selection Sort\n");

    for (i = 0; i < size - 1; i++) {
        // 현재 인덱스를 최소값으로 가정
        minIndex = i;

        // 현재 인덱스와 이후의 수와 비교하여 최소값의 인덱스 찾기
        for (j = i + 1; j < size; j++) {
            compareCount++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 최소값과 현재 인덱스의 수를 교환
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        moveCount++;
        printArray(arr, size);
    }

    printf("Move Count: %d\n", moveCount);
    printf("Compare Count: %d\n\n", compareCount);
}

// 삽입 정렬 함수
void insertionSort(int arr[], int size) {
    int i, key, j;
    int moveCount = 0, compareCount = 0;

    printf("Insertion Sort\n");

    for (i = 1; i < size; i++) {
        // 현재 수를 key로 설정
        key = arr[i];
        j = i - 1;

        // key보다 큰 수를 오른쪽으로 이동
        while (j >= 0 && arr[j] > key) {
            compareCount++;
            arr[j + 1] = arr[j];
            j = j - 1;
            moveCount++;
        }

        // key를 적절한 위치에 삽입
        arr[j + 1] = key;
        printArray(arr, size);
    }

    printf("Move Count: %d\n", moveCount);
    printf("Compare Count: %d\n\n", compareCount);
}

// 버블 정렬 함수
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    int moveCount = 0, compareCount = 0;

    printf("Bubble Sort\n");

    for (i = 0; i < size - 1; i++) {
        // 한 번의 패스에서 비교하며 교환
        for (j = 0; j < size - i - 1; j++) {
            compareCount++;
            if (arr[j] > arr[j + 1]) {
                // 인접한 수가 크기 순서에 맞지 않으면 교환
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
    // 난수 생성 시드 설정
    srand(time(NULL));

    int arr[SIZE];

    // 0 ~ 99 난수 생성
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // 원본 배열 출력
    printf("Original List\n");
    printArray(arr, SIZE);
    printf("\n");

    // 선택 정렬 실행
    selectionSort(arr, SIZE);

    // 초기 상태로 배열 재설정
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // 삽입 정렬 실행
    insertionSort(arr, SIZE);

    // 초기 상태로 배열 재설정
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // 버블 정렬 실행
    bubbleSort(arr, SIZE);

    return 0;
}