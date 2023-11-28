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

// 합병 함수
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 왼쪽과 오른쪽 부분 배열을 담을 포인터 선언
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 왼쪽 부분 배열 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // 오른쪽 부분 배열 복사
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 임시 배열을 합병하여 정렬된 결과 생성
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

    // 남은 요소들 복사
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

    // 동적으로 할당한 메모리 해제
    free(L);
    free(R);
}

// 합병 정렬 함수
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 중간 지점 계산
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 합병 수행
        merge(arr, left, mid, right);

        // 부분 배열 출력
        printArray(arr + left, right - left + 1);
    }
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

    // 합병 정렬 실행
    printf("Merge Sort\n");
    mergeSort(arr, 0, SIZE - 1);

    return 0;
}