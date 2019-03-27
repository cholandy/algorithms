#include <stdio.h>
 
typedef struct tagpoint {
    int x;
    int y;
}POINT;
 
POINT p[90];
int size;
int nemo[9][10];
int horizon[9][10];
int vertical[9][10];
int map[9][9];
int flag;
 
void input()
{
    int i, j;
    int idx = 0;
 
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &map[i][j]);
            if (!map[i][j]) {
                p[idx].y = i;
                p[idx].x = j;
                idx++;
            }
            else {
                nemo[3 * (i / 3) + (j / 3)][map[i][j]] = 1;
                horizon[i][map[i][j]] = 1;
                vertical[j][map[i][j]] = 1;
            }
        }
    }
 
    size = idx;
}
 
void print()
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}
 
void process(int idx)
{
    int i;
    int number[10] = { 0, };
 
    if (flag)    return;
    if (idx == size) {
        print();
        flag = 1;
        return;
    }
 
    for (i = 1; i < 10; i++) {
        number[i] = 1;
 
        if (nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i])   number[i] = 0;
        else if (horizon[p[idx].y][i])                    number[i] = 0;
        else if (vertical[p[idx].x][i])                   number[i] = 0;
 
        if (number[i])        number[0]++;
    }
 
    if (!number[0]) return;
    for (i = 1; i < 10; i++) {
        if (number[i]) {
            map[p[idx].y][p[idx].x] = i;
            nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i] = 1;
            horizon[p[idx].y][i] = 1;
            vertical[p[idx].x][i] = 1;

            process(idx + 1);
 
            nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i] = 0;
            vertical[p[idx].x][i] = 0;
            horizon[p[idx].y][i] = 0;
            map[p[idx].y][p[idx].x] = 0;
        }
    }
}
 
int main()
{
    input();
    process(0);
    return 0;
}
