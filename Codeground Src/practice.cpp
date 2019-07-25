#include <stdio.h>
#include <malloc.h>
int pq = 1;
int arr[10]={0,};

int main() 
{
    for (int i=0;i<10;i++) {
        arr[i] = i;
    }
    for (int i=0;i<10;i++) {
        printf("%d ", arr[i]);
    }    
    printf("\n");


    arr[pq]=arr[--pq];


    for (int i=0;i<10;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("%d\n", pq);
    return 0;
}