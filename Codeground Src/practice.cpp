#include <stdio.h>


void something(int** head, int a, int b){

    printf("%p\n", head);
    return;
}


int main()
{
    int a[5]={1,2,3,4,5};
    int b[5]={11,12,13,14,15};
    int c[5]={21,22,23,24,25};

    int* ap[3] = {a,b,c};

    for (int i=0; i<3; i++) {
        for (int j=0; j<5; j++) {
            printf("%5d ", ap[i][j]);    
        }
        printf("\n"); 
    }
    // printf("%p\n%p\n%p\n", a,ap,ap[1]);
    for (int i=0;i<3;i++){
        something(&ap[i],1,2);
    }
    return 0;
}