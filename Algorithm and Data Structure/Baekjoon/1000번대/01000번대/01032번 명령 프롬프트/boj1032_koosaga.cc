#include <cstdio>

char str[51][51];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    for (int i=0; str[0][i]; i++) {
        for (int j=1; j<n; j++) {
            if(str[j][i] != str[0][i]) goto t;
        }
        printf("%c",str[0][i]);
        continue;
        t:;
        printf("?");
    }
}