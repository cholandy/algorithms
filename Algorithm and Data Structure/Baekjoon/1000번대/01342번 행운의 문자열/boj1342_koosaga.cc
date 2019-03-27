#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char str[15];
    scanf("%s",str);
    int l = (int)strlen(str);
    sort(str,str+l);
    int r = 0;
    do{
        int f = 1;
        for (int i=0; i<l-1; i++) {
            if(str[i] == str[i+1]) f = 0;
        }
        r += f;
    }while(next_permutation(str,str+l));
    printf("%d",r);
}