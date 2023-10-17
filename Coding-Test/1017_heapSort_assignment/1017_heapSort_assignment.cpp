#include <stdio.h>

// 배열 요소 교환 함수
void swap(int* a, int* b) {
    int temp = *a; // 임시 변수를 통해 두 변수의 값을 교환
    *a = *b; // a에 b값을 할당
    *b = temp; // b에 임시 변수 값을 할당
}

// 최대 힙 구성 함수
void maxHeap(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left; // 왼쪽 자식 노드를 가장 큰 값으로 설정

    if (right < n && arr[right] > arr[largest])
        largest = right; // 오른쪽 자식 노드를 가장 큰 값으로 설정

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);
    }
}

// 힙 정렬 수행 함수
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // 최대값을 배열 끝과 교환
        maxHeap(arr, i, 0); // 변경된 상태에서 다시 최대 힙을 구성

        // 해당 시점의 힙 상태 출력
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