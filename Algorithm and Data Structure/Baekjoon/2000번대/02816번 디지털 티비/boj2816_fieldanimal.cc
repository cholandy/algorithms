#include<stdio.h>
#include<string.h>
int main()
{
    int N;
    scanf("%d", &N);
    int index[2];
    char buf[11];
    for (int i = 0; i < N; ++i)
    {
        scanf("%s", buf);
        if (strcmp(buf, "KBS1") == 0)
            index[0] = i;
        if (strcmp(buf, "KBS2") == 0)
            index[1] = i;
    }
    int add = index[0] > index[1];
    for (int i = 0; i < index[0]; ++i)
        printf("1");
    for (int i = 0; i < index[0]; ++i)
        printf("4");
    for (int i = 0; i < index[1] + add; ++i)
        printf("1");
    for (int i = 0; i < index[1] + add - 1; ++i)
        printf("4");
}
