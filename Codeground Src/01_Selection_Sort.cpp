#include <stdio.h>

#define MAX 1000000

int arr[MAX];
int N;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minidx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minidx] > arr[j])
            {
                minidx = j;
            }
        }
        Swap(&arr[minidx], &arr[i]);
    }
}
int main()
{
    freopen("C:\\Users\\multicampus\\Desktop\\algorithms\\input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}