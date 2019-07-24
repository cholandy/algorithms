#include <stdio.h>

void quickSort(int *arr, int left, int right) {
    int pivot, left_temp, right_temp;
    left_temp = left;
    right_temp = right;
    pivot = arr[left];
    while (left < right) {
        while (arr[right] >= pivot && (left < right)) {
            right--;
        }
        if (left != right) {
            arr[left] = arr[right];
        }
        while (arr[left] <= pivot && (left < right)) {
            left++;
        }
        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = left_temp;
    right = right_temp;
    if (left < pivot) quickSort(arr, left, pivot - 1);
    if (right > pivot) quickSort(arr, pivot + 1, right);
}
int N;
int arr[100001];
int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}