#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열에서 두 요소를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 배열을 분할하고 pivot 인덱스를 반환하는 함수
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

// 중간 단계를 출력하는 퀵솔트 알고리즘
void quickSortIntermediate(int arr[], int low, int high, int* compCount, int* swapCount) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, compCount, swapCount);

        // 중간 배열 출력
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSortIntermediate(arr, low, pivotIndex - 1, compCount, swapCount);
        quickSortIntermediate(arr, pivotIndex + 1, high, compCount, swapCount);
    }
}

int main() {
    // 난수 생성을 위한 시드 설정
    srand(time(NULL));

    int arr[20];
    int compTotal = 0, swapTotal = 0;

    // 20번 반복하며 평균 계산
    for (int i = 0; i < 20; i++) {
        // 20개의 난수 생성
        printf("Original List\n");
        for (int j = 0; j < 20; j++) {
            arr[j] = rand() % 100;
            printf("%d ", arr[j]);
        }
        printf("\n\n");

        int compCount = 0, swapCount = 0;

        printf("Quick Sort\n");

        // 중간 과정을 출력하며 퀵 정렬 수행
        quickSortIntermediate(arr, 0, 19, &compCount, &swapCount);

        // 최종 정렬된 배열 출력
        for (int j = 0; j < 20; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        compTotal += compCount;
        swapTotal += swapCount;

        printf("\n");
    }

    // 평균 비교 및 교환 횟수 출력
    printf("Average Move Count: %.6f\n", (float)swapTotal / 20);
    printf("Average Comp Count: %.6f\n", (float)compTotal / 20);


    return 0;
}
