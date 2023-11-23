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

// 셸 정렬 함수
void shellSort(int arr[], int size) {
    int i, j, temp, gap;
    int moveCount = 0, compareCount = 0;

    printf("Shell Sort\n");

    // 셸 정렬의 갭 설정
    for (gap = size / 2; gap > 0; gap /= 2) {
        // 갭에 따른 삽입 정렬 수행
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

    // 결과 출력
    printf("Average Move Count: %d\n", moveCount);
    printf("Average Compare Count: %d\n\n", compareCount);
}

int main() {
    // 난수 생성 시드 설정
    srand(time(NULL));

    int arr[SIZE];

    // 0 ~ 99 사이의 난수 생성
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // 원본 배열 출력
    printf("Original List\n");
    printArray(arr, SIZE);
    printf("\n");

    // 셸 정렬 실행
    shellSort(arr, SIZE);

    return 0;
}